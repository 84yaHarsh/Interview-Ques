/*FIND FIRST AND LAST OCUURANCE OF AN ELEMENT IN AN SORTED ARRAY
EX-> [2,4,10,10,10,18,20] 
T.C->O(logN) S.C->O(1)*/
#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& v, int n, int key, bool findFirst) {
    int start = 0, end = n - 1;
    int ans = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (v[mid] == key) {
            ans = mid;
            if (findFirst) 
                end = mid - 1;  // keep searching left
            else 
                start = mid + 1; // keep searching right
        }
        else if (v[mid] > key) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return ans;
}

vector<int> occurrence(vector<int>& v, int n, int key) {
    int first = binarySearch(v, n, key, true);
    int last = binarySearch(v, n, key, false);
    return {first, last};
}

int main() {
    vector<int> v = {2, 4, 10, 10, 10, 18, 20};
    int key = 10;
    int n = v.size();

    vector<int> ans = occurrence(v, n, key);
    cout << "First occurrence: " << ans[0] << "\n";
    cout << "Last occurrence: " << ans[1] << "\n";
    return 0;
}

