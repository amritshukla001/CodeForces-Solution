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

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	inp(a);
	inp(b);
	int tbi = 0;
	int tbd = 0;

	vector<int> itbi;
	vector<int> itbd;

	fo(i, 0, n) {
		//wi2(a[i], b[i]);
		if (a[i] == b[i])
			continue;
		else if (a[i] > b[i]) {
			tbd += a[i] - b[i];
			//wi(tbd);
			fo(j, 0, a[i] - b[i])
			itbd.pb(i + 1);
		}
		else {
			tbi += b[i] - a[i];
			//wi(tbi);
			fo(j, 0, b[i] - a[i])
			itbi.pb(i + 1);
		}
	}

	if (tbd == 0 && tbi == 0)
		cout << "0\n";
	else if (tbd == tbi) {
		cout << tbd << "\n";
		fo(i, 0, tbd) {
			cout << *(itbd.begin() + i) << "\t" << *(itbi.begin() + i) << "\n";
		}
		//disp(itbi);
		//disp(itbd);
	}
	else
		cout << "-1\n";
	//disp(a);
	//disp(b);
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