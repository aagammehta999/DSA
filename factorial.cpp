#include <iostream>
using namespace std;

int fact(int n)
{
    int sol;
    if (n == 1)
    {
        return 1;
    }
    else
    {
        sol = n * fact(n - 1);
        return sol;
    }
}
int main()
{
    int n, ans;
    cout << "Enter the valiue";
    cin >> n;
    ans = fact(n);
    cout<<ans;
}