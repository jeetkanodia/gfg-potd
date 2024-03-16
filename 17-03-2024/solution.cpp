//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void append(struct Node **headRef, struct Node **tailRef, int newData)
{
    struct Node *new_node = new Node(newData);

    if (*headRef == NULL)
    {
        *headRef = new_node;
    }

    else
    {
        (*tailRef)->next = new_node;
    }
    *tailRef = new_node;
}

void printList(struct Node *head)
{
    while (head)
    {
        cout << head->data << ' ';
        head = head->next;
    }
}

// } Driver Code Ends
/*
Structure of the node of the linked list is as
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
public:
    // your task is to complete this function
    int listlength(struct Node *head)
    {
        int n = 0;
        while (head)
        {
            n++;
            head = head->next;
        }
        return n;
    }
    int countPairs(struct Node *head1, struct Node *head2, int x)
    {
        // Code here
        int n = listlength(head1);
        int m = listlength(head2);
        if (n > m)
        {
            swap(n, m);
            swap(head1, head2);
        }

        unordered_map<int, int> mp;
        struct Node *temp = head1;
        while (temp)
        {
            mp[temp->data]++;
            temp = temp->next;
        }
        temp = head2;
        int count = 0;
        while (temp)
        {
            int y = temp->data;
            if (mp[x - y])
                count++;
            temp = temp->next;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        struct Node *head1 = NULL;
        struct Node *tail1 = NULL;
        struct Node *tail2 = NULL;
        struct Node *head2 = NULL;
        int n1, n2, tmp, x;
        cin >> n1;
        while (n1--)
        {
            cin >> tmp;
            append(&head1, &tail1, tmp);
        }
        cin >> n2;
        while (n2--)
        {
            cin >> tmp;
            append(&head2, &tail2, tmp);
        }
        cin >> x;
        Solution obj;
        cout << obj.countPairs(head1, head2, x) << '\n';
    }
    return 0;
}
// } Driver Code Ends