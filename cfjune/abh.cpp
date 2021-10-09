#include<bits/stdc++.h>
using namespace std;


const long long m = 1e9 + 7;

int power(int a, int b) {
    if (b == 1)
        return a % m;
    int res = 1;
    while (b > 0) {
        a = a % m;
        if ((b % 2) != 0)
            res = (res * a) % m;
        a = (a * a) % m;
        b /= 2;
    }
    return res;
}


int main()
{
#ifndef ONLINE_JUDGE
    //for getting input from input.txt
    freopen("input.txt", "r", stdin);
    //for writing output to output.txt
    freopen("output.txt", "w" , stdout);
#endif
    int n, m;
    int t;
    cin >> t;

    //cout << t << endl;
    while (t--)
    {
        cin >> n >> m;
        //cout << n;
        //cout << m;
        int temp = power(2, n);
        //cout << temp << "\n";

        int ans = power(temp - 1, m);

        cout << ans;
    }
}
