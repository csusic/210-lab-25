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

    //Read Vector
    //start timing
    auto startReadVector = high_resolution_clock::now();
    //read data into vector
    while (getline(fin, codes)) {
        vectorCodes.push_back(codes);
        count++;
    }
    //end timing
    auto endReadVector = high_resolution_clock::now();
     //calculate duration
    auto durationReadVector = duration_cast<nanoseconds>(endReadVector - startReadVector);
    //output the duration in nanoseconds
    cout << setw(W2) << durationReadVector.count();
    
    //Read List
    fin.clear(); //clears error
    fin.seekg(0, ios::beg); //moves pointer to beg. of file
    //start timing
    auto startReadList = high_resolution_clock::now();
    //read data into list
    while (getline(fin, codes)) {
        listCodes.push_back(codes);
        count++;
    }
    //end timing
    auto endReadList = high_resolution_clock::now();
     //calculate duration
    auto durationReadList = duration_cast<nanoseconds>(endReadList - startReadList);
    //output the duration in nanoseconds
    cout << setw(W2) << durationReadList.count();
    
    //Read Set
    fin.clear(); //clears error
    fin.seekg(0, ios::beg); //moves pointer to beg. of file
    //start timing
    auto startReadSet = high_resolution_clock::now();
    //read data into set
    while (getline(fin, codes)) {
        setCodes.insert(codes);
        count++;
    }
    //end timing
    auto endReadSet = high_resolution_clock::now();
     //calculate duration
    auto durationVectorSort = duration_cast<nanoseconds>(endVectorSort - startVectorSort);
    //output the duration in nanoseconds
    cout << setw(W2) << durationVectorSort.count();
    fin.close(); //close file
    cout << endl;
 
    //SORT DATA
    cout << setw(W1) << "Sort";
    
    //Sort Vector
    //start timing
    auto startSortVector = high_resolution_clock::now();
    //sort data into vector
    sort(vectorCodes.begin(), vectorCodes.end());
    //end timing
    auto endSortVector = high_resolution_clock::now();
     //calculate duration
    auto durationSortVector = duration_cast<nanoseconds>(endSortVector - startSortVector);
    //output the duration in nanoseconds
    cout << setw(W2) << durationSortVector.count();
    
    //Sort List
    //start timing
    auto startSortList = high_resolution_clock::now();
    //sort data into list
    listCodes.sort();
    //end timing
    auto endSortList = high_resolution_clock::now();
     //calculate duration
    auto durationSortList = duration_cast<nanoseconds>(endSortList - startSortList);
    //output the duration in nanoseconds
    cout << setw(W3) << durationSortList.count();
    
    //Sort Set
    //start timing
    auto startSortSet = high_resolution_clock::now();
    //sort data into set
    int sortedSet = -1;
    //end timing
    auto endSortSet = high_resolution_clock::now();
     //calculate duration
    auto durationSortSet = duration_cast<nanoseconds>(endSortSet - startSortSet);
    //output the duration in nanoseconds
    cout << setw(W4) << durationSortSet.count();
    cout << endl;
    
    //INSERT DATA
    cout << setw(W1) << "Insert";
    
    //Insert Vector
    //start timing
    auto startInsertVector = high_resolution_clock::now();
    //insert data into vector
    vectorCodes.insert(vectorCodes.begin() + vectorCodes.size() / 2, "TESTCODE");
    //end timing
    auto endInsertVector = high_resolution_clock::now();
     //calculate duration
    auto durationInsertVector = duration_cast<nanoseconds>(endInsertVector - startInsertVector);
    //output the duration in nanoseconds
    cout << setw(W2) << durationInsertVector.count();
    
    //Insert List
    //start timing
    auto startInsertList = high_resolution_clock::now();
    //insert data into list
    auto it = listCodes.begin();
    advance(it, listCodes.size() / 2);
    listCodes.insert(it, "TESTCODE");
    //end timing
    auto endInsertList = high_resolution_clock::now();
     //calculate duration
    auto durationInsertList = duration_cast<nanoseconds>(endInsertList - startInsertList);
    //output the duration in nanoseconds
    cout << setw(W3) << durationInsertList.count();
    
    //Insert Set
    //start timing
    auto startInsertSet = high_resolution_clock::now();
    //insert data into set
    setCodes.insert("TESTCODE");
    //end timing
    auto endInsertSet = high_resolution_clock::now();
     //calculate duration
    auto durationInsertSet = duration_cast<nanoseconds>(endInsertSet - startInsertSet);
    //output the duration in nanoseconds
    cout << setw(W4) << durationInsertSet.count();
    cout << endl;

    //DELETE DATA
    cout << "Delete";
    
    //Delete Vector
    //start timing
    auto startDeleteVector = high_resolution_clock::now();
    //delete data from vector
    vectorCodes.erase(vectorCodes.begin() + vectorCodes.size() / 2);
    //end timing
    auto endDeleteVector = high_resolution_clock::now();
     //calculate duration
    auto durationDeleteVector = duration_cast<nanoseconds>(endDeleteVector - startDeleteVector);
    //output the duration in nanoseconds
    cout << setw(W4) << durationDeleteVector.count();
    
    //Delete List
    //delete data from list
    advance(it, listCodes.size() / 2);
    listCodes.erase(it);
    
    //Delete Set
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