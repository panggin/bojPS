#include <iostream>
using namespace std;

int n, num, result = 0;

bool isPrimeNumber(int num)
{
    int divider = num;
    while (--divider > 1) {
        if (!(num % divider)) return false;
    }
    return true;
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    cin >> n;
    while (n--) {
        cin >> num;
        if (num == 1) continue;
        if (isPrimeNumber(num)) result += 1;
    }
    cout << result << '\n';
    return 0;
}