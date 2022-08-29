#include <iostream>
using namespace std;

int num1, num2;
int GCD, LCM;

int main()
{
    cin >> num1 >> num2;
    
    // get the greatest common denominator (최대공약수)
    GCD = min(num1, num2);
    while (GCD > 1) {
        if (!(num1 % GCD) && !(num2 % GCD)) break;
        else GCD--;
    }

    // get the least common multiple (최소공배수)
    LCM = GCD * (num1 / GCD) * (num2 / GCD);

    cout << GCD << '\n' << LCM << '\n';
    return 0;
}