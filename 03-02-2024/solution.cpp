//{ Driver Code Starts
// Program to check if linked list is empty or not
#include <iostream>
using namespace std;
const long long unsigned int MOD = 1000000007;

/* Link list Node */
struct Node
{
    bool data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// } Driver Code Ends
/* Below global variable is declared in code for modulo arithmetic
const long long unsigned int MOD = 1000000007; */

/* Link list Node/
struct Node
{
    bool data;   // NOTE data is bool
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}; */
#include <bits/stdc++.h>
class Solution
{
public:
    // Should return decimal equivalent modulo 1000000007 of binary linked list
    long long unsigned int decimalValue(Node *head)
    {
        // Your Code Here
        int n = 0;
        string str = "";
        int mod = 1e9 + 7;
        Node *temp = head;
        long long unsigned int power = 1;
        long long unsigned int ans = 0;
        while (temp)
        {
            n++;
            str += char(temp->data);
            temp = temp->next;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            int x = int(str[i]);
            ans = ans + x * power;
            ans = ans % mod;
            power = (power * 2) % mod;
        }
        return ans % mod;
    }
};

//{ Driver Code Starts.

void append(struct Node **head_ref, struct Node **tail_ref, bool new_data)
{

    struct Node *new_node = new Node(new_data);

    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

bool isEmpty(struct Node *head);

/* Driver program to test above function*/
int main()
{
    bool l;
    int i, n, T;

    cin >> T;

    while (T--)
    {
        struct Node *head = NULL, *tail = NULL;

        cin >> n;
        for (i = 1; i <= n; i++)
        {
            cin >> l;
            append(&head, &tail, l);
        }
        Solution obj;
        cout << obj.decimalValue(head) << endl;
    }
    return 0;
}
// } Driver Code Ends