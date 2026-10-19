#include <iostream>
using namespace std;
int binary_to_decimal(string& bin){
    int n = bin.size();
    int sum = 0;
    for(int i = n-1; i>=0; i--){
        sum += ((bin[i] - 48) * (1 << (n - i - 1)));
    }
    return sum;
}
int main(){
    string bin = "001101";
    cout<<binary_to_decimal(bin)<<"\n";
}