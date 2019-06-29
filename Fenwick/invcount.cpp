//https://www.spoj.com/problems/INVCNT/

using namespace std;
#include <bits/stdc++.h>

/**
 * This problem is solved using a Fenwick Tree, the amount of
 * inversions is the sum, for each i, of the amount of numbers that are less than
 * the ith element and that are at its right.
 *
 * The program iterates from right to left, checks the amount of elements that are less
 * than i and that have been already seen, and then logs the ith element as an already
 * seen element.
 */
const int MAX_N = 20000010;
int fen[MAX_N];
int N;

void update (int pos, int val) {
    for (int i = pos; i <= N; i += i&-i)
        fen[i] += val;
}

int query (int pos) {
    int ret = 0;
    for (int i = pos; i; i -= i&-i)
        ret += fen[i];
    return ret;
}

void resetFenwick(vector<int> &v){

    for(int i = 0; i < v.size(); i++){
        if(query(v[i]) > 0) update(v[i], -1);
    }
}

long long invCount(vector<int> &v){

    N = *(max_element(v.begin(), v.end())) + 10;

    long long sum  =0;
    for(int i = v.size()-1; i >= 0; i--) {
        sum += query(v[i] -1);
        update(v[i], 1);
    }

    resetFenwick(v);

    return sum;
}

vector <int> coordCmpr (const vector <int> &a) {
    vector <int> cc = a;
    sort(begin(cc), end(cc));
    cc.resize(unique(begin(cc), end(cc))-begin(cc));

    vector <int> res = a;
    for (auto &t : res) {
        t = lower_bound(begin(cc), end(cc), t)-begin(cc);
    }

    for(int i = 0; i < res.size(); i++) res[i]++;
    return res;
}

int main(){

    ios_base::sync_with_stdio(false);

    int t; cin >> t;
    vector<long long> ans(t);
    for(int i = 0; i < t; i++){
        int n; cin >> n;
        vector<int> v(n);
        for(auto &t: v) cin >> t;
        vector<int> comp = coordCmpr(v);

        ans[i] = invCount(comp);
    }

    for(auto &t: ans) cout << t << endl;
}
