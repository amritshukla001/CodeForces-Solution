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
	int n, k;
	cin >> n >> k;
	//wi2(n, k);
	vector<int> ar(n);
	inp(ar);
	vector<int> cnt(n + 1, 0);
	for (auto x : ar) cnt[x]++;
	//disp(ar);
	//disp(cnt);

	int c1 = 0;

	for (auto x : cnt) {
		if (x == 1) c1++;
	}

	vector<int> ans(n, 0);
	map<int, vector<int>> map1;
	map<int, vector<int>> map2;

	int cntflk = 0;

	fo (i, 0, n) {
		if (cnt[ar[i]] >= k) map1[ar[i]].pb(i);
		else {
			map2[ar[i]].pb(i);
			cntflk++;
		}
	}

	for (auto x : map1) {
		//cout << x.first << "\n";
		int temp1 = 1;
		for (auto y : x.second) {
			ans[y] = temp1;
			temp1++;
			if (temp1 > k) break;
		}
		//cout << "\n";
	}
	//wi(cntflk);
	int cntd = cntflk / k;
	int temp3 = 0;
	int temp2 = 0;

	for (auto x : map2) {
		//cout << x.first << "\n";
		if (temp3 >= cntd) break;
		for (auto y : x.second) {
			ans[y] = temp2 % k + 1;
			temp2++;
			if (temp2 % k == 0) temp3++;
			//wi2(temp3, temp2);
			if (temp3 >= cntd) break;
		}

		//cout << "\n";
	}
	//disp(ar);
	disp(ans);
	//cout << "\n";
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