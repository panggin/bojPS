#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string word, pattern;
vector<int> ptable; // 패턴 일치 테이블
int k=0, i=0, ti=0, pi=0, tn, pn;

// Step 1. 패턴 접두사, 접미사 일치 테이블 생성
void setTable(string pattern)
{
    pn = pattern.size();
    ptable = vector<int>(pn, 0);
    if (pn == 1) return;

    for (i=1; i<pn; i++) {
        while (k>0 && pattern[k]!=pattern[i]) k = ptable[k-1]; // 불일치
        if (pattern[k] == pattern[i]) ptable[i] = ++k; // 일치
    }
}

// Step 2. 패턴 찾기 -> 패턴이 존재하는지 확인
int KMP(string target, string pattern)
{
    setTable(pattern); tn = target.size();
    for (ti=0; ti<tn; ti++) {
        while (pi > 0 && target[ti] != pattern[pi]) // 불일치
            pi = ptable[pi-1];
        if (pi == pn-1) return 1; // 패턴 찾기 완료
        else pi++; // 일치
    }
    return 0;
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> word >> pattern;
    cout << KMP(word, pattern) << '\n';
    return 0;
}