#include <stdio.h>
#include <algorithm>

using namespace std;
#define notTERMINAL true
#define FILENAME "caycongthuc"
#define intf "%d"

struct dinh {
    char dau = 0;
    int value = 0;
    dinh *trai, *phai;
    dinh() : dau(0), value(0), trai(NULL), phai(NULL) {};
};

dinh* makeTree() {
    auto myNode = new dinh; char cur = ' ';
    while (scanf("%c", &cur) != EOF)
    {
        switch (cur) {
            case ' ': continue; break;
            
            case '(': 
                if (myNode->trai == nullptr) 
                    myNode->trai = makeTree();
                else myNode->phai = makeTree();
                continue;
            break;

            case ')': 
                return myNode;
            break;
        }

        if (cur <= '9' && cur >= '0')
        {
            
            if (myNode->left == nullptr)
                 myNode->left = newNode(' ', stoi(s.substr(nPos, nnPos - nPos)));
            else myNode->right = newNode(' ', stoi(s.substr(nPos, nnPos - nPos)));
        }
        else 
            myNode->dau = cur;
    }
    return myNode;
}

signed main() {
#if notTERMINAL
#if not nVietUK 
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#else
    freopen("test.txt", "r", stdin);
#endif
#endif

    printf(tinh(makeTree(0)));
}