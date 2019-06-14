/*
https://www.spoj.com/problems/AGGRCOW/
*/

#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &v, int c, int mid){

    int last = v[0];
    c--;

    for(int i = 1; i < v.size(); i++){
        if(c == 0) break;

        //cout << "Now computing: " << v[i] << "-" << last << "  mid is: " << mid << endl;
        if(v[i] - last >= mid){

            last = v[i];
            c--;
            //cout << endl << "C is now: " << c << endl;
        }
    }
    //cout << endl;
    return c == 0;
}
int bs(vector<int> &v, int c){

    int ans = 0;

    int left = 0, right =v[v.size() -1];

    while(left <= right){

        int mid = (left + right)/2;

        if(check(v, c, mid)){
            ans = mid;
            left = mid+1;

            //cout << mid << " returned true, arr is [" << left << "," << right << "]" << endl;
        }
        else{
            right = mid-1;
            //cout << mid << " returned false, arr is [" << left << "," << right << "]" << endl;
        }
    }

    return ans;
}
int main(){

    int t;
    cin >> t;

    while(t--){
        int n, c;
        cin >> n >> c;
        vector<int> v(n);

        for(int &t : v) cin >> t;

        sort(v.begin(), v.end());
        cout << bs(v, c) << endl;
    }

}
