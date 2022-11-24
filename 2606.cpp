#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_N = 100 + 1;

int n, edges, node1, node2;
vector<int> graph[MAX_N]; // 컴퓨터 연결 상황 그래프
vector<bool> visited(MAX_N, false); // 방문 여부 확인


int countInfected()
{
    int curr, result = 0;

    queue<int> path; path.push(1); 
    visited[1] = true; // 1번 컴퓨터에서 시작

    while (!path.empty()) {
        curr = path.front(); path.pop();
        result += 1; // 감염된 컴퓨터 수 증가
        for (int nxt : graph[curr]) {
            if (visited[nxt]) continue;
            path.push(nxt); visited[nxt] = true;
        }
    }
    return result-1; // 1번 컴퓨터 제외
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n >> edges;
    while (edges--) {
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }
    cout << countInfected();
    return 0;
}