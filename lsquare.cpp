#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

struct lineAndVector
{
	unsigned x = 0;
	vector<unsigned> y = {};
};

unsigned findLine(unsigned& x, vector<lineAndVector>& table);
unsigned findElem(unsigned x, vector<unsigned>& table);
bool tableElemComp(lineAndVector& a, lineAndVector& b);

int main()
{
	freopen("lsquare.inp", "r", stdin);
	freopen("lsquare.out", "w", stdout);

	unsigned countOfLine;
	cin >> countOfLine;

	unsigned x, y;
	vector<lineAndVector> table;
	while (countOfLine--)
	{
		cin >> x >> y;
		if (x == 83353253)
			x = 83353253 ;

		auto findpos = findLine(x, table);
		if (findpos == table.size())
		{
			table.resize(table.size() + 1);
			table[table.size() - 1].x = x;
		}
		if (findElem(y, table[findpos].y) == table[findpos].y.size())
			table[findpos].y.push_back(y);
	}

	sort(table.begin(), table.end(), tableElemComp);
	auto output = 0;
	auto outputX = -1;
	auto outputY = -1;
	auto run = false;
	for (;table.size();)
	{
		auto& yPos = table[0].y;
		run = true;
		sort(yPos.begin(), yPos.end());

		for (unsigned a = yPos.size() - 1; (0 < a) && run; a--)
			for (unsigned pointer = 0; (pointer + a < yPos.size()) && run; pointer++)
			{
				auto length = yPos[pointer + a] - yPos[pointer];
				if (length < output)
					continue;
					
				auto b = table[0].x + length;
				auto findpos = findLine(b, table);
				if (findpos == table.size())
					continue;

				if (findElem(yPos[pointer + a], table[findpos].y) == table[findpos].y.size())
					continue;

				if (findElem(yPos[pointer], table[findpos].y) == table[findpos].y.size())
					continue;

				if (length > output)
				{
					output = length;
					outputX = table[0].x;
					outputY = yPos[pointer];
					run = false;
				}
			}

		table.erase(table.begin());
	}

	if (outputX == -1)
		cout << -1;
	else
		cout << outputX << " " << outputY;
}

unsigned findTarget = 0;
bool findFunction(lineAndVector& inputStuct) { return inputStuct.x == findTarget; };
unsigned findLine(unsigned& x, vector<lineAndVector>& table)
{
	findTarget = x;
	return find_if(table.begin(), table.end(), findFunction) - table.begin();
}
bool findFunction_u(unsigned& input) { return input == findTarget; };
unsigned findElem(unsigned x, vector<unsigned>& table)
{
	findTarget = x;
	return find_if(table.begin(), table.end(), findFunction_u) - table.begin();
}

bool tableElemComp(lineAndVector& a, lineAndVector& b) { return (a.x < b.x); };
