#include <iostream>
using namespace std;
string bin(int dec){
    string ans = "";
    while(dec > 0){
        if(dec % 2 == 0){
            ans = '0' + ans;
        } else {
            ans = '1' + ans;
        }
        dec = dec >> 1;
    }
    return ans;
}
int main(){
    int dec = 20;
    cout<<bin(dec)<<"\n";
}