#include <iostream>
using namespace std;

typedef struct Node
{
    int key;
    int left_childs;
    int height;
    struct Node *left;
    struct Node *right;
} node;

node *create_node(int key)
{
    node *new_node = new node;
    new_node->key = key;
    new_node->left_childs = 0;
    new_node->height = 0;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

typedef struct AVL
{
    node *root;
} avl;

avl *create_avl()
{
    avl *new_avl = new avl;
    new_avl->root = NULL;
    return new_avl;
}

int height(node *temp)
{
    if (temp == NULL)
    {
        return -1;
    }
    return temp->height;
}

int getBalaceFactor(node *temp)
{
    if (temp == NULL)
    {
        return 0;
    }
    return height(temp->left) - height(temp->right);
}

node *rotate_right(node *x)
{
    x->left_childs -= (x->left->left_childs + 1);
    node *l = x->left;
    node *lr = l->right;
    l->right = x;
    x->left = lr;

    int max1, max2;
    if (height(x->right) >= height(x->left))
    {
        max1 = height(x->right);
    }
    else
    {
        max1 = height(x->left);
    }
    x->height = max1 + 1;

    if (height(l->right) >= height(l->left))
    {
        max2 = height(l->right);
    }
    else
    {
        max2 = height(l->left);
    }
    l->height = max2 + 1;

    return l;
}

node *rotate_left(node *x)
{
    node *r = x->right;
    node *rl = r->left;
    r->left = x;
    x->right = rl;

    int max1, max2;
    if (height(x->right) >= height(x->left))
    {
        max1 = height(x->right);
    }
    else
    {
        max1 = height(x->left);
    }
    x->height = max1 + 1;

    if (height(r->right) >= height(r->left))
    {
        max2 = height(r->right);
    }
    else
    {
        max2 = height(r->left);
    }
    r->height = max2 + 1;

    r->left_childs += (x->left_childs + 1);

    return r;
}

node *inserthelper(node *root, int key)
{
    if (root == NULL)
    {
        return create_node(key);
    }

    if (key < root->key)
    {
        root->left_childs++;
        root->left = inserthelper(root->left, key);
    }
    else
    {
        root->right = inserthelper(root->right, key);
    }

    int alt1 = height(root->left);
    int alt2 = height(root->right);
    int max;
    if (alt1 >= alt2)
    {
        max = alt1;
    }
    else
    {
        max = alt2;
    }
    root->height = max + 1;

    int balance = getBalaceFactor(root);
    if (balance > 1 && key < root->left->key)
    {
        return rotate_right(root);
    }
    if (balance < -1 && key >= root->right->key)
    {
        return rotate_left(root);
    }
    if (balance > 1 && key >= root->left->key)
    {
        root->left = rotate_left(root->left);
        return rotate_right(root);
    }
    if (balance < -1 && key < root->right->key)
    {
        root->right = rotate_right(root->right);
        return rotate_left(root);
    }
    return root;
}

void insert(avl *tree, int key)
{
    tree->root = inserthelper(tree->root, key);
}

int findhelper(node *root, int key, int x)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->key == key)
    {
        return x + root->left_childs;
    }
    if (key < root->key)
    {
        return findhelper(root->left, key, x);
    }
    else
    {
        x += (root->left_childs + 1);
        return findhelper(root->right, key, x);
    }
}

int find(avl *tree, int key)
{
    return findhelper(tree->root, key, 0);
}

int main()
{
    int qtd;
    cin >> qtd;
    avl *tree = create_avl();
    for (int i = 0; i < qtd; i++)
    {
        int type;
        int num;
        cin >> type >> num;
        if (type == 1)
        {
            insert(tree, num);
        }
        else if (type == 2)
        {
            int index = find(tree, num);
            int v = index + 1;
            if (index == -1)
            {
                cout << "Data tidak ada" << endl;
            }
            else
            {
                cout << v << endl;
            }
        }
    }
    return 0;
}