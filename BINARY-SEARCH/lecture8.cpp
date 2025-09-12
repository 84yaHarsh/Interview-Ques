/*SEARCH AN ELEMENT IN ROTATED SORTED ARRAY 
 <---  TIME COMPLEXITY --->
First pivot finding = O(log n)

Then binary search = O(log n)

Total = O(log n) + O(log n) = O(log n)*/

#include <bits/stdc++.h>
using namespace std;

// Standard Binary Search
int binarySearch(vector<int>& arr, int start, int end, int key) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) start = mid + 1;
        else end = mid - 1;
    }
    return -1;
}

// Find Pivot (Index of smallest element)
int findPivot(vector<int>& arr, int n) {
    int start = 0, end = n - 1;
    while (start <= end) {
        if (arr[start] <= arr[end]) return start;

        int mid = start + (end - start) / 2;
        int next = (mid + 1) % n;
        int prev = (mid - 1 + n) % n;

        if (arr[mid] <= arr[prev] && arr[mid] <= arr[next])
            return mid;

        if (arr[start] <= arr[mid]) start = mid + 1;
        else end = mid - 1;
    }
    return 0;
}

// Search in Rotated Sorted Array
int searchInRotatedArray(vector<int>& arr, int n, int key) {
    int pivot = findPivot(arr, n);

    // Search in left half
    int left = binarySearch(arr, 0, pivot - 1, key);
    if (left != -1) return left;

    // Search in right half
    return binarySearch(arr, pivot, n - 1, key);
}

// Main function
int main() {
    vector<int> arr = {11, 12, 15, 18, 2, 5, 6, 8};
    int n = arr.size();

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    int result = searchInRotatedArray(arr, n, key);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found!" << endl;

    return 0;
}
