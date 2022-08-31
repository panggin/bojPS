#include <iostream>
#include <vector>
#include <stack>
using namespace std;

string brackets; 
stack<int> calcStack;
vector<int> resultByDepth(15,0);

bool calcBracket(char bracket)
{
    int prevNum, depth, prevResult;

    // bracket (, [ : stack push
    if (bracket == '(') {
        calcStack.push(2); return true;
    } else if (bracket == '[') {
        calcStack.push(3); return true;
    }

    // bracket ), ] : stack pop -> update result
    else if (!calcStack.empty()) {
        prevNum = calcStack.top(); calcStack.pop();

        if ((bracket == ')' &&  prevNum == 2)||(bracket == ']' && prevNum == 3)) {
            depth = calcStack.size();
            prevResult = resultByDepth[depth+1];

            if (prevResult == 0) resultByDepth[depth] += prevNum;
            else                 resultByDepth[depth] += (prevResult * prevNum);
            
            resultByDepth[depth+1] = 0; return true; // init prev depth result
        }
    }

    // bracket error
    resultByDepth[0] = 0; return false;
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> brackets;
    for (char bracket : brackets) {
        if (!calcBracket(bracket)) break; // detect bracket error
    }
    cout << resultByDepth[0] << '\n';
    return 0;
}