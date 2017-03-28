#include<cstdio>
#include<vector>
using namespace std;

unsigned int getAriseLength(vector<int> &num)
{
    vector<int> arise;
    int length = 0;
    for(int i = 0; i < num.size(); i++)
    {
        while(!arise.empty() && num[i] <= num[arise.back()])
        {
            arise.pop_back();
        }
        arise.push_back(i);
        if(arise.size() > length) length = arise.size();
    }
    return length;
}


int main()
{
    int n;
    scanf("%d", &n);
    vector<int> num;
    for(int i = 0; i < n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        num.push_back(tmp);
    }

    unsigned int length = getAriseLength(num);
    printf("%u\n", length);
}
