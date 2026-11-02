#include <iostream>
#include <vector>
using namespace std;

// using the ASCII values of characters, to represent the characters
void f(string& text, string& pattern, vector<int>& idx){

    // size of pattern and text
    int m = text.size();
    int n = pattern.size();

    // taking d = 26, as there are 26 characters in text string
    int d = 26;

    // taking q = 997, for reducing the COLLISIONS, SUPIRIOUS HITS OVERFLOW CONDITION
    int q = 997;

    // pre calculating the values d ^ (n- 1), n is the length of pattern
    int h = 1;
    for(int i = 1; i < n; i++){
        h = (h * d) % q;
    }

    // hash value of pattern and window of text
    int p = 0;
    int t = 0;
    for(int i = 0; i < n; i++){
        p = (p * d + pattern[i]) % q;
        t = (t * d + text[i]) % q;
    }

    // finding the occurences
    for(int i = 0; i<= m - n; i++){
        // if hash of pattern and text matches
        if(p == t){
            bool flag = true;
            for(int k = 0; k < n; k++){
                if(text[i + k] != pattern[k]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                idx.push_back(i);
            }
        }

        // calculating the value of next hash
        if(i < m - n){
            t = (d * (t - text[i] * h) + text[i + n]) % q;
        }

        // very important step
        // making t positive
        if(t < 0){
            t = t + q;
        }
    }

}
int main(){

    // taking the user input text and pattern
    string text, pattern;
    cout << "Enter the text : ";
    cin >> text;
    cout<<"Enter the pattern to search : ";
    cin >> pattern;

    vector<int> occurenceIdx = {};
    f(text, pattern, occurenceIdx);

    // if pattern is not present in text
    if(!occurenceIdx.size()){
        cout<<"Pattern not found\n";
    } else {
        cout<<"Pattern found at index/indices : ";
        for(int ele : occurenceIdx){
            cout<<ele<<" ";
        }
        cout<<"\n";
    }
    
}