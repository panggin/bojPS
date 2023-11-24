#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TP {
    int time; // 상담일수
    int pay;  // 수익
};

const int MAX_N = 1500000 + 2;
vector<TP> tpTable(MAX_N, {0,0}); // 상담테이블
vector<int> dp(MAX_N, 0); // 최대 수익 DP

int i, n, t, p, nxtI;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n;
    for(i=1; i<=n; i++) {
        cin >> t >> p;
        tpTable[i].time = t;
        tpTable[i].pay = p;
    }

    for (i=1; i<=n; i++) {
        nxtI = i + tpTable[i].time;
        dp[i] = max(dp[i-1], dp[i]);
        if (nxtI <= n+1) {
            dp[nxtI] = max(dp[nxtI], dp[i] + tpTable[i].pay);
        }
    }

    cout << max(dp[n], dp[n+1]);
    return 0;
}
