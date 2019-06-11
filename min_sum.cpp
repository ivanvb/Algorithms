/**
 * Find the minimum (max element + min_element) in
 * a subsegment of size k from a given array.
 */

using namespace std;
#include <bits/stdc++.h>

int main(){

    int k, n;
    cin >> k >> n;
    vector <int> v(n);
    for(int &t : v) cin >> t;

    multiset <int> m;

    int i = 0; int j = k;

    for(i; i < j; i++){
        m.insert(v[i]);
    }

    int min_sum = *rbegin(m) + *begin(m);
    int sum;

    i = 0;

    for(j; j < v.size(); j++){
        m.erase(m.find(v[i]));
        i++;
        m.insert(v[j]);
        sum = *rbegin(m) + *begin(m);
        min_sum = min(min_sum, sum);
    }

    cout << min_sum << endl;
}
