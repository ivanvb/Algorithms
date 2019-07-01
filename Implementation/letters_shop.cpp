//https://codeforces.com/problemset/problem/1187/B
using namespace std;
#include <bits/stdc++.h>

/**
 * For each character in the Friend's name, checks if it is the rightmost
 * character. This can handle repeated characters because the position of each
 * character is stored in a vector of deques (one for each character form a to z),
 * and the position of the current iteration of a particular character is controlled
 * from a vector of indexes.
 *
 * @param v Vector of deques containing the index of each character.
 * @param f Name of the friend
 * @return number of elements that must be counted.
 */
int x(vector<deque<int>> &v, string &f){

    //vector of indexes.
    vector<int> ind(26, 0);
    int c = 0;

    /* finds the position of the character at position i
       in the Friends name, then maps it to an int j from 0
       to 25 and checks at which position that string is
       in the store's name, the position is chosen based
       on the value of j in the ind vector.*/
    for(int i = 0; i < f.size(); i++){
        int j = f[i] - 'a';
        int found = v[j][ind[j]];
        ind[j]++;
        c = max(found+1, c);
    }

    return c;
}
int main(){

    ios_base::sync_with_stdio(false);

    int t; cin >> t;
    string s; cin >> s;

    int n; cin >> n;
    vector<string> v(n);

    for(auto &t : v) cin >> t;

    /* this vector of deques store the position of each
       index in the word array, indexed by the integer
       value of the corresponding char - 'a', so it will
       go from 0 to 25. */
    vector<deque<int>> vs(26);
    for(int i = 0; i < t; i++){
        vs[s[i] - 'a'].push_back(i);
    }

    for(auto &t : v) cout << x(vs, t) << endl;
}
