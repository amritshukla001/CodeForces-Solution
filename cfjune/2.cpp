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
#define disp(v) for(auto x:v) cout << x << "\t"

const ll m = 1e9 + 7;

using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

void solve() {
	int n;
	cin >> n;
	int x;
	vector<int> a(n);
	vector<int> eve;
	vector<int> odd;
	fo(i, 0, n) {
		cin >> x;
		if (x & 1)
			odd.push_back(x);
		else
			eve.push_back(x);
	}

	fo(i, 0, eve.size())
	a[i] = eve[i];

	int k = 0;

	fo(j, eve.size(), n) {
		a[j] = odd[k];
		k++;
	}

	//disp(a);
	//cout << "\n";

	int count = 0;

	fo(i, 0, n - 1) {
		fo(j, i + 1, n) {
			//wi(gcd(a[i], 2 * a[j]));
			if (gcd(a[i], 2 * a[j]) > 1)
				count++;
		}
	}

	cout << count << "\n";
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