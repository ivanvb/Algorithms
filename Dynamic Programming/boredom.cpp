//https://codeforces.com/contest/455/problem/A
using namespace std;
#include<bits/stdc++.h>

map<int, int> m;
const int N = 100010;
int nums[N];
bool vis[N];
long long memo[N];

long long dp(int n){
    if(n < 0) return 0;
    if(vis[n]) return memo[n];

    int x = nums[n];

    long long best = -10000;

    if(x - nums[n-1] == 1){
        best = dp(n-1);
        best = max(best, (1LL * x * m[x]) + dp(n-2));
    }
    else{
        best = (1LL * x * m[x] + dp(n-1));
    }

    vis[n] = true;
    return memo[n] = best;
}
int main(){

    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        nums[i] = x;
        m[x]++;
    }

    int i = 0;
    for(auto &t: m){
        nums[i] = t.first;
        i++;
    }

     cout << dp(m.size() - 1) << endl;
}
