#include <iostream>
#include <vector>
using namespace std;
// void anySub(vector<int>& nums, int target, int sum ,vector<int>&ds, int i, bool& flag){
//     if(i > nums.size()){
//         return;
//     }
//     if(sum == target){
//         flag = true;
//         for(int ele : ds){
//             cout<<ele<<" ";
//         }
//         return;
//     }
//     if(!flag){
//         ds.push_back(nums[i]);
//         anySub(nums, target, sum + nums[i], ds, i + 1, flag);
//     }
//     if(!flag){
//         ds.pop_back();
//         anySub(nums, target, sum, ds, i + 1, flag);
//     }
// }

bool subSeq(vector<int>& nums, int target, int sum, vector<int> &ds, int i){
    if(i >= nums.size()){
        if(sum == target){
            for(int ele : ds){
                cout<<ele<<" ";
            }
            return true;
        }
        return false;
    }

    ds.push_back(nums[i]);

    if(subSeq(nums, target, sum + nums[i], ds, i+1)){
        return true;
    }

    ds.pop_back();
    if(subSeq(nums, target, sum, ds, i+1)){
        return true;
    }
    return false;
}
int main(){
    vector<int> nums = {1,2,3,4,5};

    int target = 10;
    vector<int> ds;

    subSeq(nums, target, 0, ds, 0);

    cout<<"\n";
}