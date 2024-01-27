#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
long long merge(long long *arr, int n, int l, int mid, int r)
{
    int len1 = mid - l + 1;
    int len2 = r - mid;
    long long count = 0;
    long long *temp = new long long[len1 + len2];
    int i = l, j = mid + 1, ind = 0;
    while (i <= mid && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            temp[ind++] = arr[i++];
        }
        else
        {
            temp[ind++] = arr[j++];
            count += (mid - i + 1);
        }
    }
    while (i <= mid)
    {
        temp[ind++] = arr[i++];
    }
    while (j <= r)
    {
        temp[ind++] = arr[j++];
    }
    for (int k = 0; k < len1 + len2; k++)
    {
        arr[k + l] = temp[k];
    }
    delete[] temp;
    return count;
}
long long mergeSort(long long *arr, int n, int l, int r)
{
    if (l >= r)
        return 0;
    int mid = (l + r) / 2;
    long long count = 0;
    count += mergeSort(arr, n, l, mid);
    count += mergeSort(arr, n, mid + 1, r);
    count += merge(arr, n, l, mid, r);
    return count;
}
long long getInversions(long long *arr, int n)
{
    return mergeSort(arr, n, 0, n - 1);
}