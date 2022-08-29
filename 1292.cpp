#include <iostream>
using namespace std;

int a, b, result;

int sumToN(int n)
{
    int sum = 0, num = 1;
    while (n >= num) {
        sum += (num * num);
        n -= num++;
    }
    sum += (n * num);
    return sum;
}

int main()
{
    cin >> a >> b;
    result = sumToN(b) - sumToN(a-1);
    cout << result << '\n';
    return 0;
}