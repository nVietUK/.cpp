#include <bits/stdc++.h>
#include<dirent.h>

using namespace std;

int main()
{
    struct dirent *d;
    DIR *dr;
    dr = opendir(".");
    if(dr!=NULL)
    {
        cout<<"List of Files & Folders:-\n";
        for(d=readdir(dr); d!=NULL; d=readdir(dr))
        {
            cout<<d->d_name<<endl;
            string s = d->d_name;
            string so = "";
            while (isdigit(s[s.size()-1])) 
                { so.push_back(s[s.size()-1]); s.erase(s.end()); };
            if (s.find(".AN") > -1)
            {
                
            }
            else 
            if (s.find(".IN") > -1)
        }
        closedir(dr);
    }
    else
        cout<<"\nError Occurred!";
    cout<<endl;
    return 0;
}