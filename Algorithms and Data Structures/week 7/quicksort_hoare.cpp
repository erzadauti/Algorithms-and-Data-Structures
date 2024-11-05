#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace chrono;

vector<int>::iterator partition(vector<int> &vec, vector<int>::iterator begin, 
                                vector<int>::iterator end) {
    auto hoare_pivot = begin + distance(begin, end) / 2; 
    swap(*hoare_pivot, *begin); 

    auto i = begin;
    for (auto j = begin+1; j < end; j++) {
        if (*j <= *begin) {
            i++;
            swap(*i, *j);
        }
    }
    swap(*begin, *i);
    
    return i;
}

void quicksort(vector<int> &vec, vector<int>::iterator begin, 
               vector<int>::iterator end) {
    if (begin < end) {
        auto middle = partition(vec, begin, end);   
        quicksort(vec, begin, middle);
        quicksort(vec, middle+1, end);
    }
}

int main() {
    srand(time(0));
    vector<int> computation_times;

    for (int i = 0; i < 100000; i++) {
        vector<int> vec(1000);
        generate(vec.begin(), vec.end(), rand); 

        auto start = high_resolution_clock::now(); 
        quicksort(vec, vec.begin(), vec.end());
        auto stop = high_resolution_clock::now(); 
        auto duration = duration_cast<microseconds>(stop - start);

        computation_times.push_back(duration.count());
    }

    int total_sum = 0;
    for (auto &elem : computation_times) {
        total_sum += elem;
    }

    cout << "Average time for Hoare Pivot in microseconds: " 
         <<  total_sum/100000.0 << endl;

    return 0;
}