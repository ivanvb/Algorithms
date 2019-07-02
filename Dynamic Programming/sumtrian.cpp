//https://www.spoj.com/problems/SUMTRIAN/
using namespace std;
#include <bits/stdc++.h>

const int N = 100;
const int M = 100;
bool vis[N][M];
int memo[N][M];
int tri[N][M];
int n;

int dp(int i, int j){
    if(i > j) return 0;
    if(j >= n) return 0;

    if(vis[i][j]) return memo[i][j];

    int best = -10000;

    int below = tri[i][j] + dp(i, j+1);
    int bel_ri = tri[i][j] +  dp(i+1, j+1);

    best = max(below, bel_ri);

    vis[i][j] = true;
    return memo[i][j] = best;
}
int main(){

    int t; cin >> t;
    vector<int> ans(t);

    for(int k = 0; k < t; k++){

        cin >> n;

        for(int j = 0; j < n; j++){
            for(int i = 0; i <= j ; i++){
                cin >> tri[i][j];
            }
        }

        ans[k] = dp(0, 0);
        memset(vis, false, N * M);
        memset(memo, 0, N* M);
        memset(tri, 0, N * M);
    }

    for(auto &t: ans) cout << t << endl;
}
