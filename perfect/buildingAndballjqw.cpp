#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

int calcThrowNumber(int numOfFloors, int numOfBalls) {
    if (numOfBalls < 1 || numOfFloors < 1) {
        return 0;
    }
    //dp[egg][num]形式
    vector<vector<int> > dp(numOfBalls + 1, vector<int>(numOfFloors + 1, 0));

    //初始化
    for (int i = 1; i <= numOfBalls; i++) {
        for (int j = 1; j <= numOfFloors; j++) {
            dp[i][j] = j;   //对于第j层，最坏的情况就是从1到j层逐层验证，就是j次。
        }
    }

    for (int balls = 2; balls <= numOfBalls; balls++) {  //鸡蛋个数遍历
        for (int floor = 1; floor <= numOfFloors; floor++) {  //总楼层遍历
            for (int n = 1; n < floor; n++) {  //对第一次扔的楼层进行遍历 1~j
                dp[balls][floor] = min(dp[balls][floor], 1 + max(dp[balls - 1][n - 1], dp[balls][floor - n]));
            }
        }
    }
    return dp[numOfBalls][numOfFloors];

}

int main() {
    int numOfFloors, numOfBalls;
    while (scanf("%d%d", &numOfFloors, &numOfBalls) != EOF) {
        printf("%d\n", calcThrowNumber(numOfFloors, numOfBalls));
    }
    return 0;
}
