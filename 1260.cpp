#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_N = 1000 + 1;

int n, m, v, node1, node2;
vector<int> graph[MAX_N];
vector<bool> visitedDFS(MAX_N, false); // DFS 방문 확인
vector<bool> visitedBFS(MAX_N, false); // BFS 방문 확인


void DFS(int startNode)
{
    cout << startNode << ' ';
    for (int nxt : graph[startNode]) {
        if (!visitedDFS[nxt]) { // 아직 방문하지 않은 노드
            visitedDFS[nxt] = true; DFS(nxt);
        }
    }
}

void BFS(int startNode)
{
    queue<int> path; path.push(startNode);

    while (!path.empty()) {
        int curr = path.front(); path.pop();
        cout << curr << ' ';

        for (int nxt : graph[curr])
            if (!visitedBFS[nxt]) { // 아직 방문하지 않은 노드
                visitedBFS[nxt] = true; path.push(nxt);
            }
    }
    cout << '\n';
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    cin >> n >> m >> v;
    while (m--) {
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }
    for (int node=1; node<=n; node++)
        sort(graph[node].begin(), graph[node].end(), less<int>());

    visitedDFS[v] = true; DFS(v); cout << '\n';
    visitedBFS[v] = true; BFS(v);
    return 0;
}