#include <bits/stdc++.h>

using namespace std;
int i;

bool check(string& in){
    for (unsigned pos = 0; pos < in.size()/2; pos++)
        if (in[pos] != in[in.size()-1-pos])
            return false;
    return true;
}

void process(){
    unsigned n; cin >> n;
    vector<string> ts(n);
    for (string& ele : ts)
        cin >> ele;
    map<string, unsigned long long> mos;
    set<string> sos;
    for (i = 0; i < n; i++){
        if (check(ts[i])){
            cout << "YES" << "\n";
            return;
        }
        else{
            mos[ts[i]]++;
            if (sos.find(ts[i]) != sos.end()){
                cout << "YES" << "\n";
                return;
            }
            string s = ts[i].substr(1);
            reverse(s.begin(), s.end());
            if (mos[s] > 0){
                cout << "YES" << "\n";
                return;
            }
            if (ts[i].length() == 3){
                s = "";
                s += ts[i][1];
                s += ts[i][0];
                sos.insert(s);
            }
            reverse(ts[i].begin(), ts[i].end());
            if (mos[ts[i]]){
                cout << "YES" << "\n";
                return;
            }
        }
    }
    cout << "NO" << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    unsigned t; cin >> t;
    while (t--){
        process();
    }
}