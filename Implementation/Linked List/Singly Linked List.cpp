#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int v);
};

Node::Node(int v)
{
    data = v;
    next = NULL;
}

Node* append(Node* head, int data)
{
    Node* newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        return head;
    }
    else
    {
        Node* p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = newNode;
        return head;
    }
}

Node* insertElement(Node* head, int data, int pos)
{
    Node* newNode = new Node(data);
    if (pos == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }
    else
    {
        Node* p = head;
        while (p->next != NULL && pos-- > 1)
        {
            p = p->next;
        }
        if (p->next == NULL)
        {
            p->next = newNode;
            return head;
        }
        else
        {
            newNode->next = p->next;
            p->next = newNode;
            return head;
        }
    }
}

Node* deleteElement(Node* head, int data)
{
    if(!head) return head;
    else
    {
        Node* p = head;
        while (p->next && p->next->data != data)
        {
            p = p->next;
        }
        if (p->next == NULL) return head;
        else
        {
            Node* tmp = p->next;
            p->next = p->next->next;
            delete tmp;
            return head;
        }
    }
}

void display(Node* head)
{
    for (Node* p = head; p != NULL; p = p->next)
    {
        cout << p->data << " ";
    }
    cout << endl;
}

int main()
{
    int x;
    Node* head = NULL;
    while (cin >> x)
    {
        head = append(head, x);
    }
    head = insertElement(head, 4, 3);
    display(head);
    head = deleteElement(head, 6);
    display(head);
}
