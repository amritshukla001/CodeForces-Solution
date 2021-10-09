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

bool check(vector<int> re, vector<int> retg, int cnt) {
	//disp(re);
	//disp(retg);
	fo(i, 0, cnt) {
		if (re[i] == retg[i]) return false;
	}
	return true;
}
void solve() {

	int n;
	cin >> n;
	vector<int> ew(n);
	inp(ew);
	//disp(ew);

	unordered_set<int> s;
	vector<pair<int, bool>> cew;

	vector<int> retg;

	vector<pair<int, int>> etoe;

	fo(i, 0, n) {
		if (s.find(ew[i]) == s.end())  {
			cew.pb({i + 1, true});
			etoe.pb({i + 1, ew[i]});
		}
		else cew.pb({i + 1, false});
		s.insert(ew[i]);
	}

	vector<int> re;

	for (auto x : cew) {
		if (!x.second) re.pb(x.first);
	}

	//disp(re);

	fo(i, 0, n) {
		if (s.find(i + 1) == s.end()) retg.pb(i + 1);
	}

	//disp(retg);

	int cnt = re.size();

	if (cnt == 0) {
		cout << n << "\n";
		disp(ew);
	}
	else if (cnt != 1) {
		while (!check(re, retg, cnt)) {
			int temp1 = retg[0];
			fo(i, 0, cnt - 1) {
				retg[i] = retg[i + 1];
			}
			retg[cnt - 1] = temp1;
			//disp(retg);
		}
		fo(i, 0, cnt) {
			etoe.pb({re[i], retg[i]});
		}
		sort(etoe.begin(), etoe.end());
		cout << n - re.size() << "\n";
		for (auto x : etoe) cout << x.second << "\t";
		//disp(re);
		//disp(retg);
	}
	else {
		if (re[0] != retg[0]) {
			etoe.pb({re[0], retg[0]});
			sort(etoe.begin(), etoe.end());
			cout << n - 1 << "\n";
			for (auto x : etoe) cout << x.second << "\t";
		}
		else {
			int rew = ew[re[0] - 1];
			fo(i, 0, n) {
				if (etoe[i].first == re[0]) continue;
				else if (etoe[i].second == rew) {
					etoe.pb({etoe[i].first, retg[0]});
					etoe.erase(etoe.begin() + i);
					break;
				}
			}
			etoe.pb({re[0], rew});
			sort(etoe.begin(), etoe.end());
			cout << n - 1 << "\n";
			for (auto x : etoe) cout << x.second << "\t";
			//wi(rew);
			//auto it = find_if(etoe.begin(), etoe.end())
		}
	}
	//for (auto x : s) cout << x << "\t";

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