#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int jum_query, i, node, arr[5000];

    // banyak data
    cin >> jum_query;

    for (i = 1; i <= jum_query; i++)
    {
        // input value
        cin >> node;

        // node genap: ditambahkan ke array
        if ((i % 2) == 0)
        {
            arr[i] = node;
        }

        // node ganjil: cetak
        else
        {
            cout << node << " ";
        }
    }

    for (i = 1; i <= jum_query; i++)
    {
        // jika arr[i] != 0, maka cetak
        if (arr[i] != 0)
        {
            cout << arr[i] << " ";
        }
    }
    return 0;
}