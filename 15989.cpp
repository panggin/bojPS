#include <iostream>
using namespace std;

const int MAX_N = 10000 + 1;

int dp[MAX_N][4] = {0,}; // dp[총합][사용된 숫자의 최솟값]
int t, n;

void makeDPtable()
{
    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[3][3] = 1;

    for (n=1; n<MAX_N; n++) {
        if (n-1 > 0) { // dp[n-1]의 경우에 +1이 되는 경우
            dp[n][1] = dp[n-1][1] + dp[n-1][2] + dp[n-1][3];
        } 
        if (n-2 > 0) { // dp[n-2]의 경우에 +2가 되는 경우
            dp[n][2] = dp[n-2][2] + dp[n-2][3];
        } 
        if (n-3 > 0) { // dp[n-3]의 경우에 +3이 되는 경우
            dp[n][3] = dp[n-3][3];
        }
    }
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    makeDPtable();

    cin >> t;
    while (t--) {
        cin >> n;
        cout << dp[n][1] + dp[n][2] + dp[n][3] << '\n';
    }
    return 0;
}