//Luke Hamilton
//1/24/2023
//CSC 250, S03

//Snowball Fight

//Program to display snowball fight information from a text file based on user input

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int SIZE = 50; //up to 50

//read data from txt file into arrays, return length of data
int readData(int id[], int hits[], int timesHit[], int SIZE);

//sort arrays using bubble sort
void sortArrays(int id[], int hits[], int timesHit[], int numItems);

//returns user inputted search ID
int getSearchId(int input);

//binary search based on input and returns index
int binarySearch(int id[], int hits[], int timesHit[], int input, int numItems);

//print id hits, and times hit based on index
void printResults(int id[], int hits[], int timesHit[], int index);

int main(){
    // variable declarations
    int id[SIZE], hits[SIZE], timesHit[SIZE], numItems, input, index;

    numItems = readData(id, hits, timesHit, SIZE);
    sortArrays(id, hits, timesHit, numItems);

    //init input reading, ensure no -1
    cout << "Enter team ID (enter -1 to quit): ";
    input = getSearchId(input);

    //while loop for user controlled menu program
    while (input != -1){
        index = binarySearch(id, hits, timesHit, input, numItems);
        printResults(id, hits, timesHit, index);
        cout << "Enter team ID (enter -1 to quit): ";
        input = getSearchId(input);
    }
    return 0;
}

//read data from txt file into arrays, return length of data
int readData(int id[SIZE], int hits[SIZE], int timesHit[SIZE], int SIZE){
    ifstream inFile;
    inFile.open("snowball.txt");
    if(!inFile){
        cout << "Error opening file";
        exit(102);
    }
    int i = 0;
    while (i < SIZE && inFile >> id[i] >> hits[i] >> timesHit[i]){
        i++;
    }
    return i;
}

//sort arrays using bubble sort
void sortArrays(int id[SIZE], int hits[SIZE], int timesHit[SIZE], int numItems){
    int tempId, tempHits, tempTimesHit;
    bool swap;
    do {
        swap = false;
        for (int i=0; i<numItems-1; i++){
            if (id[i] > id[i+1]){
                tempId = id[i];
                id[i] = id[i+1];
                id[i+1] = tempId;

                tempHits = hits[i];
                hits[i] = hits[i+1];
                hits[i+1] = tempHits;

                tempTimesHit = timesHit[i];
                timesHit[i] = timesHit[i+1];
                timesHit[i+1] = tempTimesHit;
                swap = true;
            }
        }
    } while (swap == true);
    return;
}

//returns user inputted search ID
int getSearchId(int input){
    cin >> input;
    return input;
}

//binary search based on input and returns index
int binarySearch(int id[], int hits[], int timesHit[], int input, int numItems){
    int first = 0;
    int last = numItems - 1;
    int index = -1;
    int middle;
    bool found = false;
    while (!found && first <= last)
    {
        middle = (first + last) / 2; // Calculate mid point
        if (id[middle] == input) // If value is found at mid
        {
            found = true;
            index = middle;
        }
        else if (id[middle] > input) // If value is in lower half
            last = middle - 1;
        else
            first = middle + 1; // If value is in upper half
    }
    return index;
}

//print id hits, and times hit based on index
void printResults(int id[], int hits[], int timesHit[], int index){
    //conditional formatting based on hit:timesHit ratio
    if (hits[index] > timesHit[index])
        cout << "Team ID " << id[index] << " Congratulations:" << endl;
    else
        cout << "Team ID " << id[index] << ":" << endl;
    cout << left << setw(15) << "Hits: " << right << setw(12) << hits[index] << endl;
    cout << left << setw(15) << "Times Hit: " << right << setw(12) << timesHit[index] << endl;
}
