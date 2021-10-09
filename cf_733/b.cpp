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
	int h, w;
	cin >> h >> w;
	//wi2(h, w);
	if (h % 2 && w % 2) {
		fo1(i, 1, h) {
			fo1(j, 1, w) {
				if ((i == 1 || i == h) && j % 2) cout << 1;
				else if (i % 2 && (j == 1 || j == w)) cout << 1;
				else cout << 0;
			}
			cout << "\n";
		}
	}
	else if (h % 2 == 0 && w % 2 == 0) {
		fo1(i, 1, h) {
			fo1(j, 1, w) {
				//wi2(i, j);
				if (i == 1 || i == h) {
					if (j % 2) cout << 1;
					else cout << 0;
				}
				else if (i % 2 && (j == 1 || j == w)) {
					if (i == h - 1) cout << 0;
					else cout << 1;
				}
				else cout << 0;
			}
			cout << "\n";
		}
	}
	else if (h % 2 && w % 2 == 0) {
		fo1(i, 1, h) {
			fo1(j, 1, w) {
				//wi2(i, j);
				if (i == 1 || i == h) {
					if (j % 2) cout << 1;
					else cout << 0;
				}
				else if (i % 2 && (j == 1 || j == w)) {
					if (i == h - 1) cout << 0;
					else cout << 1;
				}
				else cout << 0;
			}
			cout << "\n";
		}
	}
	else {
		fo1(i, 1, h) {
			fo1(j, 1, w) {
				//wi2(i, j);
				if (i == 1 || i == h) {
					if (j % 2) cout << 1;
					else cout << 0;
				}
				else if (i % 2 && (j == 1 || j == w)) {
					if (i == h - 1) cout << 0;
					else cout << 1;
				}
				else cout << 0;
			}
			cout << "\n";
		}
	}
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