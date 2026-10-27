#include <iostream>
using namespace std;
int countSet(int n){
    int count = 0;
    while(n){
        n = n & n-1;
        count ++;
    }
    return count;
}
int main(){
    int n = 100;
    cout<<__builtin_popcount(n)<<"\n";
    cout<<countSet(n)<<"\n";
}