#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// Function to find the number of ways to construct the
// sum N
ll solve(ll N) {
    ll mod = 1e9 + 7;

    // dp[] array such that dp[i] stores the number of ways
    // to construct sum = i
    ll dp[N + 1] = {};

    // Initialize dp[0] = 1 as there is only 1 way to
    // construct sum = 0, that is to not throw any dice at
    // all
    dp[0] = 1;

    // Iterate over all possible sums from 1 to N
    for (int i = 1; i <= N; i++) {
        // Iterate over all the possible values of the last die, that is from 1 to 6
        for (int j = 1; j <= 6 && j <= i; j++) {
            dp[i] = (dp[i] + (dp[i - j])) % mod;
        }
    }
    // Return the number of ways to construct sum = N
    return dp[N];
}
int main() {
    int n;
    cin >> n;
    cout << solve(n) << "\n";
}