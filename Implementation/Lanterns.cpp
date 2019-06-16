//https://codeforces.com/problemset/problem/492/B
using namespace std;
#include <bits/stdc++.h>

/*
The answer to this problem will be the maximum number between:
-The maximum distance between the limits and the first/last lantern.
-The maximum distance between two lanterns divided by 2.

This is because, if each lantern can give light for a distance D, and taking into
consideration that each lantern will give the same amount of light, then the distance d
between Ln and Ln+1 can be equally split in a way that each one gives light to a d/2 segment.
However, for the limits this is not the case because at point 0 and at point l there can be no lanterns,
so, for these two the distance is not divided by 2.
*/
int main(){

    //Problem demands 9 digits precision.
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(9);

    int n, l;
    cin >> n >> l;
    vector<int> v(n);
    for(int &t : v) cin >> t;

    sort(v.begin(), v.end());

    /*Calculating the maximum limit distance.*/
    double m = max(v[0] - 0, l - v[n-1]);

    /*Calculating the distance between each pair of consecutive lanterns
      and dividing it by 2. Then storing the result if this distance is bigger
      than the previously bigger one.*/
    for(int i = 1; i < n; i++){
        m = max(m, (v[i] - v[i-1])/2.0);
    }


    cout << m << endl;
}
