#include <iostream>
#include <cmath>
using namespace std;

bool starts_with(string input , string pattern , int pos){
    if(pos + pattern.size() > input.size()){
        return false;
    }

    for(int i=0 ; i<(int)pattern.size() ; i++){
        if(pattern[i] != input[i+pos]){
            return false;
        }
    }

    return true;
}

string replace_str(string input , string pattern , string to){
    string res="";
    for(int i=0 ; i<(int)input.size() ; i++){
        if(starts_with(input , pattern , i)){
            res+=to;
            i+=(int)pattern.size()-1;
        }
        else
            res+=input[i];
    }
    return res;
}

int main(){

    cout << starts_with("aabcabaaad", "aa", 0) << "\n";
    cout << starts_with("aabcabaaad", "aa", 1) << "\n";
    cout << starts_with("aabcabaaad", "aabcabaaad", 0) << "\n";
    cout << starts_with("aabcabaaad", "baaad", 5) << "\n";
    cout << starts_with("aabcabaaad", "baaad", 4) << "\n";

    cout << replace_str("aabcabaaad", "aa", "x") << "\n";
    cout << replace_str("aabcabaaad", "aa", "aaaa") << "\n";
    cout << replace_str("aabcabaaad", "aa", "") << "\n";

    return 0;
}
