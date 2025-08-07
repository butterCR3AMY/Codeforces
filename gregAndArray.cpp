#include <iostream>
using namespace std;

long long n, m, k, l[100010], r[100010], d[100010], bfor[100010], a[100010], arr[100010], num[100010], ans[100010], x, y;
int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> l[i] >> r[i] >> d[i];
    while (k--)
    {
        cin >> x >> y;
        bfor[x-1] += 1;
        bfor[y] -= 1;
    }
    num[0] = bfor[0];
    for (int i = 1; i < m; i++)
        num[i] = num[i-1]+bfor[i];
    for (int i = 0; i < m; i++)
    {
        arr[l[i]-1] += d[i]*num[i];
        arr[r[i]] -= d[i]*num[i];
    }
    cout << arr[0]+a[0] << ' ';
    ans[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        ans[i] = ans[i-1]+arr[i];
        cout << ans[i]+a[i] << ' ';
    }
}
