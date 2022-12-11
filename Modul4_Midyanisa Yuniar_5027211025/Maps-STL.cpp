#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    map<string, int> maps;
    int input;
    cin >> input;
    while (input > 0)
    {
        int type, marks;
        string name;
        cin >> type >> name;
        if (type == 1)
        {
            cin >> marks;
            if (maps.find(name) == maps.end())
            {
                maps.insert(make_pair(name, marks));
            }
            else
            {
                maps[name] += marks;
            }
        }
        else if (type == 2)
        {
            maps.erase(name);
        }
        else
        {
            cout << maps[name] << endl;
        }
        input--;
    }
    return 0;
}
