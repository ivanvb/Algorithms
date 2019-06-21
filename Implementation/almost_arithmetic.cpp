//https://codeforces.com/contest/978/problem/D

using namespace std;
#include <bits/stdc++.h>

int main(){

    int n; cin >> n;
    vector<int> v(n);
    for(auto &t : v) cin >> t;
    if(n > 1){

        /*
        There will always be 9 possible arithmetic progressions.
        All of them are obtaining by a combination of the first
        two numbers +1, +0 or +(-1).

        So, if there is at least one arithmetic progression that
        can be formed with the given numbers it will be among
        these 9.
        */
        vector<vector<int>> v2(9, vector<int>(v.size()));
        vector<int> res(9,0);

        vector<int> in = {0, 1, -1};

        /*Obtains all possible permutations and stores them in the v2 vector.*/
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){

                v2[i*3 + j][0] = v[0] + in[i];
                v2[i*3 + j][1] = v[1] + in[j];
                int diff = (v[1] + in[j]) - (v[0] + in[i]);
                int last = v[1] + in[j];

                for(int k = 2; k < v.size(); k++)
                {
                    v2[i*3 + j][k] = last + diff, last += diff;
                }

            }

        }

        /*
        Checks the difference between v[i] and the ith element inside each one
        of the possible solutions. In case the difference is > 1 that solution
        gets discarded because you would need to increase/decrease the ith value
        by more than 1 in order to achieve this progression.

        In case the difference is exactly 1, then the amount of steps given to achieve
        this particular result will increase by one.
        */
        for(int i = 0; i < v.size(); i++){
            for(int j = 0; j < v2.size(); j++){
                int diff = abs(v2[j][i] - v[i]);
                if(diff > 1){
                    v2.erase(v2.begin() + j);
                    res.erase(res.begin() + j);
                    j--;
                }
                else if(diff == 1) res[j]++;
            }
        }

        /*If v2 is empty it means that there is no solution for this problem given the
          current constraints. So it will print -1, else it will print the minimum value
          of res, which corresponds to the least amount of steps given to get this an
          arithmetic progression.
          */
        if(v2.size() == 0) cout << -1 << endl;
        else cout << *min_element(begin(res), end(res)) << endl;
    }
    else{
        cout << 0 << endl;
    }



}
