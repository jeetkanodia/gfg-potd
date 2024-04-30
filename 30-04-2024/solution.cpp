//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
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

struct Node *buildList(int size)
{
    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
private:
    struct Node *reverse(struct Node *root)
    {
        struct Node *prev = nullptr, *curr = root;
        while (curr)
        {
            struct Node *forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }
    // void print(struct Node* root)
    // {
    //     while(root)
    //     {
    //         cout<<root->data<<" ";
    //         root=  root->next;
    //     }
    //     cout<<endl;
    // }
public:
    // Function to add two numbers represented by linked list.
    struct Node *addTwoLists(struct Node *num1, struct Node *num2)
    {
        // code here
        num1 = reverse(num1);
        num2 = reverse(num2);
        // print(num1);
        // print(num2);
        struct Node *ans = new Node((num1->data + num2->data) % 10);
        struct Node *temp = ans;
        int borrow = (num1->data + num2->data) / 10;
        num1 = num1->next;
        num2 = num2->next;

        while (num1 && num2)
        {
            struct Node *newNode = new Node(0);
            newNode->data = ((num1->data + num2->data + borrow) % 10);
            borrow = (num1->data + num2->data + borrow) / 10;
            temp->next = newNode;
            temp = temp->next;
            num1 = num1->next;
            num2 = num2->next;
        }

        while (num1)
        {
            struct Node *newNode = new Node(0);
            newNode->data = ((num1->data + borrow) % 10);
            borrow = (num1->data + borrow) / 10;
            temp->next = newNode;
            temp = temp->next;
            num1 = num1->next;
        }
        while (num2)
        {
            struct Node *newNode = new Node(0);
            newNode->data = ((num2->data + borrow) % 10);
            borrow = (num2->data + borrow) / 10;
            temp->next = newNode;
            temp = temp->next;
            num2 = num2->next;
        }
        if (borrow)
        {
            struct Node *newNode = new Node(1);
            temp->next = newNode;
            temp = temp->next;
        }
        ans = reverse(ans);
        while (true)
        {
            if (!ans)
                break;
            if (ans->data == 0)
                ans = ans->next;
            else
                break;
        }
        if (!ans)
            return new Node(0);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;

        cin >> n;
        Node *num1 = buildList(n);

        cin >> m;
        Node *num2 = buildList(m);
        Solution ob;
        Node *res = ob.addTwoLists(num1, num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends