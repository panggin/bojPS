#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int const MAX_CNT = 10000 + 1; // 최대 사용 가능 개수

int n, k, coin, coinCnt;
vector<int> coins; // 동전 가치 저장 배열
vector<int> dp; // 최소 동전 사용 개수 저장 배열

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n >> k;
    dp = vector<int>(k+1, MAX_CNT); // DP 테이블 초기화
    while (n--) {
        cin >> coin;
        coins.push_back(coin);
    }

    dp[0] = 0;
    for (int coin : coins) {
        for (int currK=1; currK<=k; currK++) {
            if (currK - coin >= 0) { // DP 테이블 활용
                dp[currK] = min(dp[currK], dp[currK-coin] + 1);
            }
        }
    }
    if (dp[k] == MAX_CNT) dp[k] = -1;
    cout << dp[k];
    return 0;
}