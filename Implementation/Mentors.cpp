//https://codeforces.com/contest/978/problem/F
using namespace std;
#include <bits/stdc++.h>

/**
 * For this problem, I cloned the original skill's vector into a new vector VS of the same size
 * of type pair, the pair consisted of the skill of the ith programmer and its index. Once stored
 * there I sorted it based on its skill. Then created a map M and stored the answer for the skill at
 * the ith position VS. The answer is calculated by putting the index of that element in the array
 * because it will always have its position - 1 values to the left (which are lower than the current value),
 * the only exception is when VS[i] == VS[i-1], when this happens the value stored in M for VS[i] is VS[i-1].
 *
 * Once this is done, I iterate over the vector P containing the pairs and get which programmer of the pair
 * has the higher skill, then reduce its value by 1 in the answers vector.
 */

int main(){

    int n; long long k;

    cin >> n >> k;

    vector<int> s(n);
    for(int &t: s) cin >> t;

    vector<pair<int, int>> p(k);
    for(pair<int, int> &t: p) cin >> t.first >> t.second;

    vector<pair<int, int>> sorted;
    for(int i = 0; i < n; i++) sorted.push_back({s[i], i+1});

    sort(sorted.begin(), sorted.end());

    map<int, int> ans;

    ans[sorted[0].first] = 0;
    for(int i = 1; i < n; i++){
        if(ans.count(sorted[i].first) == 0){
            ans[sorted[i].first] = i;
        }
    }

    vector<int> answer(n);

    for(int i =0; i < n; i++){
        answer[i] = ans[s[i]];
    }

    for(long long i = 0; i < k; i++){

        if(s[p[i].first -1] > s[p[i].second -1]){
            answer[p[i].first -1] --;

        }
        else if(s[p[i].first -1] < s[p[i].second -1]){
            answer[p[i].second -1]--;
        }

    }

    for(int i = 0; i < n; i++){
        cout << answer[i] << " ";
    }

}
