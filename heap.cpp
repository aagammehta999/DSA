#include <iostream>
#include <queue>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }
    void insert(int val)
    {
        size += 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void deletefromheap()
    {
        if (size == 0)
        {
            cout << "nothing to delete" << endl;
            return;
        }
        arr[1] = arr[size];
        size--;

        // root node ko correct position pe
        int i = 1;
        while (i < size)
        {
            int leftindex = 2 * i;
            int rightindex = 2 * i + 1;

            if (leftindex < size && arr[i] << arr[leftindex])
            {
                swap(arr[i], arr[leftindex]);
                i = leftindex;
            }
            else if (rightindex < size && arr[i] < arr[rightindex])
            {
                swap(arr[i], arr[rightindex]);
                i = rightindex;
            }
            else
            {
                return;
            }
        }
    }
    void heapSort(int arr[], int n)
    {
        int size = n;

        while (size > 1)
        {
            // step 1 swap
            swap(arr[size], arr[1]);
            size--;

            heapify(arr, n, 1);
        }
    }
    void heapify(int arr[], int n, int i)
    {
        int largest = i;
        int left = 2 * i;
        int right = 2 * i + 1;

        if (left < n && arr[largest] < arr[left])
        {
            largest = left;
        }
        if (right < n && arr[largest] < arr[right])
        {
            largest = right;
        }
        if (largest != i)
        {
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }
};

int main()
{
    heap h1;
    h1.insert(50);
    h1.insert(55);
    h1.insert(53);
    h1.insert(52);
    h1.insert(54);
    h1.print();
    h1.deletefromheap();
    h1.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    // heapp ceation
    for (int i = n / 2; i > 0; i--)
    {
        h1.heapify(arr, n, i);
    }

    cout << "printing the array" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
        cout << endl;
    }
    // heap sort
    for (int i = 0; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "priority queue";
    priority_queue<int> pq;
    pq.push(4);
    pq.push(5);
    pq.push(2);
    pq.push(3);

    cout << "Element at top" << pq.top() << endl;
    pq.pop();
    cout << "Size is " << pq.size() << endl;
    if (pq.empty())
    {
        cout << "Empty queue" << endl;
    }
    else
    {
        cout << "Queue not empty" << endl;
    }

    // minheap

    priority_queue<int, vector<int>, greater<int>> minheap;

    minheap.push(4);
    minheap.push(5);
    minheap.push(2);
    minheap.push(3);
    cout << "Element at top" << minheap.top() << endl;
    minheap.pop();
    cout << "Size is " << minheap.size() << endl;
    if (minheap.empty())
    {
        cout << "Empty queue" << endl;
    }
    else
    {
        cout << "Queue not empty" << endl;
    }

    return 0;
}