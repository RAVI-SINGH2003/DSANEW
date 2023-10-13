#include <bits/stdc++.h>
using namespace std;

// tc : o(nlogn)
// heap sort - 1 based indexing is follwes
void heapify(int arr[], int i, int n)
{
    int left = 2 * i;
    int right = left + 1;
    int largest = i;
    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, largest, n);
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
    int last = n;
    while (last > 1)
    {
        swap(arr[last], arr[1]);
        last--;
        heapify(arr, 1, last);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
}