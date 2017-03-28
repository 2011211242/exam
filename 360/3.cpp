#include <cstdio>
#include <set>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    set<int> point;
    map<int, int> pt;

    std::set<int>::iterator set_it;

    int max_t = 0;
    int pre, cur;
    scanf("%d", &pre);

    for(int i = 1; i < n; i++)
    { 
        scanf("%d\n", &cur);
        if(pre + 1 < cur)
        {
            point.insert(pre + 1); 
            point.insert(cur - 1);
            if(pre + 1 == cur - 1)
            {
                pt[pre + 1] = 3;
            }
            else
            {
                pt[pre + 1] = 1;
                pt[cur - 1] = 2;
            }
        }
        pre = cur;
        max_t = cur + 1;
    }

    int tmp;
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &tmp);
        set_it = point.lower_bound(tmp);
        if(set_it != point.end())
        {
            int t = *set_it;
            if(pt[t] == 1 || pt[t] == 3)
            {
                printf("%d\n", t);
            }
            else{
                printf("%d\n", tmp);
            }
        }
        else{
            printf("%d\n", max_t);
        }
    }
}

