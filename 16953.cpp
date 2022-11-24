#include <iostream>
using namespace std;

int a, b;

int getCalcCnt(int a, int b)
{
    int calcCnt = 0; // 연산 횟수

    while (a < b) {
        if (b % 2 == 0) { // 2를 곱한 경우
            b /= 2; calcCnt++;
        } else if (b % 10 == 1) { // 가장 오른쪽에 1 추가한 경우
            b = (b-1) / 10; calcCnt++;
        } else break;
    }

    if (a == b) return calcCnt + 1;
    return -1;
}

int main()
{
    cin >> a >> b;
    cout << getCalcCnt(a,b);
    return 0;
}