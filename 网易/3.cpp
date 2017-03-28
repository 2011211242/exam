#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int max_h = -1;

void get_res(vector<int>& length, int idx)
{
    if(idx == length.size() - 1)
    {
        int h1, h2 = 0;
        int s = 0, e = length.size() - 1;
        while(s <= e)
        {
            if(h1 <= h2)
            {
                h1 += length[s];
                s++;
            }
            else
            {
                h2 += length[e];
                e--;
            }

            if(h1 == h2)
            {
                if(max_h < h1) max_h = h1;
            }
        }
    }

    for(int j = idx + 1; j < length.size(); j++)
    {
        swap(length[idx], length[j]);
        get_res(length, idx + 1);
        swap(length[idx], length[j]);
    }
}

int main()
{
    int n, l;
    vector<int> length;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &l);
        length.push_back(l);
    }

    get_res(length, 0);
    printf("%d\n", max_h);
}

