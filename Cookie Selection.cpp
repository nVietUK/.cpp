#include <iostream>
#include <vector>
#include <iterator>
#include <string>

using namespace std;

int main()
{
    std::istream_iterator<std::string> eos, itr(std::cin);

    std::vector<std::string> lines;


    string in;
    unsigned st = 0;
    vector<string> ta;
    while (getline(cin, in) && !in.empty())
    {
        if (in == "")
            break;
        if (in =="#")
        {
            st--;
            unsigned po;
            if (ta.size() % 2)
                po = (ta.size() + 1) / 2 - 1;
            else 
                po = ta.size() / 2;
            cout << ta[po] << endl;
            ta.erase(ta.begin() + po);
        }
        else 
        {
            st++;
            ta.push_back(in);
        }
    }
}