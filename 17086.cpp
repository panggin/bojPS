#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

typedef struct {
    int x;
    int y;
    int l; // 안전거리
} PosInfo;

const int MAX_NM = 50;
const int DIR_CNT = 8;

vector<vector<int>> map(MAX_NM, vector<int>(MAX_NM, 0));
int n, m, i, j, k, maxLen=0;
int dx[DIR_CNT] = {-1,-1,-1, 0,0, 1,1,1};
int dy[DIR_CNT] = {-1, 0, 1,-1,1,-1,0,1};

int BFS(int startX, int startY)
{
    int nx, ny, len=INT_MAX;
    vector<vector<int>> nmap = map;
    queue<PosInfo> posQ;

    posQ.push({startX, startY, 0});
    nmap[startX][startY] = 2;

    while (!posQ.empty()) {
        PosInfo curr = posQ.front();
        posQ.pop();

        for (k=0; k<DIR_CNT; k++) { // 인접한 8방향 이동
            nx = curr.x + dx[k];
            ny = curr.y + dy[k];
            if (nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if (nmap[nx][ny] == 2) continue;

            if (nmap[nx][ny] == 1) { // 가장 가까운 상어 거리 계산
                len = min(len, curr.l + 1); 
            } else {
                nmap[nx][ny] = 2;
                posQ.push({nx,ny,curr.l+1});
            }
        }
    }
    // cout << "len : " << len << '\n';
    return len;  
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n >> m;
    for (i=0; i<n; i++)
        for (j=0; j<m; j++)
            cin >> map[i][j];

    for (i=0; i<n; i++) {
        for (j=0; j<m; j++) {
            if (map[i][j] == 0) // 최대 안전거리 계산
                maxLen = max(maxLen, BFS(i,j));
        }
    }
    cout << maxLen;
    return 0;
}