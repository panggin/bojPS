#include <iostream>
#include <vector>
using namespace std;

const int MAX_LEN = 500;

int h, w, volume = 0;
int hi, wi, height, prevBlockPos;
int blockMap[MAX_LEN][MAX_LEN] = {0,};

int main()
{
    ios::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // input
    cin >> h >> w;
    for (wi=0; wi<w; wi++) {
        cin >> height;
        for (hi=0; hi<height; hi++) blockMap[hi][wi] = 1;
    }

    for (hi=0; hi<h; hi++) {
        int prevBlockPos = -1;
        for (wi=0; wi<w; wi++) {
            if (blockMap[hi][wi]) { // is on the block
                if (prevBlockPos != -1) volume += (wi - prevBlockPos - 1);
                prevBlockPos = wi;
            }
        }
    }
    cout << volume << '\n';
    return 0;
}