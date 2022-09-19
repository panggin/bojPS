#include <iostream>
#include <algorithm>
#include <climits>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

const int MAX_V = 10000+1;

int v, e, a, b, w, result = 0;
vector<pair<int,int>> graph[MAX_V]; // {가중치, 정점} 순으로 저장
vector<int> wtable; // 각 정점별 가중치 저장

int getMSTweights_prim()
{
    wtable = vector<int>(v+1, INT_MAX); // 가중치 정보 초기화
    vector<bool> visited(v+1, false); // 정점 방문 여부 확인
    
    priority_queue<pair<int,int>, vector<pair<int,int>>,
        greater<pair<int,int>>> pq;
    pq.push({0,1}); wtable[1] = 0; // 정점 1에서 출발

    while (!pq.empty()) {
        int currV = pq.top().second;
        int currW = pq.top().first;
        pq.pop();

        if (visited[currV]) continue; // 이미 방문한 정점 무시
        visited[currV] = true; result += currW;

        for (auto nxtP : graph[currV]) {
            int nxtV = nxtP.second; // 다음으로 접근 가능한 정점
            int newW = nxtP.first;
            if (visited[nxtV]) continue;

            wtable[nxtV] = min(wtable[nxtV], newW); // 가중치 업데이트
            pq.push({wtable[nxtV], nxtV});
        }
    }
    return result;
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> v >> e;
    while (e--) {
        cin >> a >> b >> w;
        graph[a].push_back({w,b});
        graph[b].push_back({w,a});
    }

    cout << getMSTweights_prim() << '\n';
    return 0;
}