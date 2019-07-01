//https://www.spoj.com/problems/YODANESS/
using namespace std;
#include <bits/stdc++.h>

/*fenwick */
const long long MAX_N = 1000000;
long long fen[MAX_N];
long long N;

void update (long long pos, long long val) {
    for (long long i = pos; i <= N; i += i&-i)
        fen[i] += val;
}

long long query (long long pos) {
    long long ret = 0;
    for (long long i = pos; i; i -= i&-i)
        ret += fen[i];
    return ret;
}

/**
 * This algorithm maps each word in the original string vector to an
 * integer, then, it travels the second string, and, based on the
 * previously created map, checks the amount of words that each one
 * has at its right with a lower index.
 *
 * This works because the amount of movements to order a disordered array
 * is equal to the number of inversions (aka i < j && A[i] > A[j]).
 */
int main(){

    long long t; cin >> t;

    vector<long long> ans(t);

    for(long long i = 0; i < t; i++){

        long long n; cin >> n;
        vector<string> s1(n);
        vector<string> s2(n);
        N = n+10;
        for(auto &t: s1) cin >> t;
        for(auto &t: s2) cin >> t;

        //Maps each string to an int.
        map<string, long long> m;
        for(long long i = 0; i < n; i++){
            m[s1[i]] = i+1;
        }

        //checks the inversion count for each word in the second string.
        long long sum = 0;
        for(long long i = n-1; i >= 0; i--){
            sum += query(m[s2[i]]);
            update(m[s2[i]], 1);
        }

        ans[i] = sum;
        m.clear();
        memset(fen,0,MAX_N);
    }

    for(auto &t: ans) cout << t << endl;
}
