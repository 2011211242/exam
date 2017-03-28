#include <cstdio>
#include <map>
using namespace std;

int main()
{
    char str[100010];
    scanf("%s", str);
    map<int, int> pattern_count;

    int p = 0x01;
    int pattern = 0x000;
    long long int ret = 0;

    pattern_count[0] = 1;
    for(int i = 0; str[i]; i++)
    {
        pattern ^= (p << (str[i] - 'a'));
        ret += (long long int) pattern_count[pattern];
        pattern_count[pattern]++;
    }
    printf("%lld\n", ret);
}
