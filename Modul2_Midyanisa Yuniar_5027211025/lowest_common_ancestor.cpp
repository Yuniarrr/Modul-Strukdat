#include <iostream>

using namespace std;

struct node {
    int data;
    node *left;
    node *right;
};

node *lca(node *root, int v1, int v2)
{
    if (root == NULL)
        return NULL;

    if (root->data > v1 && root->data > v2)
        return lca(root->left, v1, v2);

    if (root->data < v1 && root->data < v2)
        return lca(root->right, v1, v2);

    return root;
}

node *newNode(int data)
{
    node *Node = new node();
    Node->data = data;
    Node->left = Node->right = NULL;
    return (Node);
}

int main()
{
    int num_node;
    cin >> num_node;

    int data;
    cin >> data;

    node *root = newNode(data);

    for (int j = 1; j < num_node; j++)
    {
        cin >> data;
        node *temp = root;
        while (temp != NULL)
        {
            if (data < temp->data)
            {
                if (temp->left == NULL)
                {
                    temp->left = newNode(data);
                    break;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                if (temp->right == NULL)
                {
                    temp->right = newNode(data);
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }

    int v1, v2;
    cin >> v1 >> v2;

    node *t = lca(root, v1, v2);
    cout << "Lowest Common Ancestor " << v1 << " dan " << v2 << ": " << t->data << endl;
    return 0;
}
