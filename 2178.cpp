#include <iostream>
#include <queue>
#include <utility>
using namespace std;

const short MAX_NM = 100 + 1;

short maze[MAX_NM][MAX_NM];
short n, m, i, j;
short dx[4] = {1, -1, 0, 0};
short dy[4] = {0, 0, 1, -1};


void BFS(int x, int y)
{
    short k, currX, currY, nxtX, nxtY;

    queue<pair<short,short>> path;
    path.push({x,y}); maze[x][y] = 1; // 시작점 설정

    while (!path.empty()) {
        currX = path.front().first; // 현재 위치
        currY = path.front().second; path.pop();

        for (k=0; k<4; k++) {
            nxtX = currX + dx[k]; // 이동할 위치
            nxtY = currY + dy[k];
            if (nxtX>0 && nxtX<=n && nxtY>0 && nxtY<=m
                && maze[nxtX][nxtY] == -1) { // 아직 방문하지 않은 노드
                    maze[nxtX][nxtY] = maze[currX][currY] + 1;
                    path.push({nxtX, nxtY}); // 다음 경로에 추가
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (i=1; i<=n; i++) {
        for (j=1; j<=m; j++) {
            scanf("%1hd", &maze[i][j]);
            maze[i][j] *= -1; // 이동 가능한 칸을 -1로 표시
        }
    }
    BFS(1,1); // 경로 탐색 진행
    cout << maze[n][m];
    return 0;
}