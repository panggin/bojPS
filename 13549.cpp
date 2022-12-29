#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX_N = 100000;

int n, k;
vector<int> minTime(MAX_N+1, -1); // 위치별 최소 이동 시간

int calcMinTime(int &n, int &k)
{
    int pos, time;
    queue<pair<int,int>> path; // 현재 위치, 이동 시간 저장
    path.push({n,0}); // 시작점 설정
    
    while (!path.empty()) {
        pos = path.front().first; // 현재 위치
        time = path.front().second; // 이동 시간
        path.pop();

        if (minTime[pos]!=-1 && minTime[pos]<=time) continue;
        minTime[pos] = time; // 현재 위치의 최소 이동 시간 업데이트
        // cout << "update minTime (pos, time): " 
        //      << pos << ", " << minTime[pos] << '\n'; // debugging

        if (pos*2 >= 0 && pos*2 <= MAX_N) path.push({pos*2, time});
        if (pos-1 >= 0 && pos-1 <= MAX_N) path.push({pos-1, time+1});
        if (pos+1 >= 0 && pos+1 <= MAX_N) path.push({pos+1, time+1});
    }
    return minTime[k];
}

int main()
{
    cin >> n >> k;
    cout << calcMinTime(n,k);
    return 0;
}