#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }

public:
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }
};

Node *convertArr2DLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);

    Node *prev = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }

    return head;
}

Node *DeleteTail(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    Node *newtail = tail->back;
    newtail->next = nullptr;
    tail->back = nullptr;
    delete tail;

    return head;
}

Node *Deletehead(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    Node *prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;

    delete prev;

    return head;
}

// Delete the Kth ele of DLL

Node *DeleteKthele(Node *head, int k)
{
    // edge cases : empty , prev -> null , next -> null , both null

    if (head == NULL)
    {
        return NULL;
    }

    int cnt = 0;
    Node *knode = head;
    while (knode != NULL)
    {
        cnt++;

        if (cnt == k)
            break;
        knode = knode->next;
    }
        Node *prev = knode->back;
        Node *front = knode->next;

        if (prev == NULL && front == NULL)
        {
            return NULL;
        }

        else if (prev == NULL)
        {
            return Deletehead(head);
        }

        else if (front == NULL)
        {
            return DeleteTail(head);
        }

        else
        {
            prev->next = front;
            front->back = prev;
            knode->next = nullptr;
            knode->back = nullptr;

            delete knode;
        }

        return head;
    
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    vector<int> arr = {12, 5, 8, 7};
    Node *head = convertArr2DLL(arr);
    head = DeleteKthele(head, 1);
    print(head);
    return 0;
}