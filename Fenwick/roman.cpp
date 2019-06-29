//https://codeforces.com/contest/61/problem/E
using namespace std;
#include <bits/stdc++.h>

/**
 * To solve this problem I used two Fenwick trees.
 * The first one was to get the amount of numbers that n has at its right
 * that are less than n.
 *
 * The second one is used like:
 * Check the total amount of elements that the ith element has at its right.
 * Add that to the total.
 * Update the ith element in Fenwick with the elements it has to its right.
 *
 * An example of this would be:
 *
 * Given: 13, 12, 10, 9, 7, 6, 8, 3, 4, 5, 11
 * Iterating from right to left:
 *
 * 11 query: 0, inserts: 0
 * 5  query: 0, inserts: 0
 * 4  query: 0, inserts: 0
 * 3  query: 0, inserts: 0
 * 8  query: 0, inserts: 3
 * 6  query: 3, inserts: 3
 * 7  query: 3, inserts: 7
 * as the query is bigger than 0, it means that numbers less than 7 can permute with 3
 * elements less than itself. In this particular case 6 can permute with 3, 4, 5. Therefore
 * you would have the following permutations
 * 7, 6, 3
 * 7, 6, 4
 * 7, 6, 5
 * This same logic goes on for every element, as the number of valid permutations according to
 * the problem's statement will always be the sum of the amount of numbers that every element
 * before n has at its right.
 */

/* fenwick 1 init. */
const long long MAX_N = 1000010;
long long fen[MAX_N];
long long N;

/* fenwick 2 init */
const long long MAX_N2 = 1000010;
long long fen2[MAX_N2];
long long N2;

/*Fenwick stuff*/
void update (long long pos, long long val) {
    for (long long i = pos; i <= N; i += i&-i)
        fen[i] += val;
}

void update2 (long long pos, long long val) {
    for (long long i = pos; i <= N2; i += i&-i)
        fen2[i] += val;
}

long long query (long long pos) {
    long long ret = 0;
    for (long long i = pos; i; i -= i&-i)
        ret += fen[i];
    return ret;
}

long long query2 (long long pos) {
    long long ret = 0;
    for (long long i = pos; i; i -= i&-i)
        ret += fen2[i];
    return ret;
}

/* Coordinate compression. */
vector <long long> coordCmpr (const vector <long long> &a) {
    vector <long long> cc = a;
    sort(begin(cc), end(cc));
    cc.resize(unique(begin(cc), end(cc))-begin(cc));

    vector <long long> res = a;
    for (auto &t : res) {
        t = lower_bound(begin(cc), end(cc), t)-begin(cc);
    }

    for(long long i = 0; i < res.size(); i++) res[i]++;

    return res;
}

int main(){

    long long n; cin >> n;
    vector<long long> c(n);
    for(auto &t: c) cin >> t;
    vector<long long> v = coordCmpr(c);

    N = *(max_element(v.begin(), v.end()));
    N2 = N;
    long long sum = 0;

    map<long long, long long> m;
    for(long long i = n-1; i >= 0; i--){
        m[v[i]] = query(v[i]);
        update(v[i], 1);
    }

    for(long long i =  n-1; i >= 0; i--){
        sum += query2(v[i]);
        update2(v[i], m[v[i]]);
    }

    cout << sum << endl;
}
