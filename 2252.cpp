#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N = 32000 + 1;

int n, m, s1, s2, node;
vector<int> graph[MAX_N]; // 인접 리스트 활용한 그래프
vector<int> indegree; // 노드별 진입차수
queue<int> order; // 정렬을 위한 큐

void topology() // 위상 정렬
{
    for (node=1; node<=n; node++) { // 초기 설정
        if (indegree[node] == 0) order.push(node);
    }
    while (!order.empty()) {
        node = order.front(); order.pop();
        cout << node << ' '; // 순서 출력

        for (int nxt : graph[node]) {
            indegree[nxt] -= 1;
            if (indegree[nxt] == 0) order.push(nxt);
        }
    }
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n >> m;
    indegree = vector<int>(n+1, 0);
    while (m--) {
        cin >> s1 >> s2;
        graph[s1].push_back(s2);
        indegree[s2] += 1;
    }

    topology(); return 0;
}