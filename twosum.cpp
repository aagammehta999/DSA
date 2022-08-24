#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> twoSum = {3, 3, 12, 4, 5, 3, 21};
    int target = 9;
    int len = twoSum.size();
    for (int i = 0; i < twoSum.size(); i++)
    {
        int next = target - twoSum[i];
        if (next == twoSum[i + 1])
        {
            cout << "[" << i << "," << i + 1 << "]";
            break;
        }
    }
}