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

void solve() {
	int n;
	cin >> n;

	vector<int> mys;
	vector<int> ls;

	int x;

	fo1(i, 1, n) {
		cin >> x;
		//wi(x);
		mys.pb(x);
	}

	fo1(i, 1, n) {
		cin >> x;
		//wi(x);
		ls.pb(x);
	}

	sort(mys.rbegin(), mys.rend());
	sort(ls.rbegin(), ls.rend());

	//disp(mys);
	//disp(ls);

	int myssum = 0;
	int lssum = 0;

	int stage = n - n / 4;

	//wi(stage);
	//cout << mys.begin() << "\n";

	fo(i, 0, stage) {
		myssum += mys[i];
		lssum += ls[i];
	}

	//wi(mys[stage - 1]);
	//wi(ls[stage]);

	int left = n - stage;

	//wi(left);

	int ans = 0;
	int nstage;
	int temp = 1, temp1 = 0, temp2 = 1;

	while (myssum < lssum) {
		if ((n + temp) % 4 == 0) {
			if (temp2 <= stage) {
				myssum += 100;
				myssum -= mys[stage - temp2];
				//cout << "here\n";
				temp2++;
			}
		}
		else {
			myssum += 100;
			if (left != 0) {
				lssum += ls[stage + temp1];
				temp1++;
				left--;
			}
		}
		temp++;
		ans++;
		//wi2(myssum, lssum);
	}

	cout << ans << "\n";
	//for (auto x : mys) myssum += x;
	//for (auto x : ls) lssum += x;

	//wi2(myssum, lssum);
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