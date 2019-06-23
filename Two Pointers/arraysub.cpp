//https://www.spoj.com/problems/ARRAYSUB/
using namespace std;
#include <bits/stdc++.h>

int main(){

    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> v(n);
    for(auto &t: v) cin >> t;
    int k; cin >> k;

    multiset<int> m;
    for(int i = 0; i < k; i++) m.insert(v[i]);

    vector<int> ans(n - k + 1, 0); ans[0] = *(m.rbegin());

    int i = 0;
    for(int j = k; j < n; j++){
        m.erase(m.find(v[i]));
        i++;
        m.insert(v[j]);

        ans[i] = *(m.rbegin());
    }

    for(int i = 0; i < n - k + 1; i++) cout << ans[i] << " ";
    cout << endl;
}
