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

int mod(int x, int y) {
	//wi2(x, y);
	if (x > y)
		return x - y;
	return y - x;
}

bool check_nice(vector<int> &v, int n) {
	int temp;
	vector<int>::iterator it;
	fo(i, 0, n - 1) {
		fo(j, i + 1, n) {
			//wi2(i, j);
			temp = mod(v[i], v[j]);
			//wi(temp);
			it = find (v.begin(), v.end(), temp);
			if (it == v.end()) {
				v.push_back(temp);
				//disp(v);
				return false;
			}
		}
	}
	return true;
}

void solve() {
	int n;
	cin >> n;
	vector<int> b;
	int num;
	fo(i, 0, n) {
		cin >> num;
		b.push_back(num);
	}

	int s = b.size();
	//disp(b);
	//cout << "\n";
	//wi(s);
	vector<int>::iterator ip;

	int countu;
	sort(b.begin(), b.end());

	countu = distance(b.begin(), unique(b.begin(), b.begin() + n));

	//wi(countu);

	if (countu != s)
		cout << "NO\n";
	else {
		while (!(check_nice(b, s))) {
			s++;
			//wi(s);
			if (s > 300) break;
		}
		if (s <= 300) {
			cout << "YES\n" << s << "\n";
			disp(b);
			cout << "\n";
		}
		else
			cout << "NO\n";
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