#include <iostream>
using namespace std;

unsigned int t, n;
unsigned int bitmask = 1;
const int BIT_SIZE = 32;

int main()
{
    cin >> t;
    while (t--) {
        bitmask = 1; // reset bitmask
        cin >> n;
        for (int i=0; i<BIT_SIZE; i++) {
            if (n & bitmask) cout << i << ' ';
            bitmask = bitmask << 1;
        }
        cout << '\n';
    }
    return 0;
}