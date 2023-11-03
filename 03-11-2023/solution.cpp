// Brute force
// Time Complexity: O(n^3) Space Complexity: O(1)
bool checkTriplet(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                int a = arr[i] * arr[i];
                int b = arr[j] * arr[j];
                int c = arr[k] * arr[k];
                if (a == b + c || b == a + c || c == a + b)
                    return true;
            }
        }
    }
    return false;
}

// better approach
// Time Complexity: O(n^2) Space Complexity: O(N)
bool checkTriplet(int arr[], int n)
{
    // code here
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i] * arr[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int c = arr[i] * arr[i] + arr[j] * arr[j];
            if (m[c] > 0)
                return true;
        }
    }
    return false;
}

// better approach
// Time Complexity: O(n^2) Space Complexity: O(1)
bool checkTriplet(int arr[], int n)
{
    // code here
    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i] * arr[i];
    }
    sort(arr, arr + n);
    for (int c = n - 1; c > 1; c--)
    {
        int a = 0, b = c - 1;
        while (a < b)
        {
            if (arr[a] + arr[b] == arr[c])
                return true;
            else if (arr[a] + arr[b] < arr[c])
                a++;
            else
                b--;
        }
    }
    return false;
}

// best approach
// Time Complexity: O(n^2) Space Complexity: O(1)
bool checkTriplet(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i] * arr[i];
    }
    sort(arr, arr + n);
    for (int c = n - 1; c > 1; c--)
    {
        int a = 0, b = c - 1;
        while (a < b)
        {
            if (arr[a] + arr[b] == arr[c])
                return true;
            else if (arr[a] + arr[b] < arr[c])
                a++;
            else
                b--;
        }
    }
    return false;
}

// best approach
// TC:O(N + max(a[i])^2), SC:O(max(a[i])^2)
bool checkTriplet(int arr[], int n)
{

    int max = 0;
    // Find the maximum element
    for (int i = 0; i < n; i++)
    {
        max = std::max(max, arr[i]);
    }
    max = max * max;

    vector<int> freq(max + 1, 0);
    // Increase the frequency of array elements
    for (int i = 0; i < n; i++)
    {
        freq[arr[i] * arr[i]]++;
    }

    // for all possible a
    for (int i = 1; i <= max; i++)
    {
        // If a is not there
        if (freq[i] == 0)
        {
            continue;
        }

        // for all possible b
        for (int j = 1; j <= max; j++)
        {
            // If there is no b or if a and b are the same and there is only one a
            if (freq[j] == 0 || (i == j && freq[i] == 1))
            {
                continue;
            }

            // Now we have the possibility of a and b, evaluate c, and check if it is present
            int c = i + j;
            if (c > max)
            {
                continue;
            }
            if (freq[c] > 0)
            {
                return true;
            }
        }
    }
    return false;
}