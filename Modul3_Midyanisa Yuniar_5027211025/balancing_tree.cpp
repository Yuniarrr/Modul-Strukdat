#include <iostream>
using namespace std;

typedef struct Node
{
    int val;
    struct Node *left;
    struct Node *right;
    int ht;
} node;

int height(node *temp)
{
    int lh, rh;
    if (temp == NULL)
        return (0);
    if (temp->left == NULL)
        lh = 0;
    else
        lh = 1 + temp->left->ht;
    if (temp->right == NULL)
        rh = 0;
    else
        rh = 1 + temp->right->ht;
    if (lh > rh)
        return (lh);
    return (rh);
}

node *rotate_right(node *x)
{
    node *y;
    y = x->left;
    x->left = y->right;
    y->right = x;
    x->ht = height(x);
    y->ht = height(y);
    return (y);
}

node *rotate_left(node *x)
{
    node *y;
    y = x->right;
    x->right = y->left;
    y->left = x;
    x->ht = height(x);
    y->ht = height(y);
    return (y);
}

node *rr_rotation(node *parent)
{
    node *temp;
    temp = rotate_left(parent);
    return (temp);
}

node *ll_rotation(node *parent)
{
    node *temp;
    temp = rotate_right(parent);
    return (temp);
}

node *lr_rotation(node *parent)
{
    node *temp;
    temp = parent->left;
    parent->left = rotate_left(temp);
    temp = rotate_right(parent);
    return (temp);
}

node *rl_rotation(node *parent)
{
    node *temp;
    temp = parent->right;
    parent->right = rotate_right(temp);
    temp = rotate_left(parent);
    return (temp);
}

int bf(node *temp)
{
    int lh, rh;
    if (temp == NULL)
        return (0);
    if (temp->left == NULL)
        lh = 0;
    else
        lh = 1 + temp->left->ht;
    if (temp->right == NULL)
        rh = 0;
    else
        rh = 1 + temp->right->ht;
    return (lh - rh);
}

void preorder(node *temp)
{
    if (temp == NULL)
    {
        cout << "Tree is Empty" << endl;
        return;
    }
    cout << temp->val << " ";
    if (temp->left != NULL)
        preorder(temp->left);
    if (temp->right != NULL)
        preorder(temp->right);
}

void inorder(node *temp)
{
    if (temp == NULL)
    {
        cout << "Tree is Empty" << endl;
        return;
    }
    if (temp->left != NULL)
        inorder(temp->left);
    cout << temp->val << " ";
    if (temp->right != NULL)
        inorder(temp->right);
}

void postorder(node *temp)
{
    if (temp == NULL)
    {
        cout << "Tree is Empty" << endl;
        return;
    }
    if (temp->left != NULL)
        postorder(temp->left);
    if (temp->right != NULL)
        postorder(temp->right);
    cout << temp->val << " ";
}

node *insert(node *root, int val)
{
    if (root == NULL)
    {
        root = new node;
        root->val = val;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if (val < root->val)
    {
        root->left = insert(root->left, val);
        if (bf(root) == 2)
        {
            if (val < root->left->val)
                root = ll_rotation(root);
            else
                root = lr_rotation(root);
        }
    }
    else if (val > root->val)
    {
        root->right = insert(root->right, val);
        if (bf(root) == -2)
            if (val > root->right->val)
                root = rr_rotation(root);
            else
                root = rl_rotation(root);
    }
    root->ht = height(root);
    return root;
}

node *del(node *root, int val)
{
    node *p;
    if (root == NULL)
    {
        return NULL;
    }
    else if (val < root->val)
    {
        root->left = del(root->left, val);
        root = rr_rotation(root);
    }
    else if (val > root->val)
    {
        root->right = del(root->right, val);
        root = ll_rotation(root);
    }
    else
    {
        if (root->right != NULL)
        {
            p = root->right;
            while (p->left != NULL)
                p = p->left;
            root->val = p->val;
            root->right = del(root->right, p->val);
            if (bf(root) == 2)
            {
                if (bf(root->left) >= 0)
                    root = ll_rotation(root);
                else
                    root = lr_rotation(root);
            }
        }
        else
            return (root->left);
    }
    root->ht = height(root);
    return root;
}

int main()
{
    node *root = NULL;
    int val, ch;
    cin >> ch;
    for (int i = 0; i < ch; i++)
    {
        cin >> val;
        root = insert(root, val);
    }
    int newVal;
    cin >> newVal;
    root = insert(root, newVal);

    cout << "Preorder Traversal:" << endl;
    preorder(root);
    return 0;
}
