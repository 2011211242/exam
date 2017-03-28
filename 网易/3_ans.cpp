#include <bits/stdc++.h>
using namespace std;

const int maxn = 500010;
int n;
vector<int> a;
int dp[2][maxn];

int solve(vector<int> v)
{
    int res = 0;

    printf("%d\n", sizeof(dp)); return 0;

    memset(dp, 0, sizeof(dp));

    int p = 0;
    for(int i = 0; i < v.size(); i++)
    {
        dp[p][v[i]] = max(dp[1 - p][v[i]], v[i]);
        for(int ix = 0; ix < maxn; i++)
        {
            if(dp[p][ix]){
                if(dp[p][ix] < dp[1 - p][ix]) dp[p][ix] = dp[1 - p][ix];

                dp[p][ix + v[i]] = max(dp[p][ix + v[i]], \
                        max(dp[1 - p][ix + v[i]], dp[1 - p][ix] + v[i]));

                dp[p][abs(ix - v[i])] = max(dp[p][abs(ix - v[i])], \
                        max(dp[1 - p][abs(ix - v[i])], max(dp[1-p][ix] - ix + v[i], dp[1 - p][ix])));
 
            }
        }
        p = 1 - p;

    }

    if(dp[1 - p][0]) res = dp[1 - p][0];
        else res = -1;
            return res;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        a.push_back(x);
    }
    cout << solve(a) << endl;
    return 0;
}

