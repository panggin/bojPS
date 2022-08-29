#include <iostream>
using namespace std;

int m, n;
int primeSum = 0, primeMin = -1;

bool isPrimeNumber(int num)
{
    int divider = 2;
    if (num == 1) return false;
    while (divider < num) {
        if (!(num % divider++)) return false;
    }
    return true;
}

int main()
{
    cin >> m >> n;
    while (m <= n) {
        if (isPrimeNumber(m)) {
            primeSum += m;
            if (primeMin == -1) primeMin = m; 
        }
        m++;
    }
    if (!primeSum) cout << "-1\n";
    else cout << primeSum << '\n' << primeMin << '\n';
    return 0;
}