// COMSC-210 | Lab 25 | Christine Susic

#include <iostream>
#include <iomanip>
#include <chrono>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <list>
#include <set>
using namespace std;
using namespace std:: chrono;

//column width
const int W1 = 10; 

int main() {
    //output headers
    cout << setw(W1) << right << "Operation";
    cout << setw(W1) << "Vector";
    cout << setw(W1) << "List";
    cout << setw(W1) << "Set" << endl;
    
    //vector of codes
    vector<string> vectorCodes;
    //list of codes
    list<string> listCodes;
    //set of codes
    set<string> setCodes;
    
    /* READ DATA */
    cout << setw(W1) << "Read"; //header
    //read codes file into vector, list, and set
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
    cout << setw(W1) << durationReadVector.count();
    
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
    cout << setw(W1) << durationReadList.count();
    
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
    auto durationReadSet = duration_cast<nanoseconds>(endReadSet - startReadSet);
    //output the duration in nanoseconds
    cout << setw(W1) << durationReadSet.count();
    fin.close(); //close file
    cout << endl;
 
    /* SORT DATA */
    cout << setw(W1) << "Sort"; //header
    
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
    cout << setw(W1) << durationSortVector.count();
    
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
    cout << setw(W1) << durationSortList.count();
    
    //Sort Set
    //set already sorted, set value to -1
    int sortedSet = -1;
    cout << setw(W1) << sortedSet;
    cout << endl;
    
    /* INSERT DATA */ //middle element
    cout << setw(W1) << "Insert"; //header
    
    //Insert Vector (middle element)
    //start timing
    auto startInsertVector = high_resolution_clock::now();
    //insert data into vector
    vectorCodes.insert(vectorCodes.begin() + vectorCodes.size() / 2, "TESTCODE");
    //end timing
    auto endInsertVector = high_resolution_clock::now();
     //calculate duration
    auto durationInsertVector = duration_cast<nanoseconds>(endInsertVector - startInsertVector);
    //output the duration in nanoseconds
    cout << setw(W1) << durationInsertVector.count();
    
    //Insert List (middle element)
    //start timing
    auto startInsertList = high_resolution_clock::now();
    //insert data into list
    auto itIL = listCodes.begin();
    advance(itIL, listCodes.size() / 2);
    listCodes.insert(itIL, "TESTCODE");
    //end timing
    auto endInsertList = high_resolution_clock::now();
     //calculate duration
    auto durationInsertList = duration_cast<nanoseconds>(endInsertList - startInsertList);
    //output the duration in nanoseconds
    cout << setw(W1) << durationInsertList.count();
    
    //Insert Set (middle element)
    //start timing
    auto startInsertSet = high_resolution_clock::now();
    //insert data into set
    setCodes.insert("TESTCODE");
    //end timing
    auto endInsertSet = high_resolution_clock::now();
     //calculate duration
    auto durationInsertSet = duration_cast<nanoseconds>(endInsertSet - startInsertSet);
    //output the duration in nanoseconds
    cout << setw(W1) << durationInsertSet.count();
    cout << endl;

    /* DELETE DATA */ //The middle element
    cout << setw(W1) << "Delete"; //header
    
    //Delete Vector (middle element)
    //start timing
    auto startDeleteVector = high_resolution_clock::now();
    //delete data from vector
    vectorCodes.erase(vectorCodes.begin() + vectorCodes.size() / 2);
    //end timing
    auto endDeleteVector = high_resolution_clock::now();
     //calculate duration
    auto durationDeleteVector = duration_cast<nanoseconds>(endDeleteVector - startDeleteVector);
    //output the duration in nanoseconds
    cout << setw(W1) << durationDeleteVector.count();
    
    //Delete List (middle element)
    //start timing
    auto startDeleteList = high_resolution_clock::now();
    //delete data from list
    auto itDL = listCodes.begin();
    advance(itDL, listCodes.size() / 2);
    listCodes.erase(itDL);
    //end timing
    auto endDeleteList = high_resolution_clock::now();
     //calculate duration
    auto durationDeleteList = duration_cast<nanoseconds>(endDeleteList - startDeleteList);
    //output the duration in nanoseconds
    cout << setw(W1) << durationDeleteList.count();
    
    //Delete Set (middle element)
    //start timing
    auto startDeleteSet = high_resolution_clock::now();
    //delete data from set
    auto itDS = setCodes.begin();
    advance(itDS, setCodes.size() / 2);
    setCodes.erase(itDS);
    //end timing
    auto endDeleteSet = high_resolution_clock::now();
     //calculate duration
    auto durationDeleteSet = duration_cast<nanoseconds>(endDeleteSet - startDeleteSet);
    //output the duration in nanoseconds
    cout << setw(W1) << durationDeleteSet.count();

    return 0;
}