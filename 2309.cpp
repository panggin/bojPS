#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int COUNTS = 9;
const int HEIGHT_SUM = 100;
int height;
vector<int> dwarfs;

bool is7Dwarfs(vector<bool>& selected)
{
    int heightSum = 0;
    for (int i=0; i<COUNTS; i++) {
        if (selected[i]) heightSum += dwarfs[i];
    }
    if (heightSum == HEIGHT_SUM) return true;
    else return false;
}

void print7Dwarfs(vector<bool>& selected)
{
    for (int i=0; i<COUNTS; i++) {
        if (selected[i]) cout << dwarfs[i] << '\n';
    }
}

int main()
{
    // input process
    for (int i=0; i<COUNTS; i++) {
        cin >> height;
        dwarfs.push_back(height);
    }
    sort(dwarfs.begin(), dwarfs.end()); // sort heights

    vector<bool> selected(COUNTS, true); // to select 7 dwarfs
    fill(selected.begin(), selected.begin()+2, false);
    
    // cout << "---------- result -----------\n";
    do { // select process
        if (is7Dwarfs(selected)) {
            print7Dwarfs(selected); return 0;
        }
    } while (next_permutation(selected.begin(), selected.end()));
    return 0;
}