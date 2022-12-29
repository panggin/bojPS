#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_N = 100000;

struct Info {
    int curr; // 현재 위치
    int prev; // 이전 위치
    int time; // 이동 시간
};

int n, k;
vector<int> minTime(MAX_N+1, -1); // 위치별 최소 이동 시간
vector<int> prevPos(MAX_N+1, -1); // 위치별 이동 전 위치
vector<int> path; // 최소 시간일 때의 이동 경로

void getMinTimeAndPath(int &n, int &k)
{
    int curr, prev, time;
    queue<Info> log;
    log.push({n,-1,0}); // 시작점 설정
    
    // 최소 이동 시간 계산
    while (!log.empty()) {
        curr = log.front().curr;
        prev = log.front().prev;
        time = log.front().time;
        log.pop();

        if (minTime[curr]!=-1 && minTime[curr]<=time) continue;
        minTime[curr] = time; // 최소 이동 시간 업데이트
        prevPos[curr] = prev; // 이전 위치 업데이트

        if (curr-1 >= 0 && curr-1 <= MAX_N) 
            log.push({curr-1, curr, time+1});
        if (curr+1 >= 0 && curr+1 <= MAX_N)
            log.push({curr+1, curr, time+1});
        if (curr*2 >= 0 && curr*2 <= MAX_N)
            log.push({curr*2, curr, time+1});
    }

    // 이동 경로 계산
    path.push_back(k);
    while (path.back() != n)
        path.push_back(prevPos[path.back()]);

    // 최소 이동 시간 및 이동 경로 출력
    cout << minTime[k] << '\n';
    for (auto iter=path.rbegin(); iter!=path.rend(); iter++)
        cout << *iter << ' ';
}

int main()
{
    cin >> n >> k;
    getMinTimeAndPath(n,k);
    return 0;
}