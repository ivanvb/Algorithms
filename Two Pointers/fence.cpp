//https://codeforces.com/contest/363/problem/B
using namespace std;
#include <bits/stdc++.h>

int main(){

    int n, k; cin >> n >> k;
    vector<int> v(n);
    for(auto &t: v) cin >> t;

    int sum = 0;
    for(int i = 0; i < k; i++) sum += v[i];
    int m = sum, ind = 1;

    for(int i = k; i < n; i++){
        sum += v[i];
        sum -= v[i-k];

        if(sum < m){
            m = sum;
            ind = (i-k)+2;
        }
    }

    cout << ind <<  endl;

}
