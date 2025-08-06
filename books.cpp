#include <iostream>
#include <algorithm>
using namespace std;

long long n, t, a[100010], l, r, cur, maxi;
int main()
{
    cin >> n >> t;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    l = 0;
    r = 0;
    while (r < n)
    {
        cur += a[r];
        while (cur > t)
        {
            cur -= a[l];
            l++;
        }
        maxi = max(maxi, r-l+1);
        r++;
    }
    cout << maxi;
}
