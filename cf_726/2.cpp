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
#define inp(v) for (auto &x : v) cin >> x;
#define disp(v)                      \
    for(auto x:v) cout << x << "\t"; \
    cout << "\n";

const ll m = 1e9 + 7;

using namespace std;

int mod(int x, int y) {
	if (x >= y)
		return x - y;
	return y - x;
}
void solve() {

	int n, m, x, y;
	cin >> n >> m >> x >> y;

	if (n > 1 && m > 1) {
		int drx = mod(n, x), dry = mod(m, y), dlx = mod(n, x), dly = mod(1, y), urx = mod(1, x), ury = mod(m, y), ulx = mod(1, x), uly = mod(1, y);

		int sumdr = drx + dry;
		int sumdl = dlx + dly;
		int sumur = urx + ury;
		int sumul = ulx + uly;

		//wi2(sumur, sumul);
		//wi2(sumdr, sumdl);

		int x1, y1;

		if ((sumur >= sumul) && (sumur >= sumdr) && (sumur >= sumdl))
			x1 = 1, y1 = m;

		else if ((sumul >= sumur) && (sumul >= sumdr) && (sumul >= sumdl))
			x1 = 1, y1 = 1;

		else if ((sumdl >= sumdr) && (sumdl >= sumur) && (sumdl >= sumul))
			x1 = n, y1 = 1;

		else
			x1 = n, y1 = m;

		int x2, y2;

		if (((x1 - n) != 0) && ((y1 - m) != 0)) x2 = n, y2 = m;
		else if (((x1 - 1) != 0) && ((y1 - 1) != 0)) x2 = 1, y2 = 1;
		else if (((x1 - 1) != 0) && ((y1 - m) != 0)) x2 = 1, y2 = m;
		else x2 = n, y2 = 1;

		cout << x1 << "\t" << y1 << "\t" << x2 << "\t" << y2 << "\n";
	}
	else
		cout << "1\t1\t" << n << "\t" << m << "\n";

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
	//printf("Time taken: % .2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}