// InvertBinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <vector>

class Node
{
public:
    Node* left;
    Node* right;
    int data;

    Node(int d)
        : data(d)
        , left(nullptr)
        , right(nullptr)
    {}
};

Node* ArrayToTree(const std::vector<int>& v)
{
    if (v.size() == 0)
        return nullptr;
    Node* root = new Node(v[0]);
    std::queue<Node*> q;
    q.push(root);
    bool l = true;
    for (size_t i = 1; i < v.size(); ++i, l = !l)
    {
        Node* pNode = q.front();
        if (!l)
            q.pop();
        if (v[i] != -1)
        {
            if (l)
            {
                pNode->left = new Node(v[i]);
                q.push(pNode->left);
            }
            else
            {
                pNode->right = new Node(v[i]);
                q.push(pNode->right);
            }
        }
    }

    return root;
}

void FreeTree(Node* pNode)
{
    if (pNode == nullptr)
        return;

    FreeTree(pNode->left);
    FreeTree(pNode->right);

    delete pNode;
}

void InvertTree(Node* root)
{
    if (root == nullptr)
        return;

    InvertTree(root->left);
    InvertTree(root->right);
    std::swap(root->left, root->right);
}

void PrintTreeLevelOrder(std::vector<Node*>& vec)
{
    if (vec.empty())
        return;

    std::vector<Node*> v;
    std::cout << vec[0]->data;
    if (vec[0]->left != nullptr)
        v.push_back(vec[0]->left);
    if (vec[0]->right != nullptr)
        v.push_back(vec[0]->right);

    for (size_t i = 1; i < vec.size(); ++i)
    {
        std::cout << ", " << vec[i]->data;
        if (vec[i]->left != nullptr)
            v.push_back(vec[i]->left);
        if (vec[i]->right != nullptr)
            v.push_back(vec[i]->right);
    }

    if (!v.empty())
        std::cout << ", ";

    PrintTreeLevelOrder(v);
}

void PrintTreeLevelOrder(Node* pNode)
{
    std::vector<Node*> vec;
    vec.push_back(pNode);
    PrintTreeLevelOrder(vec);
    std::cout << std::endl << std::endl;
}

int main()
{
    while (true)
    {
        std::cout << "Number of nodes in the tree: ";
        int count = 0;
        std::cin >> count;
        if (count == 0)
            break;

        std::cout << "Values of the tree nodes: ";
        std::vector<int> v(count, 0);
        for (int i = 0; i < count; ++i)
            std::cin >> v[i];

        Node* root = ArrayToTree(v);

        InvertTree(root);

        PrintTreeLevelOrder(root);

        FreeTree(root);
    }
}
