#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#define int long long
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define testcase     \
    long long testn; \
    cin >> testn;    \
    while (testn--)

#define wi(x) cout << #x << " = " << x << endl;
#define wi2(x, y) cout << #x << " = " << x << " and " << #y << " = " << y << endl;
#define fo(i, l, r) for (int i = l; i < r; i++)
#define fo1(i, l, r) for (int i = l; i <= r; i++)
#define fore(i, l, r) for (int i = l; i > r; i--)
#define fore1(i, l, r) for (int i = l; i >= r; i--)
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define inp(v) for (auto &x : v) cin >> x;
#define disp(v)                      \
    for(const auto &x:v) cout << x << "\t"; \
    cout << "\n";

const ll m = 1e9 + 7;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif
/*****************************************************************************************************************************/
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*******************************************************************************************************************************/


void solve() {
	int n, k;
	cin >> n >> k;

	vector<int> ar(n);
	inp(ar);
	vector<int> cnt(n + 1, 0);
	for (auto x : ar) cnt[x]++;

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
	debug(map1)

	for (auto x : map1) {
		int temp1 = 1;
		for (auto y : x.second) {
			ans[y] = temp1;
			temp1++;
			if (temp1 > k) break;
		}
	}

	int cntd = cntflk / k;
	int temp3 = 0;
	int temp2 = 0;

	for (auto x : map2) {

		if (temp3 >= cntd) break;
		for (auto y : x.second) {
			ans[y] = temp2 % k + 1;
			temp2++;
			if (temp2 % k == 0) temp3++;
			if (temp3 >= cntd) break;
		}
	}
	debug(ar)
	disp(ans);
}

int32_t main() {
	IOS;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w" , stdout);
	freopen("Error.txt", "w", stderr);
#endif
	//clock_t tStart=clock();
	testcase solve();
	//printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}