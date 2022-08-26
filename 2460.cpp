#include <iostream>
#include <algorithm>
using namespace std;

int n = 10; // station counts
int peopleOut = 0, peopleIn = 0;
int curr, maxCurr = 0;

int main()
{
    while (n--) {
        cin >> peopleOut >> peopleIn;
        curr = curr - peopleOut + peopleIn;
        maxCurr =  max(maxCurr, curr);
    }
    cout << maxCurr << '\n';
    return 0;
}