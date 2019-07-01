//https://codeforces.com/contest/556/problem/A
using namespace std;
#include <bits/stdc++.h>

/**
 * Travels the array only once, for each one it finds it checks
 * if there is a zero already seen, in case there is, it reduces
 * the amount of zeros by one and doesn't adds the one to the 'one'
 * counter. Also the length of the result is reduced by two.
 * This same process applies for the ones as well.
 */
int main(){

    int n; cin >> n;
    string s; cin >> s;

    int one = 0, zero = 0, sum = n;

    for(int i = 0; i < n; i++){

        if(s[i] == '1' && zero == 0) one++;
        else if(s[i] == '1' && zero > 0) zero--, sum-=2;
        else if(s[i] == '0' && one == 0) zero++;
        else if(s[i] == '0' && one > 0)one--, sum -=2;

    }

    cout << sum << endl;
}
