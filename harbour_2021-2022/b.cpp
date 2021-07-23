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
	string s, t;
	cin >> s >> t;

	int fs = t.length();
	int gs = s.length();

	vector<int> index;

	fo(i, 0, gs) if (s[i] == t[0]) index.pb(i);

	bool res = false;
	fo(i, 0, index.size()) {
		int cur = index[i];
		int done = 0;
		bool ans = true;
		fo(j, 0, fs) {
			ans = true;
			int left = fs - done;
			if ((cur - 1) >= left) {
				//wi2(cur, j);
				string temp = s.substr(cur - left - 1, left);
				reverse(temp.begin(), temp.end());
				//wi2(temp, t.substr(j, left));
				if (temp == t.substr(j, left)) break;
			}
			if (s[cur] == t[j]) {
				cur++;
				done++;
				continue;
			}
			ans = false;
			break;
		}
		if (ans) {
			res = true;
			break;
		}
	}
	cout << ((res) ? "YES\n" : "NO\n");
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