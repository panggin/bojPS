#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

typedef unsigned long long ull;

const int MAX_N = 1022; // 최대 감소하는 수 개수
const int NUM_SIZE = 10; // 사용 가능한 숫자 개수 (0 ~ 9)

int n, total, place = 2;
vector<char> num = {'0','1','2','3','4','5','6','7','8','9'};
vector<ull> decNum; // 감소하는 수 저장 배열


void setAllDecNum()
{
    for (int p=2; p<=NUM_SIZE; p++) { // 감소하는 수 자릿수 설정
        vector<bool> selected(10,false);
        fill(selected.begin(), selected.begin()+p, true);
        
        do { // 자릿수만큼 숫자 선택 -> 감소하는 수 생성
            string newNum = ""; // 초기화
            
            for (int i=0; i<NUM_SIZE; i++) // 선택된 숫자로 감소하는 수 생성
                if (selected[i]) newNum = num[i] + newNum;
            
            decNum.push_back(stoull(newNum));
        } while (prev_permutation(selected.begin(), selected.end()));
    }
    sort(decNum.begin(), decNum.end()); // 배열 오름차순 정렬
}

int main()
{    
    cin >> n;

    if (n > MAX_N) { // 가능한 감소하는 수 개수 초과
        cout << -1; return 0;
    } 
    if (n < 10) { // N이 한 자리 수일 경우 N 그대로 출력
        cout << n; return 0;
    }

    setAllDecNum(); // 모든 감소하는 수 구하기
    cout << decNum[n-10]; return 0;
}