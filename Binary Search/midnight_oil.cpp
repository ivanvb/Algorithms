/*
https://codeforces.com/contest/165/problem/B
*/

using namespace std;
#include <bits/stdc++.h>

bool check(int mid, int n,int k){

    int res;
    int i = 0;
    do{
        res = mid/pow(k, i);
        n -= res;
        i++;
    }while(res > 0);

    return n <= 0;
}
int bs(int n, int k){

    int ans = -1;

    int left = 0; int right = n;

    while(left <= right){
        int mid = (left + right)/2;
        if(check(mid, n,k)){
            ans = mid;
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }

    return ans;
}

int main(){
    int n, k;

    cin >> n >> k;

    cout << bs(n, k) << endl;
}
