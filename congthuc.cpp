#include <bits/stdc++.h>

using namespace std;

typedef struct caycongthuc
{
    string dau = " ";
    int value = 0;
    caycongthuc* left;
    caycongthuc* right;
} node;

node* newNode (string dau = " ", int value = 0)
{
    node *temp = new node;
    temp->dau = dau;
    temp->value = value;
    return temp;
}

bool isNumber(string& input)
{
    unsigned i = 0; while (isdigit(input[i])) i++;
    return i == input.size();
}

node* makeTree()
{
    auto myNode = new node;
    string s;
    while (cin >> s)
    {
        if (isNumber(s))
        {
            if (myNode->left == nullptr)
                myNode->left = newNode(" ", stoi(s));
            else if (myNode->right == nullptr) 
                myNode->right = newNode(" ", stoi(s));
        }
        else 
            switch (s[0])
            {
            case '(': 
                if (myNode->left == nullptr) 
                    myNode->left = makeTree();
                else if (myNode->right == nullptr) 
                    myNode->right = makeTree();
                continue;
                break;

            case ')': 
                return myNode;
                break;
            default: 
                if (myNode->dau == " ")
                    myNode->dau = s;
                else 
                    if ((s == "*") || (s == "/") || (s == "%")) 
                    {
                        string c(s); cin >> s;
                        auto nNode = new node;
                        nNode->dau = c;
                        if (isNumber(s))
                            nNode->right = newNode(" ", stoi(s));
                        else if (s == "(")
                        nNode->right = makeTree();
                        nNode->left = myNode->right;
                        myNode->right = nNode;       
                    }
                    else 
                    {
                        string c(s); cin >> s;
                        node* nNode = new node;
                        nNode->dau = c;
                        if (isNumber(s))
                            nNode->right = newNode(" ", stoi(s));
                        else if (s == "(")
                            nNode->right = makeTree();
                        nNode->left = myNode;
                        swap(nNode, myNode);
                    }

            }
    }
    return myNode;
}

double tinh(node& input)
{
    if (input.value == 0)
        if (input.dau.compare("*") == 0)
            return tinh(*input.left) * tinh(*input.right);
        if ((input.dau.compare("-") == 0) || (input.dau.compare("–") == 0))
            return tinh(*input.left) - tinh(*input.right);
        if (input.dau.compare("+") == 0)
            return tinh(*input.left) + tinh(*input.right);
        if (input.dau.compare("/") == 0)
            return tinh(*input.left) / tinh(*input.right);
        if (input.dau.compare("%") == 0)
            return (int)tinh(*input.left) % (int)tinh(*input.right);
    else 
        return input.value;
}

int main()
{
    freopen("CONGTHUC.INP","r",stdin);
    freopen("CONGTHUC.OUT","w",stdout);

    auto tree = makeTree();

    cout << tinh(*tree);
}