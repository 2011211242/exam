#include <bits/stdc++.h>
using namespace std;

int get_max_value(const vector<int> &values, int volume)
{
    vector<int> dp(volume + 1, 0);

    for(int value : values)
    {
        for(int i = volume; i >= value; i--)
        {
            dp[i] = max(dp[i], dp[i - value] + value);
        }
    }
    return dp[volume];
}

int main()
{
    int n;
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    vector<int> times;
    int times_sum = 0;
    for(int i = 0; i < n; i++)
    {
        int time;
        scanf("%d", &time);
        time = time >> 10;

        times.push_back(time);
        times_sum += time;
    }

    int t1 = get_max_value(times, times_sum >> 1);

    //printf("t1 = %d\n", t1);
    //printf("t_sum = %d\n", times_sum);
    printf("%d\n", (times_sum - t1) << 10);

    return 0;
}

