#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
    Node(int val);
}*head, *tail;

Node::Node(int val)
{
    data = val;
    next = NULL;
    prev = NULL;
}

Node* appendNode(int data)
{
    Node* newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return head;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        return head;
    }
}

Node* insertNode(int data, int pos)
{
    Node* newNode = new Node(data);
    if (pos == 0)
    {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
        return head;
    }
    else
    {
        Node* p = head;
        while (p != tail && pos-- > 1)
        {
            p = p->next;
        }
        if (p != tail)
        {
            newNode->next = p->next;
            p->next->prev = newNode;
            p->next = newNode;
            newNode->prev = p;
            return head;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            return head;
        }
    }
}

Node* deleteNode(int key)
{
    if (head != NULL)
    {
        Node* p = head;
        while (p != tail && p->next->data != key)
        {
            p = p->next;
        }
        if (p == tail) return head;
        Node* tmp = p->next;
        p->next = p->next->next;
        p->next->prev = p;
        delete tmp;
    }
    return head;
}

void printList()
{
    Node* last, *node = head;
    cout << "\nTraversal in forward direction \n";
    while(node != NULL)
    {
        cout << " " << node->data << " ";
        last = node;
        node = node->next;
    }

    cout << "\nTraversal in reverse direction \n";
    while(last != NULL)
    {
        cout << " " << last->data << " ";
        last = last->prev;
    }
    cout << endl;
}

int main()
{
    head = NULL;
    int x;
    while (cin >> x)
    {
        head = appendNode(x);
    }
    head = insertNode(7, 2);
    printList();
    head = deleteNode(9);
    printList();
}
