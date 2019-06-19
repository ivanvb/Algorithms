//https://codeforces.com/contest/732/problem/D

using namespace std;
#include <bits/stdc++.h>

/**
 * Only take into consideration k days. If it is the last
 * chance to take the exam k in those k days, then take it.
 */
int m;
bool check(vector<int> &v, vector<int> &v2, int k){

    vector<int> v3(m+1, 0);
    for(int i = 0; i < k; i++) v3[v[i]]++;

    int days = 0;

    int exams = v2.size();

    for(int i = 0; i < k; i++){


        if(v3[v[i]] == 1 && v[i] != 0){


            days -=  v2[v[i] -1];
            exams --;


            if(days < 0){

                return false;
            }
        }
        else{
            v3[v[i]]--;
            days++;
        }
    }


    return exams == 0;
}
int bs(vector<int> &v, vector<int> &v2){

    int left = 0, right = v.size();
    int ans = -1;

    while(left <= right){
        int mid = (left + right)/2;

        if(check(v, v2, mid)){

            ans = mid;
            right = mid -1;
        }
        else{

            left = mid + 1;
        }
    }

    if(ans == 0) ans = -1;
    return ans;
}
int main(){
    int n;
    cin >> n >> m;

    vector<int> v(n);
    for(int &t : v) cin >> t;

    vector<int> v2(m);
    for(int &t: v2) cin >> t;

    cout << bs(v, v2) << endl;
}
