#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>
using namespace std;

const int MAX_N = 1000 + 1; // 최대 도시 수 설정

int n, m, from, to, cost;
vector<pair<int,int>> graph[MAX_N];
vector<int> prevTable; // 이전 비용 테이블
vector<int> currTable; // 현재 비용 테이블

int bellmanFord(int from, int to)
{
    currTable[from] = 0; // 시작점 초기화

    for (int i=1; i<n; i++) {
        prevTable = vector<int>(currTable); // 이전 테이블 정보 복사

        for (int curr=1; curr<=n; curr++) { // (n-1)번 과정 반복
            if (prevTable[curr] == INT_MAX) continue;
            for (pair<int,int> bus : graph[curr]) {
                int addCost = bus.first; // 이동 비용
                int nxt = bus.second;    // 다음 목적지
                currTable[nxt] = min(currTable[nxt], prevTable[curr]+addCost);
            }
        }
    }
    return currTable[to];
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n >> m;
    currTable = vector<int>(n+1, INT_MAX);
    while (m--) {
        cin >> from >> to >> cost;
        graph[from].push_back({cost,to});
    } cin >> from >> to;

    cout << bellmanFord(from, to) << '\n';
    return 0;
}