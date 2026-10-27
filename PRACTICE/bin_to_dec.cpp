#include <iostream>
using namespace std;
int dec(string& bin){
    int n = bin.size();
    int sum = 0;
    for(int i = n-1; i >= 0; i--){
        if(bin[i] == '1'){
            sum += (1 << (n-i-1));
        }
    }
    return sum;
}
int main(){
    // binary of INT_MIN in 2's complement as stored in memory of 32 bits
    string bin = "10000000000000000000000000000000";
    cout<<dec(bin)<<"\n";
}