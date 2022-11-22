#include <iostream>
#include <map>
using namespace std;

const int MAP_LIMIT = 100;

int n, m, i, j, counts=0;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

char battleground[MAP_LIMIT][MAP_LIMIT]; // 전쟁터 병사 분포
map<char, int> power; // 병력 합 (W : 아군, B : 적군)


void DFS(int x, int y, char color)
{
    int k, nx, ny;

    for (k=0; k<4; k++) {
        nx = x + dx[k]; ny = y + dy[k]; // 다음으로 이동할 위치
        if (nx>=0 && nx<m && ny>=0 && ny<n
                && battleground[nx][ny] == color) {
            counts += 1; // 병사 수 카운팅
            battleground[nx][ny] = 'a'; // 다음 위치 방문 처리
            DFS(nx, ny, color); // 해당 위치에서 재탐색 진행
        }
    }

}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n >> m;
    for (i=0; i<m; i++) 
        for (j=0; j<n; j++) cin >> battleground[i][j];
    power['W'] = 0; power['B'] = 0; // 각각의 병력 초기화

    for (i=0; i<m; i++) {
        for (j=0; j<n; j++) {
            char curr = battleground[i][j];
            if (curr == 'W' || curr == 'B') {
                battleground[i][j] = 'A'; counts = 1; // 탐색 전 초기화
                DFS(i,j,curr); // 탐색 진행
                power[curr] += counts * counts; // 병력 합 계산
            }
        }
    }
    cout << power['W'] << ' ' << power['B'];
    return 0;
}