#include <iostream>
#include <algorithm>
#include <climits>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N = 1000 + 1; // 최대 도시 수 설정

int n, m, from, to, cost;
vector<pair<int,int>> graph[MAX_N]; // 도시별 버스 노선 - {비용,목적지}
vector<int> minCost(MAX_N, INT_MAX);// 도시별 최소 비용

int dijkstra(int from, int to)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, 
                greater<pair<int,int>>> pq; // 우선순위 큐 초기화
    
    pq.push({0,from}); // 비용을 우선순위로 사용
    minCost[from] = 0;

    while (!pq.empty()) {
        int curr_city = pq.top().second;
        int curr_cost = pq.top().first;
        pq.pop();

        // 이미 최소 비용을 알고 있는 경우 무시
        if (minCost[curr_city] < curr_cost) continue;

        for (auto nxt : graph[curr_city]) { // 이동 가능한 도시 확인
            int nxt_city = nxt.second;
            int nxt_cost = curr_cost + nxt.first;
            // 최소 비용이 업데이트될 경우 우선순위 큐에 해당 경로 저장
            if (nxt_cost < minCost[nxt_city]) {
                minCost[nxt_city] = nxt_cost; // 최소 비용 업데이트
                pq.push({nxt_cost, nxt_city}); // 우선순위 큐에 경로 저장
            }
        }
    }
    return minCost[to];
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n >> m;
    while (m--) {
        cin >> from >> to >> cost;
        graph[from].push_back({cost,to});
    } cin >> from >> to;

    cout << dijkstra(from, to) << '\n';
    return 0;
}