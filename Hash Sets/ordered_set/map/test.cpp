#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <vector>
using namespace std;
int main(){

    cout<<(char)5;
    
    set<int> s;
    s.insert(1);
    s.insert(1);
    s.insert(2);
    s.insert(2);
    for(int ele : s){
        cout<<(ele);
    }
    set<vector<int>> sv;
    sv.insert({1,2,3,4});
    sv.insert({1,2,3,4});

    for (auto v : sv){
        for (int ele : v){
            cout<< ele<<" ";
        }
        cout<<"\n";
    }

    int i = 7;
    cout<<(char)i;
}