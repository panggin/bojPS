#include <iostream>
#include <climits>
using namespace std;

typedef unsigned long long ull;
ull s, sum;

ull binarySearch(ull nStart, ull nEnd)
{
    ull first = nStart, last = nEnd, 
        mid = (first + last) / 2;
    
    while (first <= last) {
        sum = (1 + mid) * mid / 2;
        if (sum == s) return mid;
        else if (sum > s) last = mid - 1;
        else first = mid + 1;
        mid = (first + last) / 2;
    }
    sum = (1 + last) * last / 2;
    if (sum > s) return last - 1;
    else return last;
}

int main()
{
    cin >> s;
    cout << binarySearch(1, UINT_MAX);
    return 0;
}