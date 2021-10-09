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
#define inp(v) for (auto &x : v) cin >> x;
#define disp(v)                      \
    for(auto x:v) cout << x << "\t"; \
    cout << "\n";

const ll m = 1e9 + 7;

using namespace std;

void solve() {
	int n, m;
	vector<pair<int, int>> r;
	vector<pair<int, int>> w;
	char ch;
	cin >> n >> m;
	fo1(i, 1, n) {
		fo1(j, 1, m) {
			cin >> ch;
			if (ch == 'R') r.pb({i, j});
			if (ch == 'W') w.pb({i, j});
			if (ch == '.') continue;
		}
	}

	for (auto x : r) {
		for (auto y : r) {
			if (x.second == y.second) {
				wi2(x.first, y.first);
				if (((x.first - y.first)) % 2 != 0) {
					cout << "No\n";
					goto label;
				}
			}
			else if (x.first == y.first) {
				//wi2(x.first, y.first);
				if (((x.second - y.second)) % 2 != 0) {
					cout << "No\n";
					goto label;
				}
			}
			else {

			}
		}
	}
label:
	cout << "\n";
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