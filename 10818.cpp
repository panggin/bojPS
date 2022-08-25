#include <iostream>
#include <climits>
using namespace std;

int n, num;
int minNum = 1000000, maxNum = -1000000;

int main()
{
    cin >> n;
    while (n--) {
        cin >> num;
        if (num < minNum) minNum = num;
        if (num > maxNum) maxNum = num;
    }
    cout << minNum << ' ' << maxNum << '\n';
    return 0;
}