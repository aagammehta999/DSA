#include <iostream>
using namespace std;

int partition(int arr[], int s, int e)
{
    int pivot = arr[s];
    int count = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }
    int pivotIndex = s + count;
    swap(arr[pivotIndex], arr[s]);

    // left and right part sambhalna hai
    int i = s, j = e;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j]> pivot)
        {
            j--;
        }
    //cout<<"partition";
        while (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
}
// int partition(int arr, int s, int e)
// {
//     int pivot = arr[e];
//     int pivotIndex = 0;
//     for (int i = s ; i < e; i++)
//     {
//         if (arr[i] <= pivot)
//         {
//             swap()
//         }
//     }
// }
void quick_sort(int arr[], int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int p = partition(arr, s, e);
    // cout<<"quick_Sort";
    quick_sort(arr, s, p - 1);
    quick_sort(arr, p + 1, e);
}

int main()
{
    int arr[5] = {4, 7, 23, 8, 2};
    int n = 5;
    quick_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}