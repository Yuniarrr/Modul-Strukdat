#include <iostream>
#include <deque>
using namespace std;

void maxR(int A[], int n, int w, int B[])
{
    deque<int> Dque;
    for (int i = 0; i < w; i++)
    {
        while (!Dque.empty() && A[i] >= A[Dque.back()])
            Dque.pop_back();
        Dque.push_back(i);
    }
    for (int i = w; i < n; i++)
    {
        B[i - w] = A[Dque.front()];
        while (!Dque.empty() && A[i] >= A[Dque.back()])
            Dque.pop_back();
        while (!Dque.empty() && Dque.front() <= i - w)
            Dque.pop_front();
        Dque.push_back(i);
    }
    B[n - w] = A[Dque.front()];
}
long T, N, K;
int main()
{
    cin >> T;
    while (T--)
    {

        cin >> N >> K;
        int arr[N], res[N - K + 1];
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        maxR(arr, N, K, res);

        for (int i = 0; i < N - K + 1; i++)
        {
            cout << res[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}
