//https://codeforces.com/contest/919/problem/C

using namespace std;
#include <bits/stdc++.h>

/**
 * Returns the number of consecutive k '.' in a row.
 * @param v Vector containing the '.' and '*' matrix.
 * @param n Width
 * @param m Height
 * @param k Consecutive '.'
 * @return Number of consecutive horizontal '.' in the matrix.
 */
int mat(vector<vector<char>> v, int n, int m, int k){

    /* c contains the number of times there are consecutive points.
     * p contains the points that are consecutive in the current iteration. */
    long long c = 0, p = 0;

    deque<char> dq;

    if(v[0].size() < k) return 0;

    for(int i = 0; i < n; i++){
            p = 0;
        for(int j = 0; j < m; j++){
            /*Fills the dq with the first k elements of the vector*/
            if(j == 0){
                if(dq.size() > 0) dq.clear();
                for(int l = 0; l < k; l++){
                    dq.push_back(v[i][l]);
                    if(dq.back() == '.') p++;
                }
                j = k -1;
            }
            else{
                char to_rem = dq.front();
                if(dq.front() == '.') p--;
                dq.pop_front();

                dq.push_back(v[i][j]);
                if(dq.back() == '.') p++;
            }

            if(p == k) c++;
        }
    }

    return c;
}

/**
 * n x m matrix containing only '*' and '.'. This program finds
 * all possible k consecutive '.' vertically and horizontally.
 */
int main(){
    int n, m, k;
    cin >> n >> m >> k;

    deque<char> dq;
    vector< vector<char> > v(n, vector<char>(m));

    for(vector<char> &t : v){
        for(char &u : t) cin >> u;
    }

    long long c = mat(v, n, m, k);

    /**
     * if k is equal to 1, it doesn't matter whether
     * it's vertical or horizontal.
     */
    if(k != 1){
        /*Transposes the matrix*/
        vector<vector<char>> v2(m, vector<char>(n));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                v2[i][j] = v[j][i];
            }
        }

        c+=  mat(v2, m, n, k);
    }

    cout << c << endl;
}
