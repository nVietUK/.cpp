#include <bits/stdc++.h>

using namespace std;

// communist variables
    unsigned n, m;
    vector<vector<int>> ta;

int kadane(vector<int>& arr, int& start, int& finish, int n)
{
    int sum = 0, maxSum = INT_MIN, i;
 
    finish = -1;
 
    int local_start = 0;
 
    for (i = 0; i < n; ++i)
    {
        sum += arr[i];
        if (sum < 0)
        {
            sum = 0;
            local_start = i + 1;
        }
        else if (sum > maxSum)
        {
            maxSum = sum;
            start = local_start;
            finish = i;
        }
    }
 
    if (finish != -1)
        return maxSum;
 
    maxSum = arr[0];
    start = finish = 0;
 
    for (i = 1; i < n; i++)
    {
        if (arr[i] > maxSum)
        {
            maxSum = arr[i];
            start = finish = i;
        }
    }
    return maxSum;
}
 
void findMaxSum()
{
    int maxSum = INT_MIN;
 
    int left, right, i;
    int sum, start, finish;
 
    for (left = 0; left < m; ++left) {
		vector<int> temp(n, 0);
        for (right = left; right < m; ++right) {
 
            for (i = 0; i < n; ++i) temp[i] += ta[i][right];
 
            sum = kadane(temp, start, finish, n);
 
            if (sum > maxSum) {
                maxSum = sum;
            }
        }
    }
 
    cout << maxSum;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("max2d.inp", "r", stdin);
    freopen("max2d.out", "w", stdout);
#endif
    
    cin >> n >> m; ta.resize(n); for (auto& tp : ta) tp.resize(m, 0);
    while (n--)
        for (unsigned i = 0; i < m; i++)
            cin >> ta[n][i];
    n = ta.size(); findMaxSum();
}