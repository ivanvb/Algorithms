//https://codeforces.com/contest/26/problem/B

using namespace std;
#include <bits/stdc++.h>

/**
 * All '(' are thrown into a stack (represented as a vector).
 * Whenever a ')' is found, if the stack's size is greater than 0
 * then the count is incremented by 2.
 */
int par(string s){

    int c = 0;
    vector<char> v;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(') v.push_back(s[i]);
        else if(v.size() > 0)v.pop_back(), c+=2;
    }

    return c;
}
int main(){

    string s; cin >> s;
    cout << par(s) << endl;
}
