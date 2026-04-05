// COMSC-210 | Lab 25 | Christine Susic

#include <iostream>
#include <iomanip>
#include <chrono>
#include <algorithm>
#include <fstream>
#include <vector>
#include <list>
#include <set>
using namespace std;
using namespace std:: chrono;

//size of array from file and column widths
const int SZ = 20000, W1 = 12, W2 = 9, W3 = 7, W4 = 6;  

int main() {
    //output
    cout << setw(W1) << left << "Operation";
    cout << setw(W2) << "Vector";
    cout << setw(W3) << "List";
    cout << setw(W4) << "Set" << endl;
    
    //vector of codes
    vector<string> vectorCodes;
    //list of codes
    list<string> listCodes;
    //set of codes
    set<string> setCodes;
    
    //READ DATA
    cout << setw(W1) << "Read" << endl;
    //read names file and store it in a vector, list, and set
    ifstream fin("codes.txt");
    string codes;
    int count = 0;
    while (getline(fin, codes)) {
        //read data into vector
        vectorCodes.push_back(codes);
        //read data into list
        listCodes.push_back(codes);
        //read data into set
        setCodes.insert(codes);
        count++;
    }
    fin.close();
 
    //SORT DATA
    cout << setw(W1) << "Sort";
    
    //Vector Sort
    //start timing
    auto start = high_resolution_clock::now();
    //sort data into vector
    sort(vectorCodes.begin(), vectorCodes.end());
    //end timing
    auto end = high_resolution_clock::now();
     //calculate duration
    auto duration = duration_cast<nanoseconds>(end - start);
    //output the duration in nanoseconds
    cout << duration.count();
    
    //List Sort
    //sort data into list
    listCodes.sort();
    //sort data into set
    int setSorted = -1;
    cout << endl;
    
    //INSERT DATA
    cout << setw(W1) << "Insert";
    //insert data into vector
    vectorCodes.insert(vectorCodes.begin() + vectorCodes.size() / 2, "TESTCODE");
    //insert data into list
    auto it = listCodes.begin();
    advance(it, listCodes.size() / 2);
    listCodes.insert(it, "TESTCODE");
    //insert data into set
    setCodes.insert("TESTCODE");
    cout << endl;
    
    //DELETE DATA
    cout << setw(W1) << "Delete";
    //delete data from vector
    vectorCodes.erase(vectorCodes.begin() + vectorCodes.size() / 2);
    //delete data from list
    advance(it, listCodes.size() / 2);
    listCodes.erase(it);
    //delete data from set
    auto it1 = setCodes.begin();
    advance(it1, setCodes.size() / 2);
    setCodes.erase(it1);
    cout << endl;

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/