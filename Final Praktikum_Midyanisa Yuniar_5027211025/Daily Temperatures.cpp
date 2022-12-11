#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    queue<int> temp;
    int jum_temp;
    int value;

    // input jumlah cuaca
    cin >> jum_temp;

    while (jum_temp--)
    {
        // input cuaca / temperatures
        cin >> value;
        temp.push(value);
    }

    // loop selama queue temp tidak kosong
    while (!temp.empty())
    {
        // ambil nilai pertama
        int f = temp.front();

        // hapus nilai pertama
        temp.pop();

        // copy queue
        queue<int> temp_check = temp;
        queue<int> temp_out;
        
        bool flag = false;

        // loop selama queue temp_check tidak kosong
        while (!temp_check.empty())
        {
            // masukkan nilai ke queue temp_out
            temp_out.push(temp_check.front());

            // jika nilai lebih besar dari nilai pertama
            if (temp_check.front() > f)
            {
                // set flag = true
                flag = true;
                break;
            }

            // hapus nilai pertama
            temp_check.pop();
        }

        // jika !flag , cetak "letsgo!!"
        if (!flag)
        {
            cout << "letsgo!!" << endl;
            continue;
        }

        // cetak panjang queue temp_out
        cout << temp_out.size() << " ";

        // cetak isi queue temp_out
        while (!temp_out.empty())
        {
            cout << temp_out.front() << " ";
            temp_out.pop();
        }

        cout << endl;
    }

    return 0;
}