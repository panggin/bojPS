// 1 ~ 10,000 숫자 개수를 vector를 활용하여 카운팅
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 10000 + 1;
int n, num, currCnt;
vector<int> numCnts(MAX_N, 0); // index: key

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n;
    while (n--) {
        cin >> num;
        numCnts[num]++;
    }
    
    for (num=1; num<MAX_N; num++) {
        currCnt = numCnts[num];
        while (currCnt--) cout << num << '\n';
    }
    return 0;
}
