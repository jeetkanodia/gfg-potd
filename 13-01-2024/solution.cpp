//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* Link list node */
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

/* Function to print linked list */
void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// } Driver Code Ends
// User function Template for C++

/*Link list node
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
// Divyans Mishra solved it
class Solution
{
public:
    Node *insertionSort(struct Node *head)
    {
        // code here
        Node *temp1 = head;

        while (temp1)
        {
            int minD = temp1->data;
            Node *temp2 = temp1->next;
            Node *minptr = temp1;
            while (temp2)
            {
                if (temp2->data < minD)
                {
                    minptr = temp2;
                    minD = min(minD, temp2->data);
                }
                temp2 = temp2->next;
            }
            swap(temp1->data, minptr->data);
            temp1 = temp1->next;
        }
        return head;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        Node *head = NULL;
        Node *temp = head;

        for (int i = 0; i < n; i++)
        {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else
            {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Solution ob;

        head = ob.insertionSort(head);
        printList(head);

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends