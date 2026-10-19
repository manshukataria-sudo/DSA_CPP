#include <iostream>
#include <vector>
using namespace std; 
int main(){
    string str1 = "abcab";
    string str2 = "cbab";

    string ans = "";

    for(int i = 1; i<=str1.size(); i++){
        for(int j = 1; j<=str2.size(); j++ ){
            if(str1[i-1] == str2[j-1]){
                ans += str1[i-1];
                break;
            }
        }
    }

    cout<<ans<<endl;
}