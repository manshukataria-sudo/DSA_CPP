#include <iostream>
#include <climits>
using namespace std;
// int f(int n){
//     int prev;
//     while(n){
//         prev = n;
//         n = n & n-1;
//     }
//     return prev;
// }
int f(int n){
    int i = 1;
    while(i <= 16){
        n = n | (n >> i);
        i = i << 1;
    }

    return (n + 1) >> 1;
}
int main(){
    int n = 24;
    cout<<f(n)<<"\n";
}