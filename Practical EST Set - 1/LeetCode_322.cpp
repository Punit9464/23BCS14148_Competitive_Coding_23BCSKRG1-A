#include <bits/stc++.h>
#define endl '\n'
using namespace std;

int tabulate(vector<int> &arr, int target) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target+1, 0));

    for(int i = 0; i <= target; i++) {
        if(i%arr[0]) dp[0][i] = 1e9;
        else dp[0][i] = (i/arr[0]);
    }

    for(int i = 1; i < n; i++) {
        for(int j = 0; j <= target; j++) {
            int pick = 1e9;
            if(arr[i] <= j) {
                pick = 1 + dp[i][j-arr[i]];
            }
            int notPick = dp[i-1][j];

            dp[i][j] = min(pick, notPick);
        }
    }

    return dp[n-1][target] == 1e9 ? -1 : dp[n-1][target];
}

int main() {
  vector<int> coins = { 1, 2, 5 };
  int amount = 11;
  int ans = tabulate(coins, amount);
  cout<<ans<<endl;
  return 0;
}
