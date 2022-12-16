#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int lli;
lli k, n, length, maxLen=0;
vector<lli> lenVec;

lli searchLen(lli low, lli high) // 이분탐색 활용
{
    lli currN, mid;
    while (low+1 < high) { // low와 high가 1차이 날때까지 탐색
        currN = 0;
        mid = (low + high) / 2;

        for (lli len : lenVec) currN += len/mid;

        if (currN >= n) low = mid;
        else if (currN < n) high = mid;
    }
    currN = 0; for (lli len : lenVec) currN += len/high;
    if (currN >= n) return high; // 후보 중 큰 값 먼저 조건 확인
    return low; // 조건에 맞지 않을 시 작은 값 return
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> k >> n;
    while (k--) {
        cin >> length;
        lenVec.push_back(length);
        maxLen = max(maxLen, length);
    }
    cout << searchLen(0, maxLen);
    return 0;
}