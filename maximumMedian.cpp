#include <iostream>
#include <algorithm>
using namespace std;

long long n, k, a[200010], cur, low;
long long prefixSums[200010], sum;
long long bs(long long l, long long r)
{
    long long mid;
    while (l < r)
    {
        mid = (l+r)/2;
        //try mid as the median
        low = (int)(lower_bound(a, a+n, mid)-a);
        if (n/2 == 0)
            sum = prefixSums[low-1];
        else
            sum = prefixSums[low-1]-prefixSums[n/2-1];
        if ((low-n/2)*mid-sum <= k && l != r-1)
            l = mid;
        else if ((low-n/2)*mid-sum <= k && l == r-1)
        {
            //try r
            low = (int)(lower_bound(a, a+n, r)-a);
            if (n/2 == 0)
                sum = prefixSums[low-1];
            else
                sum = prefixSums[low-1]-prefixSums[n/2-1];
            if ((low-n/2)*r-sum <= k)
                return r;
            return l;
        }
        else
            r = mid-1;
    }
    return l;
}
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);
    prefixSums[0] = a[0];
    for (int i = 1; i < n; i++)
        prefixSums[i] = a[i]+prefixSums[i-1];
    cout << bs(a[n/2], a[n-1]+k);
}
