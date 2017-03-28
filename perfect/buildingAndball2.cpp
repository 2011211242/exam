#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(10000 + 1, vector<int>(10000 + 1, -1));

int calcThrowNumber(int numOfFloors, int numOfBalls) {
    if(dp[numOfFloors][numOfBalls] != -1)
        return dp[numOfFloors][numOfBalls];
   
    if(numOfBalls > dp[numOfFloors][dp[numOfFloors][0]])
    {
        dp[numOfFloors][numOfBalls] = calcThrowNumber(numOfFloors, \
                dp[numOfFloors][dp[numOfFloors][0]]);

        if(dp[numOfFloors][numOfBalls] < dp[numOfFloors][dp[numOfFloors][0]])
            dp[numOfFloors][0] = numOfBalls;
    }
    else
    {
        //for(int balls = )
        int step = min(
                calcThrowNumber(numOfFloors - 1, numOfBalls - 1), 
                calcThrowNumber(numOfFloors - 1, numOfBalls)
                ); 

        for(int n = 2;  n < numOfFloors; n++)
        {
            step = min(
                    max(
                        calcThrowNumber(n - 1, numOfBalls - 1), 
                        calcThrowNumber(numOfFloors - n, numOfBalls)
                       ), 
                    step
                    );
        }

        dp[numOfFloors][numOfBalls] = step + 1;
        if(step + 1 < dp[numOfFloors][dp[numOfFloors][0]])
        {
            dp[numOfFloors][0] = numOfBalls;
        }
    }
    return dp[numOfFloors][numOfBalls];
}

void init()
{

    for(int balls = 1; balls < dp[0].size(); balls++)
    {
        dp[1][balls] = 1;
    }

    for(int floor = 1; floor < dp.size(); floor++)
    {
        dp[floor][1] = floor;
        dp[floor][0] = 1;
    }

    
    for(int floor = 2; floor < dp.size(); floor++)
    {
        int step = dp[floor][dp[floor][0]];
        for(int balls = 2; balls < step; balls++)
        {
            dp[floor][balls] = calcThrowNumber(floor, balls);
            step = min(step, dp[floor][balls]);
        }

        if(step < dp[floor][dp[floor][0]])
            dp[floor][0] = step;
    }
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
