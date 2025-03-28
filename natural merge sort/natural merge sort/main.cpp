#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> findRuns(vector<int>& arr) {
    vector<vector<int>> runs;
    vector<int> currentRun;

    for (int i = 0; i < arr.size(); i++) {
        if (i == 0 || arr[i] >= arr[i - 1]) {
            currentRun.push_back(arr[i]);
        }
        else {
            runs.push_back(currentRun);
            currentRun.clear();
            currentRun.push_back(arr[i]);
        }
    }
    runs.push_back(currentRun);
    return runs;
}

vector<int> naturalMergeSort(vector<int>& arr) {
    while (true) {
        vector<vector<int>> runs = findRuns(arr);

        if (runs.size() == 1) break;

        vector<int> merged;
        for (int i = 0; i + 1 < runs.size(); i += 2) {
            vector<int> temp;
            merge(runs[i].begin(), runs[i].end(), runs[i + 1].begin(), runs[i + 1].end(), back_inserter(temp), greater<>());
            merged.insert(merged.end(), temp.begin(), temp.end());
        }

        if (runs.size() % 2 == 1)
            merged.insert(merged.end(), runs.back().begin(), runs.back().end());

        arr = merged;
    }
    return arr;
}

int main() {
    vector<int> arr = { 2, 5, 8, 3, 6, 7, 4, 9, 1 };
    arr = naturalMergeSort(arr);

    for (int num : arr) cout << num << " ";
    return 0;
}
