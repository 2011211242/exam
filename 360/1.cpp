#include <cstdio>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    float e = 0.0f;
    for(int i = 0; i < n; i++)
    {
        float val, p;
        scanf("%f %f", &val, &p);
        e += val * p;
    }
    printf("%.3f\n", e / 100);
}
