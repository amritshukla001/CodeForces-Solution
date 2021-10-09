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
	int n, m;
	cin >> n >> m;

	vector<string> sv(n);
	vector<vector<int>> vec1(m, vector<int> (26, 0));

	string s;
	fo(i, 0, n) {
		cin >> s;
		sv[i] = s;
		fo(j, 0, m) {
			vec1[j][s[j] - 'a']++;
		}
	}

	fo(i, 0, n - 1) {
		cin >> s;
		fo(j, 0, m) {
			vec1[j][s[j] - 'a']--;
		}
	}

	string res;

	for (auto x : vec1) {
		int temp = 0;
		for (auto y : x) {
			if (y) {
				res += temp + 'a';
			}
			temp++;
		}
	}
	cout << res << endl;

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