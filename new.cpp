#include <iostream>
#include <string>
#include "windows.h"

using namespace std;

int main(int args, char* path[]) 
{
    //auto input = path[1].substr(5).insert(*path->begin() + 1, ":");
    string input = path[1];
    input = input.substr(5);
    input.insert(input.begin() + 1, ':');
    input = "/mnt/c/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/bin/g++.exe " + input + " -o " + (input.substr(*input.begin(), *input.end() - 3) + ".exe");
    WinExec(input);
}