#include <iostream>
using namespace std;

int n;
int f1 = 1, f2 = 1;

int main()
{
    cin >> n;
    if (n == 0) { // exception case #1 : f0
        cout << "0\n";
        return 0;
    }
    if (n < 3) { // exception case #2 : f1, f2
        cout << "1\n";
        return 0;
    }
    for (int i=3; i<=n; i++) {
        int tmp = f1 + f2;
        f1 = f2; f2 = tmp;
    }
    cout << f2 << '\n';
    return 0;
}