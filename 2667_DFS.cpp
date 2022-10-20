#include <iostream>
#include <cstdio>
#include <stack>
#include <utility>
#include <set>
using namespace std;

const int MAX_N = 25; // 최대 지도 크기
const int DIR_CNT = 4; // 이동 가능 방향 수

int n, i, j, groupNum = 2;
int dr[DIR_CNT] = {-1,1,0,0}; // 행 이동 방향 지정
int dc[DIR_CNT] = {0,0,-1,1}; // 열 이동 방향 지정

int map[MAX_N][MAX_N] = {0,};
multiset<int> houses; // 단지 내 집 수 저장 테이블

// 재귀함수를 활용한 DFS 함수
int DFS_recursive(int row, int col, int tag, int houseCnt)
{
    map[row][col] = tag; houseCnt++; // 현재 노드 방문 처리

    for (int dir=0; dir<DIR_CNT; dir++) { // 상하좌우 노드 확인
        int nr = row + dr[dir], nc = col + dc[dir];
        if (nr>=0 && nr<n && nc>=0 && nc<n && map[nr][nc]==1) {
            houseCnt = DFS_recursive(nr, nc, tag, houseCnt); // 다음 노드로 이동
        }
    }
    return houseCnt;
}

// 스택을 활용한 DFS 함수
int DFS_stack(int row, int col, int tag)
{
    int houseCnt, currR, currC, nr, nc, dir;

    // 시작 노드 설정
    stack<pair<int,int>> nxtNodes; nxtNodes.push({row, col});
    map[row][col] = tag; houseCnt = 1;

    while (!nxtNodes.empty()) {
        // 현재 노드 가져오기 (스택의 top 노드 가져오기)
        currR = nxtNodes.top().first;
        currC = nxtNodes.top().second; nxtNodes.pop();

        for (dir=0; dir<DIR_CNT; dir++) { // 상하좌우 노드 확인
            nr = currR + dr[dir]; nc = currC + dc[dir];
            if (nr>=0 && nr<n && nc>=0 && nc<n && map[nr][nc]==1) {
                map[nr][nc] = tag; houseCnt++; // 다음 노드 방문 처리
                nxtNodes.push({nr, nc}); // 다음 노드 스택에 저장
            }
        }
    }
    return houseCnt;
}

int main()
{
    cin >> n;
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) { scanf("%1d", &map[i][j]); }
    }

    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            if (map[i][j] == 1) {
                int houseCnt = DFS_recursive(i,j, groupNum++, 0); // 재귀함수 DFS
                // int houseCnt = DFS_stack(i,j, groupNum++); // 스택 DFS
                houses.insert(houseCnt);
            }
        }
    }

    cout << houses.size() << '\n';
    for (int houseCnt : houses) cout << houseCnt << '\n';
    return 0;
}