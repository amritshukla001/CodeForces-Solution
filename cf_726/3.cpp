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

const ll m = 1e9 + 7;

using namespace std;

pair<int, int> findMinDiff(vector<int> arr, int n)
{
	// Sort array in non-decreasing order
	sort(arr.begin(), arr.end());
	//disp(arr);
	// Initialize difference as infinite
	int diff = INT_MAX;
	pair<int, int> num;
	// Find the min diff by comparing adjacent
	// pairs in sorted array
	for (int i = 0; i < n - 1; i++)
		if (arr[i + 1] - arr[i] < diff) {
			diff = arr[i + 1] - arr[i];
			num.first = arr[i];
			num.second = arr[i + 1];
		}

	// Return min diff
	return num;
}

void solve() {
	int n;
	cin >> n;
	vector<int> hv(n);
	inp(hv);
	pair<int, int> x;
	x = findMinDiff(hv, n);
	vector<int> :: iterator it;
	it = find(hv.begin(), hv.end(), x.first);
	hv.erase(it);
	it = find(hv.begin(), hv.end(), x.second);
	hv.erase(it);

	//disp(hv);
	if (!(hv.empty())) {
		sort(hv.begin(), hv.end());
		cout << x.first << "\t";
		disp(hv);
		cout << x.second << "\n";
	}
	else
		cout << x.first << "\t" << x.second << "\n";

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