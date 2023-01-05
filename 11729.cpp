#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int n, k=0;
vector<pair<int,int>> moveLog; // 원판 이동 과정 저장

// n번 원판을 start -> end로 이동
void move(int idx, int start, int end)
{
    // cout << idx << "번 원판 이동: ";
    // cout << start << ' ' << end << '\n'; // 이동 과정 출력
    moveLog.push_back({start, end}); // 이동 과정 저장
    k++; // 이동 횟수 추가
}

// n개의 원판을 start -> end로 원반 이동(이동 시 sub 활용)
void hanoi(int n, int start, int end, int sub)
{
    if (n == 1) {
        move(n, start, end);
        return;
    } else {
        hanoi(n-1, start, sub, end); // (n-1)개 원판 start->sub로 이동
        move(n, start, end); // 가장 아래 원판 이동
        hanoi(n-1, sub, end, start); // (n-1)게 원판 sub->end로 이동
    }
}

int main()
{
    cin >> n;
    hanoi(n,1,3,2);
    cout << k << '\n';
    for (auto log : moveLog)
        cout << log.first << ' ' << log.second << '\n';
    return 0;
}