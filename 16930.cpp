#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

const int DIR = 4;
const int MAX_NM = 1000 + 1;

typedef struct {
    int x; // row
    int y; // column
    int t; // time
} Pos;

char tmp;
int n, m, k, i, j; 
int X1, Y1, X2, Y2;
int dx[DIR] = {0,-1,0,1};
int dy[DIR] = {-1,0,1,0};

// 최소 이동 시간 기록(벽:-1, 방문X:INT_MAX)
int map[MAX_NM][MAX_NM] = {0,}; 

void printMap()
{
    for (i=1; i<=n; i++) {
        for (j=1; j<=m; j++) {
            cout << map[i][j] << ' ';
        } cout << '\n';
    } cout << '\n';
}

void BFS(int startX, int startY)
{
    int dis, dir, nx, ny;
    Pos curr;

    queue<Pos> posQ;
    posQ.push({startX, startY, 0});
    map[startX][startY] = 0;
    
    while (!posQ.empty()) {
        curr = posQ.front();
        posQ.pop();


        for (dir=0; dir<DIR; dir++) { // 4방향으로 이동
            for (dis=1; dis<=k; dis++) { // 1~k칸 이동
                nx = curr.x + dx[dir]*dis;
                ny = curr.y + dy[dir]*dis;

                if (nx<1 || nx>n || ny<1 || ny>m 
                    || map[nx][ny] == -1 
                    || map[nx][ny] < curr.t+1) break;

                if (map[nx][ny] == INT_MAX) {
                    map[nx][ny] = curr.t+1;
                    posQ.push({nx,ny,curr.t+1});
                }
                // printMap();
            }
        }
    } 
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n >> m >> k;
    for (i=1; i<=n; i++) {
        for (j=1; j<=m; j++) {
            cin >> tmp;
            if (tmp == '.') map[i][j] = INT_MAX;
            else map[i][j] = -1;
        }
    }
    cin >> X1 >> Y1 >> X2 >> Y2;

    BFS(X1, Y1);
    // printMap();

    if (map[X2][Y2] == INT_MAX) cout << -1;
    else cout << map[X2][Y2];
    return 0;
}