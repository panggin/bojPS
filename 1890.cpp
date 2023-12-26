#include <iostream>
using namespace std;

const int MAX_N = 100;
long long int step[MAX_N][MAX_N] = {0,};
long long int dp[MAX_N][MAX_N] = {0,};

int n, i, j;
long long int nxt;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n;
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            cin >> step[i][j];
        }
    }

    dp[0][0] = 1;
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            if (step[i][j] == 0) continue;
            if (dp[i][j] == 0) continue;
            
            nxt = i+step[i][j];
            if (nxt >= 0 && nxt < n) {
                dp[nxt][j] += dp[i][j];
            }

            nxt = j + step[i][j];
            if (nxt >= 0 && nxt < n) {
                dp[i][nxt] += dp[i][j];
            }
        }
    }
    cout << dp[n-1][n-1];
    return 0;
}