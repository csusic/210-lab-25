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
const int SZ = 20000, W1 = 11, W2 = 9, W3 = 10, W4 = 8;  

int main() {
    //output
    cout << setw(W1) << right << "Operation";
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
    cout << setw(W1) << "Read";
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
    cout << endl;
 
    //SORT DATA
    cout << setw(W1) << "Sort";
    
    //Sort Vector
    //start timing
    auto startVectorSort = high_resolution_clock::now();
    //sort data into vector
    sort(vectorCodes.begin(), vectorCodes.end());
    //end timing
    auto endVectorSort = high_resolution_clock::now();
     //calculate duration
    auto durationVectorSort = duration_cast<nanoseconds>(endVectorSort - startVectorSort);
    //output the duration in nanoseconds
    cout << setw(W2) << durationVectorSort.count();
    
    //List Sort
    //start timing
    auto startListSort = high_resolution_clock::now();
    //sort data into list
    listCodes.sort();
    //end timing
    auto endListSort = high_resolution_clock::now();
     //calculate duration
    auto durationListSort = duration_cast<nanoseconds>(endListSort - startListSort);
    //output the duration in nanoseconds
    cout << setw(W3) << durationListSort.count();
    
    //Set Sort
    //start timing
    auto startSetSort = high_resolution_clock::now();
    //sort data into set
    int setSorted = -1;
    //end timing
    auto endSetSort = high_resolution_clock::now();
     //calculate duration
    auto durationSetSort = duration_cast<nanoseconds>(endSetSort - startSetSort);
    //output the duration in nanoseconds
    cout << setw(W4) << durationSetSort.count();
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