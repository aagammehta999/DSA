#include <bits/stdc++.h>
using namespace std;
struct Job
{
    int id;
    int dead;
    int profit;
};
class Solution
{
public:
    bool static comparison(Job a, Job b)
    {
        return (a.profit > b.profit);
    }
    pair<int, int> JobScheduling(Job arr[], int n)
    {
        sort(arr, arr + n, comparison);
        int maxi = arr[0].dead;
        for (int i = 1; i < n; i++)
        {
            maxi = max(maxi, arr[i].dead);
        }
        int slot[maxi + 1];
        for (int i = 0; i <= maxi; i++)
        {
            slot[i] = -1;
        }
        int countJobs = 0, jobProfit = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = arr[i].dead; j > 0; j--)
            {
                if (slot[j] == -1)
                {
                    slot[j] = i;
                    countJobs++;
                    jobProfit += arr[i].profit;
                    break;
                }
            }
        }

        return make_pair(countJobs, jobProfit);
    }
};
int main()
{
    int n = 5;
    Job arr[n] = {{1, 4, 20}, {2, 1, 10}, {3, 2, 60}, {4, 2, 30}, {5, 3, 90}};
    Solution ob;
    pair<int, int> ans = ob.JobScheduling(arr, n);
    cout << "Total jobs performed out of 5 : " << ans.first << "\nTotal profit : " << ans.second << endl;
    return 0;
}
