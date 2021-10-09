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
#define fo(i, n) for (ll i = 0; i < n; i++)
#define fon(i, n) for (ll i = 0; i <= n; i++)
#define fo1(i, n) for (ll i = 1; i < n; i++)
#define fo1n(i, n) for (ll i = 1; i <= n; i++)

const ll m = 1e9 + 7;

using namespace std;


void solve() {
	string s;
	int n, cnt = 0;
	cin >> n >> s;
	fo(i, n) if (s[i] == '0') cnt++;
	(cnt & 1) ? (cnt == 1) ? cout << "BOB" : cout << "ALICE" : cout << "BOB";
	cout << "\n";
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