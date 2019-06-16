//https://codeforces.com/contest/670/problem/D2

using namespace std;
#include <bits/stdc++.h>

bool check(vector<tuple<int, int, int>> &t, long long k, long long mid){
    for(int i = 0; i < t.size(); i++){
        if(k < 0) break;
        int baked = get<0>(t[i]);
        int left = get<1>(t[i]);
        int ings = get<2>(t[i]);

        if(baked >= mid) continue;


        if(left > 0){
            k -= ings - left;
            //cout << "k is now: " << k << endl;
            baked++;
            left = 0;
        }

        long long needed = mid - baked;

        k -= needed * ings;
    }

    //cout << "k is: " << k << " for: " << mid << endl;
    return k >= 0;
}

long long bs(vector<tuple<int, int, int>> &t, int k){

    int ans = -1;
    long long left = 0,  right = INT_MAX;

    //cout << right << endl;
    while(left <= right){

        long long mid = (left + right)/2;

        if(check(t, k, mid)){
            ans = mid;
            left = mid+1;
        }
        else{
            right = mid -1;
        }
    }

    return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> grams(n);
    vector<int> ings(n);
    for(int &t : grams) cin >> t;
    for(int &t : ings) cin >> t;
    vector<tuple<int, int, int>> t;

    for(int i = 0; i < n; i++) t.push_back({ings[i]/grams[i], ings[i]%grams[i], grams[i]});

    //for(tuple<int, int, int> &m : t) cout << get<0>(m) << " " << get<1>(m) << " " << get<2>(m) << endl;

    cout << bs(t, k) << endl;
}
