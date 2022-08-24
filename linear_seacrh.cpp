#include <iostream>
using namespace std;

bool linear_search(int arr[], int size, int k)
{
    if (size == 0)
    {
        return false;
    }
    if (arr[0] = k)
    {
        return true;
    }
    else
    {
        bool remaning_part = linear_search(arr + 1, size - 1, k);
        return remaning_part;
    }
}

int main()
{
    int arr[5] = {55, 49, 15, 45, 12};
    int size = 5;
    int key = 49;
    bool ans = linear_search(arr, size, key);
    return ans;
}