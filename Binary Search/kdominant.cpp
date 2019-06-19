//https://codeforces.com/contest/888/problem/C
using namespace std;
#include <bits/stdc++.h>

/**
 * A character will be considered k dominant if it appears on
 * every substring of size k. To know this information I created
 * two maps, the first one, m, stores the characters present on the
 * substring of size k. The second one, ans, is the one that will be
 * checked at the end to see if there is a k dominant character or not.
 *
 * For the iteration I used sliding window. So, the number of iterations will
 * be equal to n - k + 1. So, if at the end of the function, any character in
 * the ans map has a value of n - k + 1 it means that for a distance k a dominant
 * character is possible.
 */
bool check(string s, int k){

    int goal = s.size() - k + 1;
    int n = s.size();
    map<char, int> m;
    map<char, int> ans;

    for(int i = 0; i < k; i++) m[s[i]]++;

    for(int i = 97; i < 123; i++) if(m[i] > 0) ans[i]++;

    int i = 0;
    for(int j = k; j < n; j++){
        m[s[i]]--;
        i++;
        m[s[j]]++;

        /*
        As this iteration is constant it wasn't taken into consideration at first.
        But later on I discovered that 26 operations per iteration of this
        loop was not a good practice.
        */
        for(int i = 97; i < 123; i++) if(m[i] > 0) ans[i]++;
    }
    for(int i = 97; i < 123; i++) if(ans[i] == goal) return true;

    return false;
}

int bs(string s){

    int left = 0; int right = s.size();
    int ans = -1;

    while(left <= right){
        int mid = (left + right)/2;

        if(check(s, mid)){

            right = mid -1;
            ans = mid;
        }
        else{

            left = mid + 1;
        }
    }

    return ans;
}
int main(){

    string s; cin >> s;
    cout << bs(s) << endl;
}
