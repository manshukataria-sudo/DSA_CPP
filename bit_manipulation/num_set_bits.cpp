#include <iostream>
#include <climits>
using namespace std;
// Brian Kernigle's Algorithm
int count_set_bits(int n){
    int count = 0;
    while(n){
        n = n & (n-1);
        count++;
    }
    return count;
}
int main(){
    int n = INT_MAX;
    // returns the no. of set bits, i.e number of 1's present in binary representation
    // cout<<__builtin_popcount(n)<<"\n";
    cout<<count_set_bits(n)<<"\n";
}