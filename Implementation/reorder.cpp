//https://codeforces.com/contest/1007/problem/A
using namespace std;
#include <bits/stdc++.h>

/**
 * When the elements are all sorted (inside a set of pairs, each element being
 * paired with its position) my algorithm will try to move each element, ignoring
 * all the occurrences of the first element, to the first position of a smaller
 * number that is not already occupied.
 */
int main(){

    int n; cin >> n;
    vector<int> v(n);
    for(auto &t : v) cin >> t;

    set<pair<int, int>> s;
    for(int i = 0; i < n; i++){
        s.insert({v[i], i});
    }

    vector<int> ans(n, -1);
    auto snd = (*(s.begin())).first;
    auto it = s.upper_bound({snd, INT_MAX});

    auto iit = s.begin();

    queue<int> h;
    while(it != s.end()){

        if((*(iit)).first != (*(it)).first)
        {
            ans[(*(iit)).second] = (*(it)).first;
            iit++;
        }else{
            h.push((*(it)).first);
        }
        it++;

    }

    for(int i = 0; i < n; i++){
        if(ans[i] == -1 && h.size() > 0){
            ans[i] = h.front();
            h.pop();
        }
        else if(ans[i] == -1){
            ans[i] = (*(s.begin())).first;
        }

    }

    int sum = 0;
    for(int i = 0; i < n; i++){
        if(ans[i] > v[i]) sum++;
    }

    cout << sum << endl;
}
