//https://codeforces.com/problemset/problem/492/B

using namespace std;
#include <bits/stdc++.h>

/**
 * Searches the the first number that is bigger than k in the
 * sorted array and returns its position (which is the amount
 * of numbers that are less or equal than k)
 */
int bs(vector<int> &d, int k, int n){

    int left = 0, right = n;
    int ans = -1;
    while(left <= right){
        int mid = (left + right)/2;

        if(mid != n && d[mid] <= k){
            left =  mid + 1;
        }
        else{
            ans = mid;
            right = mid -1;
        }

    }

    return ans;
}
int main(){

    int n; cin >> n;
    vector<int> d(n);
    for(int &t : d) cin >> t;

    int q; cin >> q;
    vector<int> m(q);
    for(int &t : m) cin >> t;

    sort(d.begin(), d.end());

    for(int &t : m) cout << bs(d, t, n) << endl;

}
