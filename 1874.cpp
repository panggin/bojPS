#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

int n, num, stackTop=0, pushNxt=1;
bool isUnable = false; // 연산 가능 여부 확인
stack<int> numStack;
vector<char> calcLog; // 연산 과정 저장

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> num;
        // cout << "curr state : " << num << ' ' << stackTop << ' ' << pushNxt << '\n'; // debugging
        if (num < pushNxt && num != stackTop) isUnable = true;
        if (isUnable) continue; // 연산 불가능

        while (num >= pushNxt) { // 해당 숫자까지 push 진행하여 top으로 만들기
            // cout << "push " << pushNxt << '\n'; // debugging
            stackTop = pushNxt; // 스택 top 업데이트
            numStack.push(pushNxt++);
            calcLog.push_back('+');
        }
        // cout << "after push : " << num << ' ' << stackTop << ' ' << pushNxt << '\n'; // debugging     
        if (!numStack.empty() && num == stackTop) { // 스택의 top을 pop하여 수열 만들기
            // cout << "pop " << stackTop << '\n'; // debugging
            numStack.pop();
            calcLog.push_back('-');
        }
        if (!numStack.empty()) stackTop = numStack.top(); // 스택 top 업데이트
        else stackTop = 0; // 빈 스택의 경우 top 0으로 설정
    }

    if (isUnable) { cout << "NO"; return 0; }
    for (char log : calcLog) cout << log << '\n';
    return 0;
}