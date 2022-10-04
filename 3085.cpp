#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_N = 50;

int n, i, j; char color;
vector<char> map[MAX_N];

int countColor(int n)
{
    int r, c, start, result=0; char sample;

    // 각 행에서 연속된 색상 개수 계산
    for (r=0; r<n; r++) {
        start=0; sample = map[r][0]; // 연속 시작점 및 해당 색깔 설정
        for (c=1; c<n; c++) {
            if (sample != map[r][c]) { // 연속 X
                result = max(result, c-start); 
                start = c; sample = map[r][c]; // 연속 시작점 및 색깔 리셋
            }
        } result = max(result, c-start);
    }

    // 각 열에서 연속된 색상 개수 계산
    for (c=0; c<n; c++) {
        start=0; sample = map[0][c]; // 연속 시작점 및 해당 색깔 설정
        for (r=1; r<n; r++) {
            if (sample != map[r][c]) { // 연속 X
                result = max(result, r-start);
                start = r; sample = map[r][c]; // 연속 시작점 및 색깔 리셋
            }
        } result = max(result, r-start);
    }

    return result;
}

int findMaxCounts(int n)
{
    int result = 0;
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            if (i+1 < n) {
                swap(map[i][j], map[i+1][j]); // 아래쪽 요소와 swap
                result = max(result, countColor(n));
                swap(map[i][j], map[i+1][j]); // swap 되돌리기
            }
            if (j+1 < n) {
                swap(map[i][j], map[i][j+1]); // 오른쪽 요소와 swap
                result = max(result, countColor(n));
                swap(map[i][j], map[i][j+1]); // swap 되돌리기    
            }
        }
    }
    return result;
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n;
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            cin >> color;
            map[i].push_back(color);
        }
    }
    cout << findMaxCounts(n);
    return 0;
}