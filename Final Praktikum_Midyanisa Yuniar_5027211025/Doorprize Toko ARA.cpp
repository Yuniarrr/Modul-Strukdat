#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    int durasi, total_prize = 0, receipt, transaksi;

    priority_queue<int> high;
    priority_queue<int, vector<int>, greater<int>> low;

    // input durasi
    cin >> durasi;

    for (int i = 0; i < durasi; i++)
    {
        // input receipt
        cin >> receipt;

        // input transaksi
        for (int j = 0; j < receipt; j++)
        {
            cin >> transaksi;

            // masukkan ke priority queue
            high.push(transaksi);
            low.push(transaksi);
        }

        // hitung total prize
        total_prize += high.top() - low.top();

        // hapus data
        high.pop();
        low.pop();
    }

    // cetak total prize
    cout << total_prize << endl;
    return 0;
}