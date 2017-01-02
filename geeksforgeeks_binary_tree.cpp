#include <bits/stdc++.h>

using namespace std;

typedef struct _node
{
    struct _node *left;
    struct _node *right;
    long long int key = numeric_limits<long long int>::max();
} node;

void insert_node(node *root, long long int val)
{
    if(root->key == numeric_limits<long long int>::max())
    {
        root->key = val;
        root->left = NULL;
        root->right = NULL;
        return;
    }
    if (val > root->key)
    {
        if (root->right != NULL)
            insert_node(root->right, val);
        else
        {
            node *child = new node;
            root->right = child;
            child->right = NULL;
            child->left = NULL;
            child->key = val;
        }
    }

    else if (val < root->key)
    {
        if (root->left != NULL)
            insert_node(root->left, val);
        else
        {
            node *child = new node;
            root->left = child;
            child->right = NULL;
            child->left = NULL;
            child->key = val;
        }
    }
}

void inorder_traversal(node *root)
{
    if (root->left != NULL)
        inorder_traversal(root->left);
    std::cout << root->key << " ";
    if (root->right != NULL)
        inorder_traversal(root->right);
}

void invert_tree(node *root)
{
    if (root != NULL)
    {
        node *temp = root->left;
        root->left = root->right;
        root->right = temp;
        if (root->left != NULL)
            invert_tree(root->left);
        if (root->right != NULL)
            invert_tree(root->right);
    }
    else
        return;
}

long long int diameter(node *root)
{
    // TBD
    return 0;
}

int main()
{
    long long int nodes;
    cin >> nodes;
    node *root = new node;
    for (long long int i = 0; i < nodes; i++)
    {
        long long int val;
        cin>>val;
        insert_node(root, val);
    }
    inorder_traversal(root);
    std::cout << std::endl;
    invert_tree(root);
    inorder_traversal(root);
    std::cout << std::endl;
}
