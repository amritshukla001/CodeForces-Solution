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
	int l, a, b;
	cin >> l >> a >> b;
	string s;
	cin >> s;
	//wi(s);

	if (b == 0) cout << a*l << "\n";
	else if (b < 0)  {
		vector<int> c0;
		vector<int> c1;
		int cnt0 = 0;
		int cnt1 = 0;
		fo(i, 0, l) {
			if (s.at(i) == '0') cnt0++;
			else cnt1++;
		}
		if (cnt0 == 0 || cnt1 == 0) cout << a*l + b << "\n";
		else {
			char ch = s[0];
			int temp = 1;
			int ind = 0;
			fo(i, 1, l) {
				//wi(s[i]);
				if (s[i] == ch) temp++;
				else {
					if (ch == '0') c0.pb(temp);
					else c1.pb(temp);

					ch = s[i];
					temp = 1;
				}
				//wi2(ch, temp);
			}

			if (s[l - 1] == '0') c0.pb(temp);
			else c1.pb(temp);

			/*
			disp(c0);
			disp(c1);
			int sum0 = 0, sum1 = 0;
			for (auto &x : c0) {
				sum0 += x;
			}
			for (auto &x : c1) {
				sum1 += x;
			}

			wi2(sum0, sum1);
			*/
			int cnt = min(c0.size(), c1.size());

			int ans = a * l + b * (cnt + 1);
			cout << ans << "\n";
		}
		//cout << "min\n";
	}
	else cout << (a + b)*l << "\n";
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