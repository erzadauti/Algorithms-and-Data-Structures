#include <iostream>
#include <cstdlib>
#include <chrono>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

void selectionSort(vector<int>& seq, int n);

vector<int> bestCase(int n);
vector<int> averageCase(int n);
vector<int> worstCase(int n);

int interval = 100000;

int main() {
    fstream worstFile("worstCaseData.txt", ios::out);
    fstream averageFile("averageCaseData.txt", ios::out);
    fstream bestFile("bestCaseData.txt", ios::out);
    int iterations = 5;
    int maxSize = 34000;
    int caseStep = 1000;
    srand(time(NULL));
    
    if (worstFile.is_open() && averageFile.is_open() && bestFile.is_open()) {
        vector<int> worstTimes, averageTimes, bestTimes;

        for (int n = 0; n <= maxSize; n += caseStep) {
            chrono::system_clock::time_point start, end;
            chrono::duration<double> period;

            // Initialize times vectors with first element 0
            if (n == 0) {
                worstFile << n << " " << 0 << endl;
                averageFile << n << " " << 0 << endl;
                bestFile << n << " " << 0 << endl;
                worstTimes.push_back(0);
                averageTimes.push_back(0);
                bestTimes.push_back(0);
                continue;
            }

            double worstCaseIterationSum = 0;
            for (int i = 0; i < iterations; i++) {
                vector<int> worstCaseGen = worstCase(n);
                start = chrono::system_clock::now();
                selectionSort(worstCaseGen, (int) worstCaseGen.size());
                end = chrono::system_clock::now();
                period = end - start;
                worstCaseIterationSum += period.count();
            }
            // Output average time for iterations
            worstFile << n << " " 
                      << worstCaseIterationSum / iterations << endl;
            cout << n << " " 
                 << worstCaseIterationSum / iterations << endl;

            // Calculate time for average case
            double averageCaseIterationSum = 0;
            for (int i = 0; i < iterations; i++) {
                vector<int> averageCaseGen = averageCase(n);
                // Calculate time taken for case
                start = chrono::system_clock::now();
                selectionSort(averageCaseGen, (int) averageCaseGen.size());
                end = chrono::system_clock::now();
                period = end - start;
                averageCaseIterationSum += period.count();
            }
            // Output average time for iterations
            averageFile << n << " " 
                        << averageCaseIterationSum / iterations << endl;
            cout << n << " " 
                 << averageCaseIterationSum / iterations << endl;

            // Calculate time for best case
            double bestCaseIterationSum = 0;
            for (int i = 0; i < iterations; i++) {
                vector<int> bestCaseGen = bestCase(n);
                start = chrono::system_clock::now();
                selectionSort(bestCaseGen, (int) bestCaseGen.size());
                end = chrono::system_clock::now();
                period = end - start;
                bestCaseIterationSum += period.count();
            }
            // Output average time for iterations
            bestFile << n << " " 
                     << bestCaseIterationSum / iterations << endl;
            cout << n << " "
                 << bestCaseIterationSum / iterations << endl;
        }
    }

    worstFile.close();
    averageFile.close();
    bestFile.close();

    return 0;
}

void selectionSort(vector<int>& seq, int n) {
    for (int i = 0; i < n - 1; i++) {
        int temp, min = i;
        for (int j = i + 1; j < n; j++)
            if (seq[j] < seq[min])
                min = j;
        if (min != i) {
            temp = seq[min];
            seq[min] = seq[i];
            seq[i] = temp;
        }
    }
}

vector<int> bestCase(int n) {
    vector<int> best;
    for (int i = 0; i < n; i++)
        best.push_back(rand() % interval);
    sort(best.begin(), best.end());
    return best;
}

vector<int> averageCase(int n) {
    vector<int> average;
    for (int i = 0; i < n; i++)
        average.push_back(rand() % interval);
    return average;
}

vector<int> worstCase(int n) {
    int firstIndex, swappingNumber = 0;
    vector<int> sample;
    vector<int> indices;
    vector<int> worst(n);

    for (int i = 0; i < n; i++)
        indices.push_back(i);

    for (int i = 0; i < n; i++)
        sample.push_back(rand() % interval);
    sort(sample.begin(), sample.end());

    firstIndex = rand() % n;
    vector<int>::const_iterator it;
    for (it = indices.begin(); it != indices.end(); it++)
        if (*it == firstIndex)
            break;

    indices.erase(it);

    for (int i = 0; i < n; i++) {
        if (i != (n - 1)) {
            int swapIndex = indices[rand() % ((int) indices.size())];

            for (it = indices.begin(); it != indices.end(); it++)
                if (*it == swapIndex)
                    break;
            indices.erase(it);

            if (i == 0)
                worst[swapIndex] = sample[firstIndex];
            else
                worst[swapIndex] = swappingNumber;
            swappingNumber = sample[swapIndex];
        } else 
            worst[firstIndex] = swappingNumber;
    }
    return worst;    
}