//https://codeforces.com/contest/978/problem/C
using namespace std;
#include <bits/stdc++.h>

long long bs(vector<long long> &v, long long x){

    long long left = 0, right = v.size(), ans = -1;

    while(left <= right){

        long long mid = (left + right)/2;

        if(x <= v[mid]){
            ans = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }

    return ans;
}
int main(){

    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    vector<long long> v(n);

    for(long long &t : v) cin >> t;

    vector <long long> r(m);
    for(long long &t : r) cin >> t;

    /*
    Array that stores the sum from 0 to i of the ith element
    in the v vector
    */
    vector<long long> s(n+1);

    unsigned long long sum = 0;
    s[0] = 0;

    for(int i = 0; i < n; i++){
        sum += v[i];
        s[i+1] = sum;
    }

    /*
    Performs a binary search on every room in the r vector.
    The binary search will return the index of the first number
    that is less or equal than n r[i]. The index of this element
    corresponds to the dorm number.

    To calculate the room number, as I inserted 0 at the beginning of
    the S array, the room number will always be equal to r[i] - the sum
    of all the dorm rooms before s[dorm], which means s[dorm - 1].
    */
    for(int i = 0; i < m; i++){

        long long dorm = bs(s, r[i]);
        long long room = r[i] - s[dorm -1];

        cout << dorm << " " << room << endl;
    }
}
