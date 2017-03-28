#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int n;

    scanf("%d", &n);
    vector<bool> is_prime(n, true);
    vector<int> prime;
    for(int i = 2; i < n ; i++)
    {
        if(is_prime[i])
        {
            prime.push_back(i);
            int t = i + i;
            while(t < n)
            {
                is_prime[t] = false;
                t+= i;
            }
        }
    }
    int s = 0, e = prime.size() - 1;
    int cnt = 0;

    while(s <= e)
    {
        if(prime[s] + prime[e] == n)
        {
            cnt++;
            s++;
            e--;
        }
        else{
            if(prime[s] + prime[e] > n)
            {
                e--;
            }
            else{
                s++;
            }
        }
    }
    printf("%d\n", cnt);
}
