using namespace std;
#include <bits/stdc++.h>

/**
 * Checks if a subarray of mid size whose sum is less or
 * equal than k exists in the vector v.
 *
 * @param v Vector
 * @param mid Size of the subarray.
 * @param k Bigger value the sum of the subarray can have.
 * @param n Size of v.
 * @return The subarray of size mid whose sum is less or equal
 * to k exists.
 */
bool check(vector<int> &v, int mid, int k, int n){

    int sum = 0;
    for(int i = 0; i < mid; i++){
        sum += v[i];
    }

    int i = 0;
    for(int j = mid; j < n; j++){
        if(sum <= k) break;

        sum -= v[i];
        i++;
        sum += v[j];
    }

    return sum <= k;
}
int bs(vector<int> &v, int k, int n){

    int left = 0, right = n;
    int ans = 0;

    while(left <= right){

        int mid = (left + right)/2;

        if(check(v, mid, k, n)){
            ans = mid;
            left = mid +1;
        }
        else{
            right = mid -1;
        }
    }

    return ans;
}
int main(){

    int n, t;
    cin >> n >> t;

    vector<int> b(n);
    for(int & t: b) cin >> t;

    cout << bs(b, t, n) << endl;
}
