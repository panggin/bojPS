#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int ARRAY_SIZE = 10;
const int MAX_N_INDEX = 3-1;

int T, inputNum;
vector<int> numArr;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> T;
    while (T--) {
        vector<int> numArr(ARRAY_SIZE, 0);
        for (int &num : numArr) {
            cin >> inputNum;
            num = inputNum;
        }
        sort(numArr.begin(), numArr.end(), greater<int>());
        cout << numArr[MAX_N_INDEX] << '\n';
    }
    return 0;
}