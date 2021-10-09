#include <bits/stdc++.h>
#include <unordered_map>
typedef long long ll;
typedef unsigned long long ull;
#define int long long
#define wi(x) cout << #x << " = " << x << endl;
#define wi2(x, y) cout << #x << " = " << x << " and " << #y << " = " << y << endl;
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define testcase     \
    long long testn; \
    cin >> testn;    \
    while (testn--)
#define fo(i, l, r) for (int i = l; i < r; i++)
#define fo1(i, l, r) for (int i = l; i <= r; i++)
#define fore(i, l, r) for (int i = l; i > r; i--)
#define fore1(i, l, r) for (int i = l; i >= r; i--)
#define pb push_back
#define inp(v) for (auto &x : v) cin >> x;
#define disp(v)                      \
    for(const auto &x:v) cout << x << "\t"; \
    cout << "\n";

const ll m = 1e9 + 7;

using namespace std;

ll binpow(ll a, ll b) {
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

ll binmodpow(ll a, ll b) {
	if (b == 1)
		return a % m;
	ll res = 1;
	while (b > 0) {
		a = a % m;
		if (b & 1)
			res = (res * a) % m;
		a = (a * a) % m;
		b >>= 1;
	}
	return res;
}

int mod(int x, int y) {
	if (x >= y)
		return x - y;
	return y - x;
}

void solve() {
	cin.ignore();
	pair<int, int> a, b, f;
	cin >> a.first >> a.second;
	cin >> b.first >> b.second;
	cin >> f.first >> f.second;

	int dx = abs(a.first - b.first);
	int dy = abs(a.second - b.second);


	if (a.first == b.first) {
		if (!(f.first == a.first))
			cout << dy << "\n";
		else if (f.second > min(a.second, b.second) && f.second < max(a.second, b.second))
			cout << dy + 2 << "\n";
		else
			cout << dy << "\n";
	}

	else if (a.second == b.second) {
		if (!(f.second == a.second))
			cout << dx << "\n";
		else if (f.first > min(a.first, b.first) && f.first < max(a.first, b.first))
			cout << dx + 2 << "\n";
		else
			cout << dx << "\n";
	}

	else {
		cout << dx + dy << "\n";
	}



	/*
	wi2(a.first, a.second);
	wi2(b.first, b.second);
	wi2(f.first, f.second);
	wi2(dx, dy);
	*/
}

int32_t main() {
	IOS;
#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt", "r", stdin);
	//for writing output to output.txt
	freopen("output.txt", "w" , stdout);
#endif
	//clock_t tStart=clock();
	testcase solve();
	//printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}