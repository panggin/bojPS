#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

const short MAX_NM = 100 + 1;

short graph[MAX_NM][MAX_NM] = {0,};
short n, m, k, i, j, maxSize=0;
short dx[4] = {1, -1, 0, 0};
short dy[4] = {0, 0, 1, -1};


void BFS(short x, short y)
{
    short d, currX, currY, nxtX, nxtY, currSize=0;

    queue<pair<short,short>> path;
    path.push({x,y}); graph[x][y] = 2; // 시작점 설정

    while (!path.empty()) {
        currX = path.front().first; // 현재 노드
        currY = path.front().second; 
        path.pop(); currSize += 1; // 크기 1 증가

        for (d=0; d<4; d++) {
            nxtX = currX + dx[d]; // 다음 노드
            nxtY = currY + dy[d];

            if (nxtX>0 && nxtX<=n && nxtY>0 && nxtY<=m 
                && graph[nxtX][nxtY] == 1) {
                    graph[nxtX][nxtY] = 2; // 다음 노드 방문 처리
                    path.push({nxtX, nxtY}); // 다음 경로 추가
            }
        }
    }
    maxSize = max(maxSize, currSize); // 최대 크기 업데이트
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n >> m >> k;
    while (k--) {
        cin >> i >> j;
        graph[i][j] = 1; // 음식물 위치 1로 표시
    }
    for (i=1; i<=n; i++) {
        for (j=1; j<=m; j++) {
            if (graph[i][j] == 1) BFS(i,j);    
        }
    }
    cout << maxSize;
    return 0;
}