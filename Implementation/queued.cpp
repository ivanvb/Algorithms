//https://codeforces.com/contest/545/problem/D
using namespace std;
#include <bits/stdc++.h>

int main(){

    int n; cin >> n;
    multiset<int> m;
    int x;
    for(int i = 0; i < n; i++){
        cin >> x;
        m.insert(x);
    }

    int time = 0;
    int sum = 0;
    auto it = m.lower_bound(time);
    while(it != m.end()){
        sum ++;
        time += *(it);
        m.erase(it);
        it = m.lower_bound(time);
    }

    cout << sum << endl;
}
