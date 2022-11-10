// #include <iostream>
#include <stdio.h>

#define MAXN 1001

struct Node {
    int V;
    int L,R;
    int nL,nR;
} n[MAXN];

int nCk[MAXN][MAXN], S, M = 1000003;

void add(int &root, int val){
    if (root == -1){
        root = ++S;
        n[root].V = val;
        n[root].L = n[root].R = -1;
        n[root].nL = n[root].nR = 0;
    } else {
        if (val < n[root].V){
            n[root].nL++;
            add(n[root].L, val);
        } else {
            n[root].nR++;
            add(n[root].R, val);
        }
    }
}

long long f(int root){
    if (root == -1) return 1;
    long long res = 1;
    res = (res * f(n[root].L)) % M;
    res = (res * f(n[root].R)) % M;
    res = (res * nCk[n[root].nL + n[root].nR][n[root].nR]) % M;
    return res;
}

int main(){
    nCk[0][0] = 1;
    for (int i = 1; i < MAXN; i++){
        nCk[i][0] = 1;
        for (int j = 1; j < MAXN; j++) {
            nCk[i][j] = (nCk[i-1][j-1] + nCk[i-1][j]) % M;
        }
    }

    int result[MAXN];
    int TC;
    scanf("%d", &TC);
    for (int i = 0; i < TC; i++) {
        int N, T, val, root = -1;
        S = 1;
        scanf("%d %d", &N, &T);
        for (int i=0; i<N; i++) {
            scanf("%d", &val);
            add(root, val);
        };
        result[i] = int( f(root) * nCk[T][N] % M );
    }
    for (int i = 0; i < TC; i++) {
        printf("%d\n", result[i]);
    }
}