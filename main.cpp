// COMSC-210 | Lab 25 | Christine Susic

#include <iostream>
#include <chrono>

#include <vector>
#include <list>
#include <set>
using namespace std;

const int SZ = 20000;  //size of array from file

int main() {
    //output
    cout << "Operation   Vector   List   Set";
    
    //vector of codes
    vector<string> vectorCodes;
    //list of codes
    list<string> listCodes;
    //set of codes
    set<string> setCodes;
    
    //READ DATA
    cout << "Read";
    //read names file and store it in a vector, list, and set
    ifstream fin("codes.txt");
    string codes;
    int count = 0;
    while (getline(fin, codes)) {
        //read data into vector
        vectorCodes.push_back(codes);
        //read data into list
        //listCodes.push_back(codes);
        //read data into set
        //setCodes.insert(codes);
        count++;
    }
    fin.close();
 
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