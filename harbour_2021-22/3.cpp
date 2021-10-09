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

int min(string s) {

	int t1g = 0, t2g = 0;
	int ch1 = 0, ch2 = 0;
	int i = 0;
	for (i = 0; i < 10; i++) {

		ch1 = (10 - i) / 2;

		if (i % 2 == 0) ch2 = (10 - i) / 2;
		else ch2 = (10 - i) / 2 + 1;

		//wi2(ch1, ch2);
		//wi(i);
		//wi2(t1g, t2g);
		if (t1g > t2g + ch2 || t2g > t1g + ch1)
			return i;

		//wi2(ch1, ch2);
		//wi2(t1g, t2g);

		if (i % 2 == 0 && s[i] == '1') t1g++;

		else if (i % 2 == 1 && s[i] == '1') t2g++;

	}
	return i;

}
void solve() {
	string s;
	cin >> s;
	//wi(s);
	int c11 = 0, c12 = 0, c01 = 0, c02 = 0, cu1 = 0, cu2 = 0;


	fo(i, 0, 10) {
		if (i % 2 == 0) {
			if (s[i] == '1') c11++;
			else if (s[i] == '0') c01++;
			else cu1++;
		}
		else {
			if (s[i] == '1') c12++;
			else if (s[i] == '0') c02++;
			else cu2++;
		}
	}

	if (c11 + c12 == 10 || c01 + c02 == 10) cout << 10 << "\n";
	else if (cu1 + cu2 == 10) cout << 6 << "\n";

	else if (cu1 == 0 && cu2 == 0) {
		cout << min(s) << "\n";
	}

	else {
		string stemp1 = s;
		string stemp2 = s;
		int ans1 = 0, ans2 = 0;

		fo(i, 0, 10) {
			if (i % 2 == 0 && stemp1[i] == '?') stemp1[i] = '1';
			else if (i % 2 == 1 && stemp1[i] == '?') stemp1[i] = '0';
		}

		ans1 = min(stemp1);

		fo(i, 0, 10) {
			if (i % 2 == 0 && stemp2[i] == '?') stemp2[i] = '0';
			else if (i % 2 == 1 && stemp2[i] == '?') stemp2[i] = '1';
		}

		ans2 = min(stemp2);

		//wi2(ans1, ans2);

		cout << ((ans1 <= ans2) ? ans1 : ans2) << "\n";
	}

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