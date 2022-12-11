#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>
using namespace std;

int main()
{
    int num, start = 0;
    list<int> arr[100];
    list<int>::iterator it;

    for (int i = 0; i > -1; i++)
    {
        // input number
        cin >> num;

        // jika num = 0, break
        if (num == 0)
        {
            break;
        }
        
        // push number ke array
        arr[start].push_back(num);
    }

    // sort dan unique: urutkan dan hapus duplikat
    arr[start].sort();
    arr[start].unique();

    // cetak
    for (it = arr[start].begin(); it != arr[start].end(); it++)
    {
        cout << *it << endl;
    }

    return 0;
}