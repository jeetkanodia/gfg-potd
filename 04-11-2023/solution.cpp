int transitionPoint(int arr[], int n)
{
    // code here
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
            return i;
    }
    return -1;
}
// TC - O(N) SC - O(1)

int transitionPoint(int arr[], int n)
{
    // code here
    int start = 0, end = n - 1;
    int ans = -1;
    int mid = (start + end) / 2;
    while (start <= end)
    {
        if (arr[mid] == 1)
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = (start + end) / 2;
    }
    return ans;
}
// TC - O(logN) SC - O(1)
