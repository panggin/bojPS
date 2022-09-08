#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, s, num, sum = 0, result;
vector<int> numArr;
vector<int>::iterator startIter, endIter, numArrEnd;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n >> s; result = n+1;
    for (int i=0; i<n; i++) {
        cin >> num; numArr.push_back(num);
    } numArr.push_back(0); // 부분합 계산 단순화를 위함

    startIter = numArr.begin(); endIter = startIter;
    numArrEnd = numArr.end()-1; sum = *startIter;
    
    while (endIter != numArrEnd) {
        if (sum < s) { // Case 1. 부분합이 주어진 값보다 작을 경우
            sum += *(++endIter);
        } else {       // Case 2. 부분합이 주어진 값 이상일 경우
            result = min(result, (int)(endIter - startIter + 1));
            sum -= *(startIter++);
        }
        if (startIter > endIter) endIter = startIter;
    }

    if (result == n+1) result = 0; // 부분합 S 만들기 불가능
    cout << result << '\n';
    return 0;
}