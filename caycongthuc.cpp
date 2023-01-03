#include <iostream>
#include <string>
#include <locale>

using namespace std;

typedef struct caycongthuc
{
    char dau = ' ';
    int value = 0;
    caycongthuc* left;
    caycongthuc* right;
} node;

node* newNode (char dau = ' ', int value = 0)
{
    node *temp = new node;
    temp->dau = dau;
    temp->value = value;
    return temp;
}

node* makeTree(string& s, unsigned pos)
{
    auto myNode = new node;
    for (int nPos = pos; nPos < s.size(); nPos++)
    {
        switch (s[nPos])
        {
        case ' ': continue;
            break;
        
        case '(': 
            if (myNode->left == nullptr) 
                 myNode->left = makeTree(s, nPos + 1);
            else myNode->right = makeTree(s, nPos + 1);
            --nPos;
            continue;
            break;

        case ')': 
            s.erase(pos - 1, nPos - pos + 3);
            return myNode;
            break;
        }

        if (isalnum(s[nPos]))
        {
            auto nnPos = nPos + 1; while (isalnum(s[nnPos])) nnPos++;
            if (myNode->left == nullptr)
                 myNode->left = newNode(' ', stoi(s.substr(nPos, nnPos - nPos)));
            else myNode->right = newNode(' ', stoi(s.substr(nPos, nnPos - nPos)));
        }
        else 
            myNode->dau = s[nPos];
    }
    return myNode;
}

long long tinh(node& input)
{
    if (input.value == 0)
        if (input.dau == '*')
            return tinh(*input.left) * tinh(*input.right);
        if (input.dau == '-')
            return tinh(*input.left) - tinh(*input.right);
        if (input.dau == '+')
            return tinh(*input.left) + tinh(*input.right);
        if (input.dau == '/')
            return tinh(*input.left) / tinh(*input.right);
        if (input.dau == '%')
            return tinh(*input.left) % tinh(*input.right);
    else 
        return input.value;
}

int main()
{
    string s;
    getline(cin, s);

    auto tree = makeTree(s, 0);

    cout << tinh(*tree);
}