#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 16 + 1;

int n;
int graph[MAX_N][MAX_N] = {0,};
int dp[3][MAX_N][MAX_N] = {0,}; // 각 방향별로 dp 준비 (가로, 세로, 대각선)


int movPipeCases(int startR, int startC, int state)
{
    dp[state][startR][startC] = 1; // 처음 파이프 위치 설정

    for (int r=1; r<=n; r++) {
        for (int c=1; c<=n; c++) {
            if (graph[r][c] == 1) continue; // 벽으로 막힌 공간

            int nr = r+1, nc = c+1; // 다음으로 이동할 좌표

            if (nc <= n && !graph[r][nc]) { // 가로로 이동 가능
                dp[0][r][nc] += dp[0][r][c]; // 가로 -> 가로
                dp[0][r][nc] += dp[2][r][c]; // 대각선 -> 가로
            }
            if (nr <= n && !graph[nr][c]) { // 세로로 이동 가능
                dp[1][nr][c] += dp[1][r][c]; // 세로 -> 세로
                dp[1][nr][c] += dp[2][r][c]; // 대각선 -> 세로
            }
            if (nr <= n && nc <= n && !graph[nr][c] 
                && !graph[r][nc] && !graph[nr][nc]) { // 대각선으로 이동 가능
                dp[2][nr][nc] += dp[0][r][c]; // 가로 -> 대각선
                dp[2][nr][nc] += dp[1][r][c]; // 세로 -> 대각선
                dp[2][nr][nc] += dp[2][r][c]; // 대각선 -> 대각선
            }
        } 
    }
    return dp[0][n][n] + dp[1][n][n] + dp[2][n][n]; // 이동 방법 총합
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n;
    for (int r=1; r<=n; r++)
        for (int c=1; c<=n; c++)
            cin >> graph[r][c];

    cout << movPipeCases(1,2,0);
    return 0;
}