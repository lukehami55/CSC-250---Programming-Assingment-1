# Program Design
## Structure Chart
![Chart](https://github.com/lukehami55/CSC-250---Programming-Assingment-1/blob/main/Structure%20Chart.png?raw=true)

## Data Storage in Main
``` cpp
int id[SIZE]; //id array
int hits[SIZE]; //hits array
int timesHit[SIZE]; //times hit array
int numItems; //size of the arrays
string input; //team id input
int index; //find index of parallel arrays based on input
```
## Function Design
``` cpp
//read data from txt file into arrays, return length of data
int readData(int id[], int hits[], int timesHit[], int SIZE);

//sort arrays using bubble sort
void sortArrays(int id[], int hits[], int timesHit[], int numItems);

//returns user inputted search ID
int getSearchId(int input);

//binary search based on input and returns index
int binarySearch(int id[], int hits[], int timesHit[], int index);

//print id hits, and times hit based on index
void printResults(int id[], int hits[], int timesHit[], int index);
```
## Time Estimates
|  | Estimated Time    | Actual Time    |
| :---:   | :---: | :---: |
| Program Design | 30   | 45   |
| readData | 5   | 15   |
| sortArrays | 10   | 5   |
| getSearchId | 5   | 5   |
| binarySearch | 15   | TBD   |
| printResults | 5   | TBD   |
| Program Test | 5   | TBD   |
| Total Time | 75   | TBD   |
