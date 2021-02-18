#include <iostream>

using namespace std;

struct Node
{
    int value;
    Node* left;
    Node* right;
    Node(int _value)
    {
        value = _value;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int value)
{
    Node* newNode = new Node(value);
    if (root == NULL)
    {
        root = newNode;
    }
    else
    {
        if (root->value > value)
        {
            root->left = insert(root->left, value);
        }
        else
        {
            root->right = insert(root->right, value);
        }
    }
    return root;
}

void traverseInOrder(Node *root)
{
	if (root != NULL)
	{
		traverseInOrder(root->left);
		cout << root->value << " ";
		traverseInOrder(root->right);
	}
}

void traversePreOrder(Node* root)
{
    if (root != NULL)
    {
        cout << root->value << " ";
        traversePreOrder(root->left);
        traversePreOrder(root->right);
    }
}

void traversePostOrder(Node* root)
{
    if (root != NULL)
    {
        traversePostOrder(root->left);
        traversePostOrder(root->right);
        cout << root->value << " ";
    }
}

Node* minNode(Node* root)
{
    if (!root) return root;
    else
    {
        Node* curr = root;
        while (curr->left)
        {
            curr = curr->left;
        }
        return curr;
    }
}

Node* removeNode(Node* root, int key)
{
    if(!root) return root;
    if(root->value < key)
    {
        root->right = removeNode(root->right, key);
    }
    else if(root->value > key)
    {
        root->left = removeNode(root->left, key);
    }
    else
    {
        // If deleted node have 1 child or no child
        if(!root->right)
        {
            Node* tmp = root->left; // if this is NULL, then it will return NULL
            delete root;
            return tmp;
        }
        else if (!root->left)
        {
            Node* tmp = root->right; // if this is NULL, then it will return NULL
            delete root;
            return tmp;
        }
        // node with two children: Get the inorder successor
        // (smallest in the right subtree)
        Node* tmp = minNode(root->right);

        // Copy the inorder successor's content to this node
        root->value = tmp->value;

        // Remove inorder succesor
        root->right = removeNode(root->right, tmp->value);
    }
    return root;
}

int maxDepth(Node* root)
{
    if (!root) return 0;
    else
    {
        int left_height = 1 + maxDepth(root->left);
        int right_height = 1 + maxDepth(root->right);
        if (left_height > right_height) return left_height;
        else return right_height;
    }
}

int main()
{
    int n, data, deletedValue;
    cin >> n;
    Node* root = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        root = insert(root, data);
    }
    cin >> deletedValue;
    cout << endl << "Height of Binary Tree: " << maxDepth(root) - 1 << endl;
    root = removeNode(root, deletedValue);
    traverseInOrder(root);
    cout << endl;
    traversePostOrder(root);
    cout << endl;
    traversePreOrder(root);
}
