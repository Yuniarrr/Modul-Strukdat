#include <iomanip>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int jum_test, num_sehat, count = 0, jum_ren_sehat = 0;
    double tot = 0, ren_sehat = 0, tot_sementara = 0, komposisi, tot_akhir;
    string makanan;

    // input jumlah test, jumlah sehat
    cin >> jum_test;
    cin >> num_sehat;

    for (int i = 0; i < jum_test; i++)
    {
        // input makanan
        cin >> makanan;

        // jika makanan != "GASS", input komposisi makanan
        if (makanan != "GASS")
        {
            cin >> komposisi;

            // hitung total komposisi
            tot = tot + komposisi;

            // hitung jumlah makanan sehat
            count++;
        }

        // jika makanan == "GASS", hitung rata-rata komposisi makanan sehat
        else
        {
            ren_sehat = tot / count;
            cout << fixed << setprecision(2) << ren_sehat << endl;
            tot_sementara = tot_sementara + ren_sehat;
            jum_ren_sehat++;
        }
    }

    // hitung rata-rata komposisi makanan sehat
    tot_akhir = tot_sementara / jum_ren_sehat;
    
    // output rata-rata komposisi makanan sehat
    cout << tot_akhir << " ";
    
    // output status
    if (0.5 * num_sehat <= tot_akhir && 1.5 * num_sehat >= tot_akhir)
    {
        cout << "AMAN";
    }
    else
    {
        cout << "LOH";
    }
}