#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> value;
    int jum;
    int num;
    cin >> jum;
    for (int i = 0; i < jum; i++)
    {
        cin >> num;
        value.push_back(num);
    }

    int erasei, tstart, tend;
    cin >> erasei >> tstart >> tend;
    value.erase(value.begin() + erasei - 1);
    value.erase(value.begin() + tstart - 1, value.begin() + tend - 1);

    cout << value.size() << endl;
    for (int i = 0; i < value.size(); i++)
        cout << value[i] << " ";

    return 0;
}
