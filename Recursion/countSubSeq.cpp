#include <iostream>
#include <vector>
using namespace std;

int count(vector<int> &nums, vector<int>&ds, int target, int i, int sum){
    if( i >= nums.size()){
        if(sum == target){
            return 1;
        }
        return 0;
    }

    ds.push_back(nums[i]);
    int sub1 = count(nums, ds, target, i+1, sum+nums[i]);

    ds.pop_back();
    int sub2 = count(nums, ds, target, i+1, sum);

    return sub1 + sub2;
}

int main(){
    vector<int> nums = {1,2,3,4,5};

    int target = 8;
    vector<int> ds;
    cout << count(nums, ds, target, 0, 0);
}