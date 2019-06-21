//https://codeforces.com/problemset/problem/519/B

using namespace std;
#include <bits/stdc++.h>

int main(){

    ios_base::sync_with_stdio(false);
    map<int, pair<int, int>> m;
    int n, a; cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a;
        m[a].first++, m[a].second++;
    }

    for(int i = 0; i < n-1; i++) cin >> a, m[a].first++;

    for(int i = 0; i < n-2; i++) cin >> a, m[a].first++;

    int f, s;
    for(auto &t: m){

        int goal =  t.second.second * 3;

        if(goal - t.second.first == 0) continue;
        else if(goal - t.second.first == 3){
            f = t.first, s = t.first;
        }
        else if(goal - t.second.first == 2){
            f = t.first;
        }
        else if(goal - t.second.first == 1){
            s = t.first;
        }
    };

    cout << f << endl << s << endl;
}
