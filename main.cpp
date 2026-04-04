// COMSC-210 | Lab 25 | Christine Susic

#include <iostream>
#include <chrono>
#include <list>
#include <set>
using namespace std;

const int SZ = 20000;  //size of array from file

int main() {
    //output
    cout << "Operation   Vector   List   Set";
    
    //READ DATA
    cout << "Read";
    // first read names file and store in an array
    ifstream fin("codes.txt");
    string codes[SZ];
    int i = 0;
    while (fin >> codes[i++]);
    fin.close();
    
     //read data into vector

    //read data into list
    //list of codes
    list<string> codes;
    
    //read data into set
    //set of codes
    set<string> codes;
    
    
    //SORT DATA
    cout << "Sort";
    //sort data into vector
    
    //sort data into list
    
    //sort data into set
    
    
    //INSERT DATA
    cout << "Insert";
    //insert data into vector
    
    //insert data into list
    
    //insert data into set
    
    
    //DELETE DATA
    cout << "Delete";
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