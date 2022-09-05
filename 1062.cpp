#include <iostream>
#include <vector>
using namespace std;

int n, k, teached = 1;
vector<int> wordBits;

// a c     i    n     t       -> 5
// abcdefghijklmnopqrstuvwxyz -> 26

int getMaxCounts(int lefts, int idx)
{
    int result = 0;
    
    if (lefts == 0) { // word count
        for (int word : wordBits)
            if ((word & teached) == word) result++;
        return result;
    }
    for (int i=idx; i<26; i++) { // alphabet select
        if (teached & (1 << i)) continue; // already teached
        teached |= (1 << i);
        result = max(result, getMaxCounts(lefts-1, i+1));
        teached &= ~(1 << i);
    }
    return result;
}

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n >> k;
    string word;
    for (int i=0; i<n; i++) {
        cin >> word; int wordBit = 0;
        for (char w : word) wordBit |= 1 << (w - 'a');
        wordBits.push_back(wordBit);
    }

    if (k < 5) {cout << "0\n"; return 0;}
    teached |= 1 << ('a' - 'a');
    teached |= 1 << ('c' - 'a');
    teached |= 1 << ('i' - 'a');
    teached |= 1 << ('n' - 'a');
    teached |= 1 << ('t' - 'a');

    cout << getMaxCounts(k-5, 1) << '\n';
    return 0;
}