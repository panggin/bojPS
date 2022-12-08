#include <iostream>
#include <climits>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

const int MAX_POS = 100000;

int n, k;
vector<int> visited(MAX_POS, INT_MAX); // 각 위치별로 최단 시간 저장


pair<int,int> searchPath(int startPos, int endPos)
{
    int minTime = INT_MAX, pathCnt = 0;
    int currPos, currTime;

    queue<pair<int,int>> path; // {현재위치, 걸린시간} 순으로 저장
    path.push({startPos, 0});

    while (!path.empty()) {
        currPos = path.front().first;
        currTime = path.front().second;
        path.pop();

        if (currPos == endPos) {
            if (currTime == minTime) pathCnt++; // 최단 시간 동일 -> 경우의 수 증가
            else if (currTime < minTime) { // 최단 시간 업데이트
                minTime = currTime; pathCnt = 1;
            }
        }

        if (currTime <= visited[currPos]) { // 경로 찾기
            visited[currPos] = currTime;
            if (currPos-1 >= 0) path.push({currPos-1, currTime+1});
            if (currPos+1 <= MAX_POS) path.push({currPos+1, currTime+1});
            if (currPos*2 <= MAX_POS) path.push({currPos*2, currTime+1});
        }
    }
    return {minTime, pathCnt};
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n >> k;
    pair<int,int> result = searchPath(n,k);
    cout << result.first << '\n' << result.second;
    return 0;
}