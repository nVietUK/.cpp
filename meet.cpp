#include <Windows.h>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    FreeConsole();
    string s = "\"C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe\" meet.google.com/";
    for (auto i = 6; i < (unsigned)strlen(argv[1]); i++) s += argv[1][i];


    freopen("C:\\Users\\vietu\\Desktop\\Project1\\Project1\\exe\\meet.bat", "w", stdout);
    cout << "@echo off" << endl;
    cout << s << endl;
    cout << "exit" ;
    fclose(stdout);
	
    system("start /min C:\\Users\\vietu\\Desktop\\Project1\\Project1\\exe\\meet.bat || exit");
	return 0;
}