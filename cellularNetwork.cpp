#include <iostream>
#include <algorithm>
using namespace std;

int n, m, c[100010], t[100010], low, r, dist;
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < m; i++)
        cin >> t[i];
    sort(c, c+n);
    sort(t, t+m);
    for (int i = 0; i < n; i++)
    {
        low = (int)(lower_bound(t, t+m, c[i])-t);
        dist = 2*(int)1e9;
        if (low < m)
            dist = min(dist, abs(t[low]-c[i]));
        if (low > 0)
            dist = min(dist, abs(t[low-1]-c[i]));
        r = max(r, dist);
    }
    cout << r;
}
