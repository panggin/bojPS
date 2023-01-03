#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string a, b, result="";
string::reverse_iterator riterA, riterB;
int numA, numB, num, carry=0;
char charNum;

int main()
{
    cin >> a >> b;
    riterA = a.rbegin(); riterB = b.rbegin();

    while (riterA!=a.rend() || riterB!=b.rend() || carry!=0) {
        if (riterA != a.rend()) numA = *riterA++ - '0';
        else numA = 0;
        
        if (riterB != b.rend()) numB = *riterB++ - '0';
        else numB = 0;

        num = numA + numB + carry;
        carry = num / 10;
        charNum = '0' + (num % 10);
        result = charNum + result;
    }
    cout << result;
    return 0;
}