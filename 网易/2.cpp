#include <cstdio>
#include <vector>
using namespace std;

int dfs(const vector<vector<int>> &workers, vector<bool> &works, int worker_id)
{
    if(worker_id >= workers.size()) return 1;

    int ret = 0;
    for(int i = 0; i < workers[worker_id].size(); i++)
    {
        int work_id = workers[worker_id][i];
        if(works[work_id] == false)
        {
            works[work_id] = true;
            ret += dfs(workers, works, worker_id + 1);
            works[work_id] = false;
        }
    }
    return ret;
}

int main()
{
    int n;
    char str[10];

    scanf("%d", &n);

    vector<vector<int>> workers(n);
    vector<bool> works(n, false);

    for(int i = 0; i < n; i++)
    {
        scanf("%s", str);
        for(int j = 0; str[j]; j++)
        {
            workers[i].push_back(str[j] - '0');
        }
    }
    int ret = dfs(workers, works, 0);
    printf("%d\n", ret);
}
