#include <bits/stdc++.h>

using namespace std;

typedef struct caycongthuc
{
    string dau = " ";
    int value = 0;
    caycongthuc* left = nullptr;
    caycongthuc* right = nullptr;
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

node* makeTree(string dau)
{
    auto myNode = new node;
    myNode->dau = dau;
    string s;
    while (cin >> s)
    {
        if (isNumber(s))
        {
            if (
                (myNode->left == nullptr) &&
                (
                    (myNode->dau == " ") ||
                    (myNode->dau == "abs") ||
                    (myNode->dau == "max") ||
                    (myNode->dau == "min")
                )
            )
                myNode->left = newNode("@", stoi(s));
            else if (myNode->right == nullptr) 
                myNode->right = newNode("@", stoi(s));
        }
        else 
        {
            if (
                (s == ")") ||
                (s == ",")
            )
                return myNode;
            if (
                (s == "max(") ||
                (s == "min(") ||
                (s == "abs(") ||
                (s == "(")
            )
            {
                dau = s.substr(0, 3);
                if (s != "(") 
                {
                    myNode->left = makeTree(dau);
                    if (dau != "abs")
                        myNode->left->right = makeTree(" ");
                }
                else 
                {
                    if (myNode->left == nullptr) 
                        myNode->left = makeTree((dau != "(") ? dau : " ");
                    else if (myNode->right == nullptr) 
                        myNode->right = makeTree((dau != "(") ? dau : " ");
                }
            }
            else 
            {
                if (myNode->dau == " ")
                    myNode->dau = s;
                else 
                {
                    if ((s == "*") || (s == "/") || (s == "%")) 
                    {
                        string c(s); cin >> s;
                        auto nNode = new node;
                        nNode->dau = c;
                        if (isNumber(s))
                            nNode->right = newNode("@", stoi(s));
                        else if (s == "(")
                        nNode->right = makeTree(" ");
                        nNode->left = myNode->right;
                        myNode->right = nNode;       
                    }
                    else 
                    {
                        string c(s); cin >> s;
                        node* nNode = new node;
                        nNode->dau = c;
                        if (isNumber(s))
                            nNode->right = newNode("@", stoi(s));
                        else if (s == "(")
                            nNode->right = makeTree(" ");
                        nNode->left = myNode;
                        swap(nNode, myNode);
                    }
                }
            }
        }
    }
    return myNode;
}

void tinh(node& input)
{
    if (
        (input.dau != " ") && 
        (input.dau != "@")
    )
    {
        if (input.left != nullptr) tinh(*input.left);
        else 
        {
            cout << input.dau;
            input.dau = "";
        }
        if (input.right != nullptr) tinh(*input.right);
        if (input.left != nullptr) cout << input.dau << " ";
    }
    else 
    if (input.left != nullptr)
        tinh(*input.left);
    else 
        cout << input.value << " ";
}

void xuly(string& in);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream filein;
    ofstream fileou;

    filein.open("t2h.INP");
    string s; getline(filein, s);
    filein.close();

    xuly(s);

    fileou.open("t2h.inp");
    fileou.clear();
    fileou << s;
    fileou.close();

    freopen("t2h.INP","r",stdin);
    freopen("t2h.OUT","w",stdout);

    tinh(*makeTree(" "));
}

void xuly(string& in)
{
    for (auto i = 0; i < in.size()-1; i++)
        if (
            (in[i+1] == ' ') || 
            ((isdigit(in[i]) != 0) && (isdigit(in[i+1]) != 0)) ||
            ((isalpha(in[i]) != 0) && (isalpha(in[i+1]) != 0)) ||
            ((isalpha(in[i]) != 0) && (in[i+1] == '('))
        )
        {
            if (in[i+1] == ' ') i++;
            continue;
        }
        else 
        {
            in.insert(in.begin()+i+1, ' ');
            i++;
        }
}