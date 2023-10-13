#include <bits/stdc++.h>
using namespace std;

// min heap - 1 based indexing is follwes
void heapify(int arr[], int i, int n)
{
    int smallest = i;
    int left = 2 * i ;
    int right = 2 * i + 1;
    if (left <= n && arr[smallest] > arr[left])
        smallest = left;
    if (right <= n && arr[smallest] > arr[right])
        smallest = right;
    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        heapify(arr, smallest, n);
    }
}
int main()
{
    cout << "Enter the size : ";
    int n;
    cin >> n;
    int *arr = new int[n + 1];
    cout << "Enter the elements : ";
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    // all nodes from n/2+1 to n are leaf nodes.
    // Building heap tc : O(N)
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, i, n);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
}