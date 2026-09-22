#include <iostream>
#include <vector>

using namespace std;
// void reverse(vector<int>& arr, int i, int j) {
//     if (i > j || i == j) {
//         return;
//     }
//     swap(arr[i], arr[j]);
//     reverse(arr, i + 1, j - 1);
// }

void reverse(vector<int>& ans, int i) { 
    if(i >= ans.size()/2){
        return;
    }
    swap(ans[i], ans[ans.size() - 1 - i]); 
    reverse(ans, i+1);
}
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    // reverse(arr, 0, arr.size() - 1);
    reverse(arr, 0);
    for (int ele : arr) {
        cout << ele << " ";
    }

    cout << '\n';
    return 0;
}