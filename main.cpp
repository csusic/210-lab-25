// COMSC-210 | Lab 25 | Christine Susic

#include <iostream>
#include <chrono>
#include <algorithm>
#include <fstream>
#include <vector>
#include <list>
#include <set>
using namespace std;

const int SZ = 20000;  //size of array from file

int main() {
    //output
    cout << "Operation   Vector   List   Set" << endl;
    
    //vector of codes
    vector<string> vectorCodes;
    //list of codes
    list<string> listCodes;
    //set of codes
    set<string> setCodes;
    
    //READ DATA
    cout << "Read" << endl;
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
    cout << "Sort" << endl;
    //sort data into vector
    sort(vectorCodes.begin(), vectorCodes.end());
    //sort data into list
    listCodes.sort();
    //sort data into set
    setCodes.clear();
    //setCodes.insert(-1);
    
    //INSERT DATA
    cout << "Insert" << endl;
    //insert data into vector
    vectorCodes.insert(vectorCodes.begin() + vectorCodes.size() / 2, "TESTCODE");
    //insert data into list
    auto it = listCodes.begin();
    advance(it, listCodes.size() / 2);
    listCodes.insert(it, "TESTCODE");
    //insert data into set
    setCodes.insert("TESTCODE");
    
    //DELETE DATA
    cout << "Delete" << endl;
    //delete data from vector
    
    //delete data from list
    
    //delete data from set
    

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/