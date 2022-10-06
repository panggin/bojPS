#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k, coin;
vector<int> coins; // 동전 가치 저장 배열
vector<int> dp; // 가치 합 경우의 수 저장 배열

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n >> k;
    dp = vector<int>(k+1, 0); // DP 테이블 초기화
    while (n--) {
        cin >> coin;
        coins.push_back(coin);
    }

    dp[0] = 1;
    for (int coin : coins) {
        for (int currK=1; currK<=k; currK++) {
            if (currK - coin >= 0) // DP 테이블 활용
                dp[currK] += dp[currK-coin];
        }
    }
    cout << dp[k];
    return 0;
}