#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int jum_komputer, com[3001];

    // input jumlah komputer
    cin >> jum_komputer;

    // input komputer
    for (int i = 0; i < jum_komputer; ++i)
    {
        cin >> com[i];

        // decrement komputer
        --com[i];
    }

    // cek komputer
    for (int i = 0; i < jum_komputer; ++i)
    {
        // jika komputer sama dengan komputer ke-4
        if (com[i] == com[com[com[com[i]]]])
        {
            // cetak YES
            cout << "YES" << endl;
            return 0;
        }
    }

    // cetak NO
    cout << "NO" << endl;

    return 0;
}