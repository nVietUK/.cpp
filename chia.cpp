#include <bits/stdc++.h>

using namespace std;
vector<int> Ar;
string s1,s2;
string S = "";

int len;
bool lonhon(string s1, string s2){
    if (s1.size() < s2.size())
        return false;
    if (s1.size() > s2.size())
        return true;
    for (int i = 0; i < min(s1.size(), s2.size()); i++)
        if (s1[i] < s2[i])
            return false;
        else 
        if (s1[i] > s2[i])
            return true;
    return true;
}
void Nhan(string s1, string s2){
    string tam = "";
    while (s1.size()){
        tam += s1[0]; s1.erase(0);
        if (lonhon(tam, s2))

    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("nhan.INP","r",stdin);
    //freopen("nhan.OUT","w",stdout);
    cin >> s1;
    cin >> s2;
    Ar.resize(0);
    if ((s1[0] == '-') && (s2[0] == '-')){
        s1.erase(s1.begin()); s2.erase(s2.begin());
    }
    else if (s1[0] == '-'){
        cout << "-";
        s1.erase(s1.begin());
    }
    else if (s2[0] == '-'){
        cout << "-";
        s2.erase(s2.begin());
    }
     Ar.resize(len = s1.length()+s2.length());
    Nhan(s1,s2);
    return 0;
}
