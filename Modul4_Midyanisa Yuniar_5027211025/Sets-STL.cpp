#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int value;
    int option, num;
    set<int> sets;

    cin >> value;
    for (int i = 0; i < value; i++)
    {
        cin >> option;
        cin >> num;
        switch (option)
        {
        case 1:
            sets.insert(num);
            break;
        case 2:
            sets.erase(num);
            break;
        case 3:
            set<int>::iterator it = sets.find(num);
            if (it != sets.end())
                cout << "Yes";
            else
                cout << "No";
            cout << endl;
            break;
        }
    }
}
