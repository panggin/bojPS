#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

int n, k, i, curr, priority, result = 0;
deque<int> usageState[101];  // 전기용품 별 사용 횟수
vector<int> order;           // 사용순서
vector<int> multitap;        // 멀티탭 사용 현황

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n >> k;
    multitap = vector<int>(n,0);
    for (i=0; i<k; i++) {
        cin >> curr; 
        order.push_back(curr);
        usageState[curr].push_back(i);
    }

    for (i=0; i<k; i++) {
        curr = order[i]; priority = 3; // priority : 0~2 할당
        vector<int>::iterator targetIter = multitap.begin();

        for (auto iter=multitap.begin(); iter<multitap.end(); iter++) {
            // Case 1. 남은 자리있음 혹은 이미 사용중 -> priority 0
            if (*iter == 0 || *iter == curr) {
                priority = 0; targetIter = iter; break;
            }
            // Case 2. 앞으로 사용하지 않을 전기용품 제거 후 사용 -> priority 1
            else if (priority > 0 && usageState[*iter].empty()) {
                priority = 1; targetIter = iter;
            }
            // Case 3. 가장 나중에 사용될 전기용품 제거 후 사용 -> priority 2
            else if (priority > 1 &&
                (usageState[*iter].front() > usageState[*targetIter].front())) {
                priority = 2; targetIter = iter;
            }
        }
        *targetIter = curr; usageState[curr].pop_front();
        if (priority) result += 1;
    }
    cout << result << '\n';
    return 0;
}