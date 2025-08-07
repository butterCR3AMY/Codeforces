#include <iostream>
using namespace std;

long long n, k, q, l, r, bfor[200010], arr[200010], prefixSums[200010], a, b;
int main()
{
    cin >> n >> k >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> l >> r;
        bfor[l]++;
        bfor[r+1]--;
    }
    arr[0] = bfor[0];
    for (int i = 1; i <= 200000; i++)
        arr[i] = arr[i-1]+bfor[i];
    if (arr[0] >= k)
        prefixSums[0] = 1;
    for (int i = 1; i <= 200000; i++)
    {
        if (arr[i] >= k)
            prefixSums[i] = prefixSums[i-1]+1;
        else
            prefixSums[i] = prefixSums[i-1];
    }
            
    while (q--)
    {
        cin >> a >> b;
        cout << prefixSums[b]-prefixSums[a-1] << '\n';
    }
}
