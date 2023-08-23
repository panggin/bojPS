#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

typedef struct {
    int cnt; // 현재 이모티콘 개수
    int cb; // 클립보드에 저장된 개수
    int t; // 걸린 시간
} EmoInfo;

const int MAX_S = 1000;

int s, i, nxtCnt, minTime=INT_MAX;
int timeTable[MAX_S+1][MAX_S+1] = {0,};
queue<EmoInfo> emoQ;
EmoInfo curr;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> s;
    emoQ.push({1,0,0}); // 초기 이모티콘 상태 설정
    while (!emoQ.empty()) {
        curr = emoQ.front();
        emoQ.pop();
        // cout << curr.cnt << ' ' << curr.cb << ' ' << curr.t << '\n' ;
        
        // case 1. 이모티콘 복사 (+1s)
        nxtCnt = curr.cnt;
        if (nxtCnt>0 && nxtCnt<=MAX_S && !timeTable[nxtCnt][curr.cnt]) {
            timeTable[nxtCnt][curr.cnt] = curr.t+1;
            emoQ.push({nxtCnt, curr.cnt, curr.t+1});
        }
        // case 2. 클립보드 이모티콘 존재 O -> 복사 (+1s)
        nxtCnt = curr.cnt + curr.cb;
        if (nxtCnt!=curr.cnt && nxtCnt>1 && nxtCnt<=MAX_S
                && !timeTable[nxtCnt][curr.cb]) {
            timeTable[nxtCnt][curr.cb] = curr.t+1;
            emoQ.push({nxtCnt, curr.cb, curr.t+1});
        }
        // case 3. 이모티콘 1개 삭제 (+1s)
        nxtCnt = curr.cnt - 1;
        if (nxtCnt>1 && !timeTable[nxtCnt][curr.cb]) {
            timeTable[nxtCnt][curr.cb] = curr.t+1;
            emoQ.push({nxtCnt, curr.cb, curr.t+1});
        }
    }

    for (i=1; i<=MAX_S; i++)
        if (timeTable[s][i] != 0) 
            minTime = min(minTime, timeTable[s][i]);
    cout << minTime;
    return 0;
}