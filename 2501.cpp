#include <iostream>
using namespace std;

int n, k;
int q = 0, order = 0;

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n >> k;
    while (++q <= n) {
        if (n % q == 0) order++;
        if (order == k) {
            cout << q << '\n';
            return 0;
        }
    }
    cout << "0\n";
    return 0;
}