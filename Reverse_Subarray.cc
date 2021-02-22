#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
	int t;
	cin>>t;

	while (t--) {
		int n;
		cin>>n;
		vector<int> a(n);
		vector<vector<ll>> dp(n + 1, vector<ll>(3));

		for (auto &it : a)
			cin>>it;

		for (int i = 0; i < n; ++i) {
			dp[i + 1][0] = max(dp[i + 1][0], dp[i][0] + (i & 1 ? 0 : a[i]));

			if (i + 2 <= n)
				dp[i + 2][1] = max(dp[i + 2][1], max(dp[i][0], dp[i][1]) + (i & 1 ? a[i] : a[i + 1]));

			dp[i + 1][2] = max(dp[i + 1][2], max({dp[i][0], dp[i][1], dp[i][2]}) + (i & 1 ? 0 : a[i]));
		}
		cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;
	}
	
	return(0);
}