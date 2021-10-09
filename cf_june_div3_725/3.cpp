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

void solve() {
	int n, l, r;
	cin >> n >> l >> r;
	int cnt = 0;
	vector<int> num(n);
	fo(i, 0, n) cin >> num[i];
	//disp(num);
	sort(num.begin(), num.end());
	//disp(num);
	//cout << "\n";
	//int sum;
	//int ind1 = lower_bound(num.begin() + 2 , num.end(), 2) - num.begin();
	//int ind2 = upper_bound(num.begin()  , num.end(), 5) - num.begin();
	//wi2(ind1, ind2);
	//wi2(l, r);
	fo(i, 0, n - 1) {
		int c1 = l - num[i];
		int c2 = r - num[i];
		//wi2(c1, c2);
		int ind1 = lower_bound(num.begin() + i + 1 , num.end(), c1) - num.begin();
		int ind2 = upper_bound(num.begin() + i + 1 , num.end(), c2) - num.begin();
		//wi2(ind1, ind2);
		cnt += (ind2 - ind1);
	}
	cout << cnt << "\n";
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