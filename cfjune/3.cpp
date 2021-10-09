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
	string s;
	cin >> s;
	int len = s.length();
	//wi(len);

	string ans;
	int res = 0;

	//vector<pair<int, int>> nb;
	vector<string> nb;

	int i = 1;

	while (i < (len - 1)) {
		//wi(i);
		char ch = '?';
		if (s.at(i) == ch) {
			//wi(ch);
			int count = 1;
			int x = i - 1;
			//wi(x);
			char ch1 = s.at(x);
			//wi(ch1);
			i++;
			//wi(i);
			//wi(s.at(i));
			while (i < (len - 1) && s.at(i) != '1' && s.at(i) != '0') {
				count++;
				i++;
				//wi(i);
			}
			//wi(count);
			if (count & 1) {
				if (s.at(i) != ch1) nb.pb(s.substr(x, i + 1));
			}
			else {
				//wi(i);
				if (s.at(i) == ch1) nb.pb(s.substr(x, i + 1));
			}
			//wi(i);
		}
		i++;
	}

	for (auto x : nb) {
		cout << x << "\n";
	}
	cout << "\n";



	//to find total no of continguous substring
	/*substring(pos,len)
	(pos start from 0
	and len from 1)
	*/
	sort(nb.begin(), nb.end());

	for (int i = 0; i <= (len - 1); i++) {

		for (int j = 1; j <= (len - i); j++) {


			int m = i + (j - 1);

			//wi2(i, j);
			ans = s.substr(i, j);
			int index;

			wi(ans)
			cout << "\n";

			string s1 = "00";
			string s2 = "11";

			/*
			check if a string contains the given substring
			Input − The main string and the substring to check
			Output − The positions of the substring in the main string

			pos := 0
			while index = first occurrence of sub_str into the str in range pos to end of the string, do
				print the index as there is a match
				pos := index + 1
			done

			if not present return string::npos
			https://www.tutorialspoint.com/check-if-a-string-contains-a-sub-string-in-cplusplus
			*/

			pair<int, int>mp{i, m};
			//wi2(i, m);

			//if (binary_search(nb.begin(), nb.end(), mp)) cout << "hello\n";

			if ((index = ans.find(s1, 0)) == string::npos && (index = ans.find(s2, 0)) == string::npos) {
				//wi(res);
				res++;
				//wi(res);
			}
		}
	}
	cout << res << "\n";
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