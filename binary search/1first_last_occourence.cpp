/*
int find_first_last(int arr[], int n, int x, bool firstSearch)
{
    int low = 0, high = n - 1;

    int fi = -1, li = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            if (firstSearch)
            {
                high = mid - 1;
                fi = mid;
            }
            else
            {
                low = mid + 1;
                li = mid;
            }
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return (firstSearch == true) ? fi : li;
}
vector<int> find(int arr[], int n, int x)
{
    int fi = find_first_last(arr, n, x, 1);
    int li = find_first_last(arr, n, x, 0);

    vector<int> ans = {fi, li};
    return ans;
}
*/

//METHOD - 2 : Using binary search stl functions
// vector<int> find(int arr[], int n , int x )
// {
      
//    bool isPresent = binary_search(arr ,arr+n ,x);
//    if(!isPresent)
//    return {-1,-1};
//    else{
//        int fi = lower_bound(arr,arr+n,x) - arr;
//        int li = upper_bound(arr,arr+n,x) - arr;
//        return {fi,li-1};
//    }
// }