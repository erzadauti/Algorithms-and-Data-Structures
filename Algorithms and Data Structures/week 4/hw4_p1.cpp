#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <chrono> 

using namespace std;
using namespace chrono;


void insertionSort(vector<int> vec, vector<int>::iterator begin, 
                   vector<int>::iterator end) {

    for (auto j = begin+1; j < end; j++) {
        int key = *j;

        int beginIND = distance(vec.begin(), begin)-1; 
        int jIND = distance(vec.begin(), j);   
        int i = jIND - 1;

        while ((i > beginIND) && (vec[i] > key)) {
            vec[i+1] = vec[i];
            i--;
        }
        vec[i+1] = key;
    } 
}

void merge(vector<int> vec, vector<int>::iterator begin, 
           vector<int>::iterator middle, vector<int>::iterator end) {

    vector<int> left;
    left.assign(begin, middle); 
    left.push_back(numeric_limits<int>::max()); 

    vector<int> right;
    right.assign(middle, end);  
    right.push_back(numeric_limits<int>::max()); 
    
    int leftIND = 0, rightIND = 0;
    for (auto it = begin; it < end; it++) {
        if (left[leftIND] <= right[rightIND]) {
            *it = left[leftIND];
            leftIND++;
        }
        else {
            *it = right[rightIND];
            rightIND++;
        }
    }
}

void mergeInsertionSort(const vector<int> &vec, vector<int>::iterator begin, 
               vector<int>::iterator end, int k) {

    int size = distance(begin, end); 
    if (size <= k) {    
        insertionSort(vec, begin, end);
    }
    else {
        auto middle = begin + (end - begin) / 2;    
        mergeInsertionSort(vec, begin, middle, k);  
        mergeInsertionSort(vec, middle, end, k);    
        merge(vec, begin, middle, end);             
    }
}

vector<int> bestCase(int size) {
    vector<int> vec;

    int elem = rand() % 50;   
    vec.push_back(elem);        

    for (int i = 1; i < size; i++) {    
        int increment = 1 + rand() % 10;   
        elem += increment;      
        vec.push_back(elem);    
    }

    return vec;
}

vector<int> worstCase(int size) {
    vector<int> vec;

    int elem = rand() % 50;    
    vec.push_back(elem);        

    for (int i = 1; i < size; i++) {    
        int increment = 1 + rand() % 10;    
        elem += increment;      
        vec.push_back(elem);   
    }

    reverse(vec.begin(), vec.end());    

    return vec;
}

vector<int> averageCase(int size) {
    vector<int> vec;

    for (int i = 0; i < size; i++) {
        int elem = rand() % 50;     
        vec.push_back(elem);        
    }

    return vec;
}

int main () {
    //vectors that will hold compuation times for the different k-values
    vector<int> bestCaseTimes;
    vector<int> worstCaseTimes;
    vector<int> averageCaseTimes;

    int kValue = 100;  
    for (int i = 2; i < kValue; i++) {  
        vector<int> vec = bestCase(100);

        //compute the time of the algorithm in microseconds
        auto start = high_resolution_clock::now(); 
        mergeInsertionSort(vec, vec.begin(), vec.end(), i);
        auto stop = high_resolution_clock::now(); 
        auto duration = duration_cast<microseconds>(stop - start);

        bestCaseTimes.push_back(duration.count());  
    }

    for (int i = 2; i < kValue; i++) {  
        vector<int> vec = worstCase(100);

        //compute the time of the algorithm in microseconds
        auto start = high_resolution_clock::now(); 
        mergeInsertionSort(vec, vec.begin(), vec.end(), i);
        auto stop = high_resolution_clock::now(); 
        auto duration = duration_cast<microseconds>(stop - start);

        worstCaseTimes.push_back(duration.count()); 
    }

    for (int i = 2; i < kValue; i++) { 
        vector<int> vec = averageCase(100);

        auto start = high_resolution_clock::now(); 
        mergeInsertionSort(vec, vec.begin(), vec.end(), i);
        auto stop = high_resolution_clock::now(); 
        auto duration = duration_cast<microseconds>(stop - start);

        averageCaseTimes.push_back(duration.count());  
    }

    cout << "Times for Best Case: ";
    for (auto elem : bestCaseTimes) {
        cout << elem << ", ";
    }
    cout << endl << endl;

    cout << "Times for Worst Case: ";
    for (auto elem : worstCaseTimes) {
        cout << elem << ", ";
    }
    cout << endl << endl;

    cout << "Times for Average Case: ";
    for (auto elem : averageCaseTimes) {
        cout << elem << ", ";
    }
    cout << endl << endl;

    return 0;
}