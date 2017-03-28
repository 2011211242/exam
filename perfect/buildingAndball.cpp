#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(10000 + 1, vector<int>(10000 + 1, -1));

void init()
{
    for(int i = 1; i < dp.size(); i++)
    {
        dp[i][1] = i;
        dp[i][0] = i;
    }

    for(int i = 1; i < dp[0].size(); i++)
    {
        dp[1][i] = 1;
    }
}

int calcThrowNumber(int numOfFloors, int numOfBalls) {
    if(dp[numOfFloors][numOfBalls] != -1)
        return dp[numOfFloors][numOfBalls];

    /*
    if(numOfBalls > dp[numOfFloors][0])
    {
        dp[numOfFloors][numOfBalls] = calcThrowNumber(numOfFloors, dp[numOfFloors][0]);
        dp[numOfFloors][0] = dp[numOfFloors][numOfBalls];
    }
    else
    {
    */
    for(int floor = 2; floor <= numOfFloors; floor++)
    {
        for(int balls = 2; balls <= numOfBalls; balls++)
        {
            /*
            if(balls > dp[floor][0])
            {
                dp[floor][0]  = dp[floor][balls] = calcThrowNumber(floor, dp[floor][0]);
            }
            else
            {
            */
            int step = min(
                    calcThrowNumber(floor - 1, balls - 1), 
                    calcThrowNumber(floor - 1, balls)
                    ); 

            for(int n = 2;  n < floor; n++)
            {
                step = min(
                        max(
                            calcThrowNumber(n - 1, balls - 1), 
                            calcThrowNumber(floor - n, balls)
                           ), 
                        step
                        );
            }

            dp[floor][balls] = step + 1;
                /*
                dp[floor][0] = step + 1;
            }
            */
        }
    }
    //}
    return dp[numOfFloors][numOfBalls];
}

int main() {
    freopen("input.txt", "r", stdin);
    init();
    int numOfFloors, numOfBalls;

    while (scanf("%d %d", &numOfFloors, &numOfBalls) != EOF) {
        printf("%d %d\n", numOfFloors, numOfBalls);
        printf("%d\n",calcThrowNumber(numOfFloors, numOfBalls));
        break;
    }
}
