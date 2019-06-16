//https://csacademy.com/contest/archive/task/dominoes

#include <bits/stdc++.h>
using namespace std;

int res(vector<int> v, int K){
    int left = K;
    deque<int> ss;
    ss.push_back(v[0]);

    int i = 0, j = 0;

    int m = 0;
    for(int j = 1; j < v.size(); j++){

        int current = v[j];
        int dist = current - ss.back() -1;
        left -= dist;

        ss.push_back(current);

        while(ss.size() > 1 && left < 0){
            int to_rem = ss.front();
            ss.pop_front();
            int dist = ss.front() - to_rem  -1;
            left += dist;
        }

        m = max(abs(ss.front() - ss.back()) + left + 1, m);
    }

    return m;
}

int main(){
    int n;
    cin >> n;
    int K;
    cin >> K;
    vector<int> v(n);
    for (int &t : v) cin >> t;

    cout << res(v, K) << endl;
}
