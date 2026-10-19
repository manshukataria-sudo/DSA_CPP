#include <iostream>
#include <algorithm>
using namespace std;
string decimal_to_binary(int decimal){
    string ans = "";
    while(decimal > 0){
        if(decimal % 2 == 0){
            ans += '0';
        } else {
            ans += '1';
        }
        decimal = decimal >> 1;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main(){
    cout<< decimal_to_binary(12) <<"\n";
}