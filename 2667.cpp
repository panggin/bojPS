#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>
#include <set>
using namespace std;

const int MAX_N = 25; // 최대 지도 크기
const int DIR_CNT = 4; // 이동 가능 방향 수

int n, i, j, groupNum = 2;
int di[DIR_CNT] = {-1,1,0,0}; // 행 이동 방향 지정
int dj[DIR_CNT] = {0,0,-1,1}; // 열 이동 방향 지정

int map[MAX_N][MAX_N] = {0,};
multiset<int> houses; // 단지 내 집 수 저장 테이블

int BFS(int row, int col, int tag)
{
    int houseCnt, currI, currJ, ni, nj;

    // 시작 노드 설정
    queue<pair<int,int>> nxtNodes; nxtNodes.push({row, col});
    map[row][col] = tag; houseCnt = 1;

    while (!nxtNodes.empty()) {
        // 현재 노드 가져오기 (큐에서 가장 앞에 있는 노드 가져오기)
        currI = nxtNodes.front().first;
        currJ = nxtNodes.front().second; nxtNodes.pop();

        for (int d=0; d<DIR_CNT; d++) {
            ni = currI + di[d]; nj = currJ + dj[d]; // 다음 노드 지정
            if (ni>=0 && ni<n && nj>=0 && nj<n && map[ni][nj]==1) {
                map[ni][nj] = tag; houseCnt++; // 다음 노드 방문 처리
                nxtNodes.push({ni, nj}); // 다음 노드 큐에 저장
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
            if (map[i][j] == 1) { // 단지 번호 부여 여부 확인
                int houseCnt = BFS(i,j, groupNum++);
                houses.insert(houseCnt);
            }
        }
    }

    cout << houses.size() << '\n';
    for (int houseCnt : houses) cout << houseCnt << '\n';
    return 0;
}