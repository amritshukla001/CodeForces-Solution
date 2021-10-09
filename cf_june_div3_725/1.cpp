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
#define pb push_back
#define disp(v) for(auto x:v) cout << x << "\t"

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

void solve() {
	int n;
	cin >> n;
	int cnt;
	vector<int> num(n + 1);
	fo1 (i, 1, n) cin >> num[i];
	//disp(num);
	//cout << "\n";
	//auto it1 = find(num.begin(), num.end(), 1);
	int i1 = find(num.begin(), num.end(), 1) - num.begin();
	//auto it2 = find(num.begin(), num.end(), n);
	int i2 = find(num.begin(), num.end(), n) - num.begin();
	//wi2(i1, i2);
	int i1f = min(i1, n + 1 - i1);
	int i2f = min(i2, n + 1 - i2);
	//wi2(i1f, i2f);
	cnt = min(i1f, i2f);
	//wi(cnt);
	int temp;
	if (i1 > i2)  temp = i1 - i2;
	else temp = i2 - i1;
	if (cnt == i1f)	cnt += min(temp, i2f);
	else cnt += min(temp, i1f);
	cout << cnt << "\n";
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