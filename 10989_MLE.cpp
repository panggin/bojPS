// 1. vector와 sort 활용한 풀이 -> 메모리 초과
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, num;
vector<int> numVec;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n;
    while (n--) {
        cin >> num;
        numVec.push_back(num);
    }
    sort(numVec.begin(), numVec.end());
    
    for (int num : numVec) {
        cout << num << '\n';
    }
    return 0;
}

// // 2. multiset을 활용한 풀이 -> 메모리 초과
// #include <iostream>
// #include <set>
// using namespace std;

// int n, num;
// multiset<int> numVec;

// int main()
// {
//     ios::ios_base::sync_with_stdio(false);
//     std::cin.tie(0);

//     cin >> n;
//     while (n--) {
//         cin >> num;
//         numVec.insert(num);
//     }
    
//     for (int num : numVec) {
//         cout << num << '\n';
//     }
//     return 0;
// }