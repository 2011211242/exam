#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> black(n, 0);
    vector<int> white(n, 0);


    int max_area = 0;
    for(int i = 0; i < n; i++)
    {

        char * str = new char[n + 1];
        scanf("%s", str);
        for(int j = 0; j < n; j++)
        {
            if(str[j] == 'B')
            {
                black[j]++;
                white[j] = 0;
                max_area = max(max_area, black[j]);
            }
            if(str[j] == 'W')
            {
               white[j] ++;
               black[j] = 0;
               max_area=max(max_area, white[j]);
            }
        }
    }
    printf("%d\n", max_area);
}
