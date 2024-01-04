#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int MAX_N = 50;
const int MAX_M = 1000;

int n, s, m, i, nxtV1, nxtV2;
vector<int> v(MAX_N, 0); // 단계별 볼륨 조절량
set<int> currVol; // 현재 단계 볼륨
set<int> nxtVol; // 다음 단계 볼륨

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n >> s >> m;
    for (i=0; i<n; i++) {
        cin >> v[i];
    }

    nxtVol.insert(s);
    for (i=0; i<n; i++) {
        currVol = set<int>(nxtVol);
        nxtVol.clear();

        for (int curr : currVol) {
            nxtV1 = curr + v[i];
            nxtV2 = curr - v[i];
            if (nxtV1>=0 && nxtV1<=m) nxtVol.insert(nxtV1);
            if (nxtV2>=0 && nxtV2<=m) nxtVol.insert(nxtV2);
        }
    }

    if (nxtVol.empty()) {
        cout << -1;
    } else { // 오름차순 정렬이므로 마지막 값 가져옴
        cout << *nxtVol.rbegin();
    }
    return 0;
}