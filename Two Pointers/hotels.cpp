//https://www.spoj.com/problems/HOTELS/
using namespace std;
#include <bits/stdc++.h>

int main(){

    ios_base::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    int max_ = 0, i = 0, sum = 0;

    for(int j = 0; j < n; j++){
        if(sum + v[j] > m){
            sum += v[j];
            while(sum > m){
                sum -= v[i];
                i++;
            }
            max_ = max(max_, sum);
        }
        else{
            sum += v[j];
            max_ = max(max_, sum);
        }
    }


    cout << max_ << endl;
}
