#include <iostream>
using namespace std;

int fibo(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    else
    {
        int sol=fibo(n-1)+fibo(n-2);
        return sol;
    }
}
int main()
{
    int n;
    cout << "Enter the no";
    cin >> n;
    int ans = fibo(n);
    return 0;
}