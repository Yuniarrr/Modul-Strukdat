#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

// 
int count = 0;

// AVL Tree
struct AVLNode
{
    int data;
    AVLNode *left, *right;
    int height;
};

struct AVL
{
private:
    AVLNode *_root;
    unsigned _size;

    // Fungsi untuk membuat node baru
    AVLNode *_avl_createNode(int value)
    {
        AVLNode *newNode = (AVLNode *)malloc(sizeof(AVLNode));
        newNode->data = value;
        newNode->height = 1;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    // Fungsi untuk mencari node
    AVLNode *_search(AVLNode *root, int value)
    {
        // Jika root != kosong
        while (root != NULL)
        {
            // Jika value < root->data, maka cari di kiri
            if (value < root->data)
                root = root->left;
            // Jika value > root->data, maka cari di kanan
            else if (value > root->data)
                root = root->right;
            else
                return root;
        }
        return root;
    }

    // Fungsi untuk mencari tinggi node
    int _getHeight(AVLNode *node)
    {
        // Jika node kosong, maka tinggi = 0
        if (node == NULL)
            return 0;
        // Jika tidak kosong, maka tinggi = node->height
        return node->height;
    }

    // Fungsi untuk mencari nilai maksimum
    int _max(int a, int b)
    {
        return (a > b) ? a : b;
    }

    // Fungsi untuk melakukan rotasi kanan
    AVLNode *_rightRotate(AVLNode *pivotNode)
    {
        cout << "\tDilakukan rotasi kanan dengan pivot node " << pivotNode->data << ")" << endl;

        AVLNode *newParrent = pivotNode->left;
        pivotNode->left = newParrent->right;
        newParrent->right = pivotNode;

        pivotNode->height = _max(_getHeight(pivotNode->left),
                                 _getHeight(pivotNode->right)) +
                            1;
        newParrent->height = _max(_getHeight(newParrent->left),
                                  _getHeight(newParrent->right)) +
                             1;

        return newParrent;
    }

    // Fungsi untuk melakukan rotasi kiri
    AVLNode *_leftRotate(AVLNode *pivotNode)
    {
        cout << "\tDilakukan rotasi kiri dengan pivot node " << pivotNode->data << ")" << endl;
        AVLNode *newParrent = pivotNode->right;
        pivotNode->right = newParrent->left;
        newParrent->left = pivotNode;

        pivotNode->height = _max(_getHeight(pivotNode->left),
                                 _getHeight(pivotNode->right)) +
                            1;
        newParrent->height = _max(_getHeight(newParrent->left),
                                  _getHeight(newParrent->right)) +
                             1;

        return newParrent;
    }

    AVLNode *_leftCaseRotate(AVLNode *node)
    {
        return _rightRotate(node);
    }

    AVLNode *_rightCaseRotate(AVLNode *node)
    {
        return _leftRotate(node);
    }

    // Fungsi untuk melakukan rotasi kiri-kanan
    AVLNode *_leftRightCaseRotate(AVLNode *node)
    {
        node->left = _leftRotate(node->left);
        return _rightRotate(node);
    }

    // Fungsi untuk melakukan rotasi kanan-kiri
    AVLNode *_rightLeftCaseRotate(AVLNode *node)
    {
        node->right = _rightRotate(node->right);
        return _leftRotate(node);
    }

    // Fungsi untuk mencari balance factor
    int _getBalanceFactor(AVLNode *node)
    {
        if (node == NULL)
            return 0;
        return _getHeight(node->left) - _getHeight(node->right);
    }

    // Fungsi untuk melakukan insert node
    AVLNode *_insert_AVL(AVLNode *node, int value)
    {

        if (node == NULL)
            return _avl_createNode(value);
        if (value < node->data)
            node->left = _insert_AVL(node->left, value);
        else if (value > node->data)
            node->right = _insert_AVL(node->right, value);

        node->height = 1 + _max(_getHeight(node->left), _getHeight(node->right));

        int balanceFactor = _getBalanceFactor(node);

        if (balanceFactor > 1 && value < node->left->data)
        {
            cout << "Ketika insert node " << value << endl;
            cout << "\tSubtree " << node->data << " tidak seimbang BF = " << balanceFactor << " (Kondisi BF > 1 dan subtree kiri > subtree kanan)" << endl;
            return _leftCaseRotate(node);
        }
        if (balanceFactor > 1 && value > node->left->data)
        {
            cout << "Ketika insert node " << value << endl;
            cout << "\tSubtree " << node->data << " tidak seimbang BF = " << balanceFactor << " (Kondisi BF > 1 dan subtree kiri < subtree kanan)" << endl;
            return _leftRightCaseRotate(node);
        }
        if (balanceFactor < -1 && value > node->right->data)
        {
            cout << "Ketika insert node " << value << endl;
            cout << "\tSubtree " << node->data << " tidak seimbang BF = " << balanceFactor << " (Kondisi BF < -1 dan subtree kiri < subtree kanan)" << endl;
            return _rightCaseRotate(node);
        }
        if (balanceFactor < -1 && value < node->right->data)
        {
            cout << "Ketika insert node " << value << endl;
            cout << "\tSubtree " << node->data << " tidak seimbang BF = " << balanceFactor << " (Kondisi BF < -1 dan subtree kiri > subtree kanan)" << endl;
            return _rightLeftCaseRotate(node);
        }

        return node;
    }

    // Fungsi untuk mencari node terkecil
    AVLNode *_findMinNode(AVLNode *node)
    {
        AVLNode *currNode = node;
        while (currNode && currNode->left != NULL)
            currNode = currNode->left;
        return currNode;
    }

    // Fungsi untuk melakukan remove node
    AVLNode *_remove_AVL(AVLNode *node, int value)
    {
        if (node == NULL)
            return node;
        if (value > node->data)
            node->right = _remove_AVL(node->right, value);
        else if (value < node->data)
            node->left = _remove_AVL(node->left, value);
        else
        {
            AVLNode *temp;
            if ((node->left == NULL) || (node->right == NULL))
            {
                temp = NULL;
                if (node->left == NULL)
                    temp = node->right;
                else if (node->right == NULL)
                    temp = node->left;

                if (temp == NULL)
                {
                    temp = node;
                    node = NULL;
                }
                else
                    *node = *temp;

                free(temp);
            }
            else
            {
                temp = _findMinNode(node->right);
                node->data = temp->data;
                node->right = _remove_AVL(node->right, temp->data);
            }
        }

        if (node == NULL)
            return node;

        node->height = _max(_getHeight(node->left), _getHeight(node->right)) + 1;

        int balanceFactor = _getBalanceFactor(node);

        if (balanceFactor > 1 && _getBalanceFactor(node->left) >= 0)
        {
            cout << "Ketika delete node " << value << endl;
            cout << "\tSubtree " << node->data << " tidak seimbang BF = " << balanceFactor << " (Kondisi BF > 1 dan subtree kiri > subtree kanan)" << endl;
            return _leftCaseRotate(node);
        }

        if (balanceFactor > 1 && _getBalanceFactor(node->left) < 0)
        {

            cout << "Ketika delete node " << value << endl;
            cout << "\tSubtree " << node->data << " tidak seimbang BF = " << balanceFactor << " (Kondisi BF > 1 dan subtree kiri < subtree kanan)" << endl;
            return _leftRightCaseRotate(node);
        }

        if (balanceFactor < -1 && _getBalanceFactor(node->right) <= 0)
        {

            cout << "Ketika delete node " << value << endl;
            cout << "\tSubtree " << node->data << " tidak seimbang BF = " << balanceFactor << " (Kondisi BF < -1 dan subtree kiri < subtree kanan)" << endl;
            return _rightCaseRotate(node);
        }

        if (balanceFactor < -1 && _getBalanceFactor(node->right) > 0)
        {

            cout << "Ketika delete node " << value << endl;
            cout << "\tSubtree " << node->data << " tidak seimbang BF = " << balanceFactor << " (Kondisi BF < -1 dan subtree kiri > subtree kanan)" << endl;
            return _rightLeftCaseRotate(node);
        }

        return node;
    }

    // Fungsi untuk melakukan traversal inorder
    void _inorder(AVLNode *node)
    {
        if (node)
        {
            _inorder(node->left);
            cout << node->data << " ";
            _inorder(node->right);
        }
    }

    // Fungsi untuk melakukan traversal preorder
    void _preorder(AVLNode *node)
    {
        if (node)
        {
            cout << node->data << " ";
            _preorder(node->left);
            _preorder(node->right);
        }
    }

    // Fungsi untuk melakukan traversal postorder
    void _postorder(AVLNode *node)
    {
        if (node)
        {
            _postorder(node->left);
            _postorder(node->right);
            cout << node->data << " ";
        }
    }

public:
    // Constructor
    void init()
    {
        _root = NULL;
        _size = 0U;
    }

    // Fungsi untuk mengecek apakah tree kosong
    bool isEmpty()
    {
        return _root == NULL;
    }

    // Fungsi untuk mencari node
    bool find(int value)
    {
        AVLNode *temp = _search(_root, value);
        if (temp == NULL)
            return false;

        if (temp->data == value)
            return true;
        else
            return false;
    }

    // Fungsi untuk melakukan insert node
    void insert(int value)
    {
        if (!find(value))
        {
            _root = _insert_AVL(_root, value);
            _size++;
        }
    }

    // Fungsi untuk melakukan remove node
    void remove(int value)
    {
        if (find(value))
        {
            _root = _remove_AVL(_root, value);
            _size--;
        }
    }

    // Fungsi untuk melakukan traversal inorder
    void inorder()
    {
        this->_inorder(_root);
    }

    // Fungsi untuk melakukan traversal preorder
    void preorder()
    {
        this->_preorder(_root);
    }

    // Fungsi untuk melakukan traversal postorder
    void postorder()
    {
        this->_postorder(_root);
    }
};

int main()
{
    // Buat objek AVL
    AVL avl_tree;

    // Panggil fungsi init
    avl_tree.init();

    int jum_query, value;
    string comm;

    // Input jumlah query
    cin >> jum_query;

    // Looping sebanyak jumlah query
    while (jum_query--)
    {
        // Input command
        cin >> comm;
        if (comm == "insert")
        {
            cin >> value;
            avl_tree.insert(value);
        }
        else if (comm == "delete")
        {
            cin >> value;
            avl_tree.remove(value);
        }
        else if (comm == "inOrder")
        {
            avl_tree.inorder();
        }
        else if (comm == "preOrder")
        {
            avl_tree.preorder();
        }
        else if (comm == "postOrder")
        {
            avl_tree.postorder();
        }
    }

    return 0;
}