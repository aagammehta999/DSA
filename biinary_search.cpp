#include <iostream>
using namespace std;
// check if the array is sorted ir not
bool is_sorted(int *arr, int size)
{
    if (size == 0 || size == 1)
    {
        return true;
    }
    if (arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        bool remaningpart = is_sorted(arr + 1, size - 1);
        return remaningpart;
    }
}
bool binary_search(int *arr, int s, int e, int k)
{
    int mid = s + (e - s) / 2;

    if (s > e)
    {
        return false;
    }
    if (arr[mid] == k)
    {
        return true;
    }

    if (arr[mid] < k)
    {
        return binary_search(arr, mid + 1, e, k);
    }
    else if (arr[mid] > k)
    {
        return binary_search(arr, s, mid - 1, k);
    }
    else
    {
    }
}

// sum of the array using recursion
int sumofarr(int *arr, int size)
{
    if (size == 0)
    {
        return 0;
    }
    if (size == 1)
    {
        return arr[0];
    }

    int remaning_part = sumofarr(arr + 1, size - 1);
    int sum = arr[0] + remaning_part;
    return sum;
}

int main()
{
    int arr[5] = {55, 49, 15, 45, 12};
    int size = 5;
    bool ans = is_sorted(arr, size);
    int key = 10;
    int start = arr[0];
    int end = arr[5];
    if (is_sorted)
    {
        cout<<"Found or Not"<<binary_search(arr, start, end, key);
    }
    else{
        cout<<"Array not sorted";
    }
    return 0;
}