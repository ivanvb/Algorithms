//https://codeforces.com/contest/991/problem/C
using namespace std;
#include <iostream>

bool check(long long n, long long k){

    if(k == 0) return false;
    long long total = n;
    long long A = 0;
    long long B = 0;

    while(n > 0){
        if(n < k){
            A += n;
            n = 0;
        }
        else{
            A += k;
            n -= k;
        }
        B += n/10;
        n -= n/10;
    }

    return A >= total/2.0;
}
long long bs(long long n){

    long long ans = -1;
    long long right = n; long long left = 0;

    while(left <= right){
        long long mid = (left + right)/2;

        if(check(n, mid)){
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

    long long n;
    cin >> n;
    cout << bs(n) << endl;
}
