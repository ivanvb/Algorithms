//https://codeforces.com/contest/91/problem/B
using namespace std;
#include <bits/stdc++.h>

/* very similar logic to https://github.com/ivb98/Algorithms/blob/master/Implementation/knights_table.cpp */
int main(){

    int n; cin >> n;
    vector<int> v(n);
    for(auto &t: v) cin >> t;

    multiset<pair<int, int>> m;
    multiset<pair<int, int>> o;

    for(int i = 0; i < n; i++) m.insert({v[i], i}), o.insert({i, v[i]});

    auto it = m.end();
    vector<int> ans(n);

    for(int i = 0; i < n; i++){
        it--;
        pair<int, int> e = *(it);
        o.erase(o.find({e.second, e.first }));

        if(o.size() > 0){
            pair<int, int> s = *(--o.end());
            int a = (s.second < e.first && s.first > e.second) ? s.first - e.second - 1 : -1;
            ans[e.second] = a;
        }
        else{
            ans[e.second] = -1;
        }
    }

    for(auto &t: ans) cout << t<< " "; cout << endl;
}
