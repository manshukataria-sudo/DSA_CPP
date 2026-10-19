#include <iostream>
using namespace std;
// calc no. less than or equal to n in powers of 2
// again using the Brian Kernigle's algorithm
int pow_2(int n){
    int prev = 0;
    while(n){
        prev = n;
        n = n & (n-1);
    }
    return prev;
}

// using the other method, shifting bits and taking OR | to make ans
int pow_2_2(int n){
    int i = 1; 
    while(i <= 16){
        n = n | (n >> i);
        i = 1 << i;
    }
    return (n + 1) >> 2;
}
int main(){
    int n = 100;
    cout<<pow_2(n)<<"\n";
}