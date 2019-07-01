//https://codeforces.com/contest/994/problem/B
using namespace std;
#include <bits/stdc++.h>

/**
 * Pairs the value of each knight's strength to its money and stores them
 * in two multisets, one ordered by money and another by strength.
 *
 * Then starts traveling the multiset ordered by strength from end to begin,
 * for each element it removes it from the money multiset because as it is
 * the one with the most strength, no other knight will be able to kill him
 * and take his money.
 *
 * To calculate the max amount of money that each knight q will be able to earn,
 * after removing itself from the money multiset, it sums the amount of money
 * that q has with the amount of money of each of the last k elements of the
 * money sorted multiset.
 */
int main(){

    long long n, k; cin >> n >> k;
    vector<long long> v(n);
    vector<long long> m(n);
    for(auto&t : v) cin >> t;
    for(auto &t: m) cin >> t;

    multiset<pair<long long, long long>> st; //strength sorted multiset
    multiset<pair<long long, long long>> mo; //money sorted multiset
    for(long long i = 0; i < n; i++){
        st.insert({v[i], m[i]});
        mo.insert({m[i], v[i]});
    }

    map<long long, long long> ans;

    auto it = st.end();
    for(long long i = 0; i < n; i++){

        it--;
        pair<long long, long long> b = (*(it));
        mo.erase(mo.find({b.second, b.first}));

        long long sum = b.second;

        auto iit = mo.end();
        /*if there are not k elements left, that knight can only kill the
          amount of elements left in the money multiset. */
        long long l = (k < mo.size()) ? k : mo.size();
        for(long long i = 0; i < l; i++){
            iit--;
            if(it == mo.begin()) break;

            sum += (*(iit)).first;
        }

        ans[b.first] = sum;
    }

    for(auto &t: v) cout << ans[t] << " ";cout << endl;
}
