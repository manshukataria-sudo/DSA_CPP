#include <iostream>
#include <climits>
using namespace std;
int main(){
    int a = 10;
    cout<< 10 << 1 << "\n";
    cout<< ~a<<"\n";
    cout<< (a ^ a) <<"\n";
    cout<< (a | a)<< "\n";
    cout<< -10 <<"\n";
    cout<< -a << "\n";
    cout<< (7<<3) <<"\n"; 
    cout<< __builtin_popcount(INT_MAX)<<"\n";
    cout<< __builtin_popcount(INT_MIN)<<"\n";
    cout<< __builtin_popcount(100)<<"\n";
}