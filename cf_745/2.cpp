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
#define fr first
#define sc second
#define pb push_back
#define mem1(ar)   memset(ar,-1,sizeof(a))
#define mem0(ar)   memset(ar,0,sizeof(a))
#define inp(v) for (auto &x : v) cin >> x;
#define disp(v)                      \
    for(const auto &x:v) cout << x << "\t"; \
    cout << "\n";
#define all(v) v.begin(),v.end()
#define uniq(v) (v).erase(unique(all(v)),(v).end())

template<typename T, typename T1>T amax(T &a, T1 b) {if (b > a)a = b; return a;}
template<typename T, typename T1>T amin(T &a, T1 b) {if (b < a)a = b; return a;}

const ll m = 1e9 + 7;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

/*---------------------------------------------------------------------------------------------------------------------------*/
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
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fr); cerr << ","; _print(p.sc); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*---------------------------------------------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b >>= 1;} return res;}
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
/*---------------------------------------------------------------------------------------------------------------------------*/

int bin_ans(int extra) {
	int left = 1;
	int right = 1e9;

	int ans;

	int mid;

	while (left <= right) {
		mid = left + (right - left) / 2;
		debug(mid);

		if (((mid * (mid + 1)) / 2) > extra) right = mid - 1;

		else if (((mid * (mid + 1)) / 2) < extra) {
			ans = mid;
			left = mid + 1;
		}

		else if (((mid * (mid + 1))) / 2 == extra) {
			ans = mid;
			return ans;
		}
	}
	return ans;
}

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	int max_ed = (n * (n - 1)) / 2;

	debug(mp(n, m));
	debug(mp(max_ed, k));

	if (m > max_ed || m < (n - 1)) cout << "NO\n";
	else {
		if ((k - 2) < 0) cout << "NO\n";
		else {
			int extra = m - (n - 1);
			/*int ind = lower_bound(all(se), extra) - se.begin();
			debug(mp(extra, ind));

			if (se[ind] == extra) {
				int maxd = (n - (ind + 2));
				if (maxd >= (k - 1)) cout << "NO\n";
				else cout << "YES\n";
			}
			else {
				ind = ind - 1;

				int maxd = (n - (ind + 2));
				if (maxd >= (k - 1)) cout << "NO\n";
				else cout << "YES\n";
			}*/
			int maxd;
			if (extra == 0) {
				maxd = n - 1;
				if (maxd >= (k - 1)) cout << "NO\n";
				else cout << "YES\n";
			}
			else {
				int req = bin_ans(extra);
				maxd = n - (req + 1);
				if (maxd >= (k - 1)) cout << "NO\n";
				else cout << "YES\n";
				debug(mp(extra, req));
			}
		}
	}
	debug("\n");
}


int32_t main() {
	IOS;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w" , stdout);
	freopen("Error.txt", "w", stderr);
#endif
	//clock_t tStart=clock();
	//pre();
	testcase solve();
	//printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}