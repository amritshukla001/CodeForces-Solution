#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#include <unordered_map>
typedef long long ll;
typedef unsigned long long ull;
#define whatis(x) cout << #x << " = " << x << endl;
#define whatis2(x, y) cout << #x << " = " << x << " and " << #y << " = " << y << endl;
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define testcase     \
    long long testn; \
    cin >> testn;    \
    while (testn--)
#define loop(i, n) for (ll i = 0; i < n; i++)
#define loopn(i, n) for (ll i = 0; i <= n; i++)
#define loop1(i, n) for (ll i = 1; i < n; i++)
#define loop1n(i, n) for (ll i = 1; i <= n; i++)
#define vfor(i) for(auto i = (v).begin() ; i!= (v).end(); i++)

/*
int prime[10000000] = {0} ;
void calculateprime()
{
    //calculating primes
    prime[0] = prime[1] = 1 ;
    for(int i = 2 ; (ll)i*i <= 10000000 ; i++)
    {
        if(prime[i] == 0)
        {
            for(ll j = i*i ; j <= 10000000 ; j += i )
            {
                prime[j] = 1 ;
            }
        }
    }
}
*/

/*
ll fib(int n)
{
  ll a = 0, b = 1, c, i;
  if( n == 0)
    return a;
  for (i = 2; i <= n; i++)
  {
    c = (a + b);
    a = b;
    b = c;
  }
  return b;
}
*/

/*
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
*/

/*
ll findgrouplcm(ll arr[], ll n)
{
    ll ans = arr[0];

    for (ll i = 1; i < n; i++)
        ans = (arr[i] * (ans/(gcd(arr[i], ans))));

    return ans;
}
/*

ll powerwithmod(ll x, unsigned ll y, ll p)
{
    ll res = 1;

    x = x % p;

    if (x == 0) return 0;

    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;

        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
*/

using namespace std;

void solve() {

}

int main() {
	IOS;
#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt", "r", stdin);
	//for writing output to output.txt
	freopen("output.txt", "w" , stdout);
#endif
	testcase {
		solve();
	}
	return 0;
}

