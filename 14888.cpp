#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int n;
int addCnt, subCnt, mulCnt, divCnt;
int calcMin = INT_MAX, calcMax = INT_MIN;
vector<int> numArr(11,0);


void calcSimulate(int add, int sub, int mul, int div, 
                int numIdx, int calcResult)
{
    if (add > 0) calcSimulate(add-1, sub, mul, div, 
                    numIdx+1, calcResult + numArr[numIdx]);
    if (sub > 0) calcSimulate(add, sub-1, mul, div, 
                    numIdx+1, calcResult - numArr[numIdx]);
    if (mul > 0) calcSimulate(add, sub, mul-1, div, 
                    numIdx+1, calcResult * numArr[numIdx]);
    if (div > 0) calcSimulate(add, sub, mul, div-1, 
                    numIdx+1, calcResult / numArr[numIdx]);
    if (numIdx >= n) {
        calcMax = max(calcMax, calcResult);
        calcMin = min(calcMin, calcResult);
    }
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    cin >> n;
    for (int i=0; i<n; i++) cin >> numArr[i];
    cin >> addCnt >> subCnt >> mulCnt >> divCnt;

    calcSimulate(addCnt, subCnt, mulCnt, divCnt, 1, numArr[0]);
    cout << calcMax << '\n' << calcMin << '\n';
    return 0;
}