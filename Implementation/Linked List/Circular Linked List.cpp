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

Node* addToEmpty(Node* last, int data)
{
    if (last != NULL) return last;
    Node* newNode = new Node(data);
    last = newNode;
    last->next = last;
    return last;
}

Node* addBegin(Node* last, int data)
{
    if (last == NULL) return addToEmpty(last, data);
    Node* newNode = new Node(data);
    newNode->next = last->next;
    last->next = newNode;
    return last;
}

Node* addEnd(Node* last, int data)
{
    if (last == NULL) return addToEmpty(last, data);
    Node* newNode = new Node(data);
    newNode->next = last->next;
    last->next = newNode;
    last = newNode;
    return last;
}

Node* addAfter(Node* last, int data, int key)
{
    if (last == NULL) return last;
    if (last->data == key)
    {
        return addEnd(last, data);
    }
    Node* p = last->next;
    while (p != last)
    {
        if (p->data == key)
        {
            return addEnd(p, data);
        }
        p = p->next;
    }
    cout << key << " not present in the list." << endl;
    return last;
}

Node* deleteElement(Node* last, int key)
{
    if (last == NULL) return last;
    Node* p = last->next;
    do
    {
        if(p->next->data == key)
        {
            Node* tmp = p->next;
            p->next = p->next->next;
            delete tmp;
            break;
        }
        p = p->next;
    }
    while(p != last->next);
    return last;
}

void traverse(Node* last)
{
    if (last == NULL) return;
    Node* p = last->next;
    do
    {
        cout << p -> data << " ";
        p = p -> next;
    }
    while(p != last->next);
}

int main()
{
    Node* last = NULL;
    last = addToEmpty(last, 6);
    last = addBegin(last, 4);
    last = addBegin(last, 2);
    last = addEnd(last, 8);
    last = addEnd(last, 12);
    last = addAfter(last, 10, 8);
    last = deleteElement(last, 6);
    traverse(last);
}
