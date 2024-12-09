#include <stdio.h>
#include <math.h>
void preprocess(int arr[], int n, int st[n][(int)log2(n) + 1]) {

    for (int i = 0; i < n; i++) {
        st[i][0] = arr[i];
    }
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) - 1 < n; i++) {
            st[i][j] = (st[i][j - 1] < st[i + (1 << (j - 1))][j - 1]) ? st[i][j - 1] : st[i + (1 << (j - 1))][j - 1];
        }
    }
}
int query(int st[][100], int L, int R) {
    int j = (int)log2(R - L + 1);

    return (st[L][j] < st[R - (1 << j) + 1][j]) ? st[L][j] : st[R - (1 << j) + 1][j];
}

int main() {
    int n, q;
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int st[n][(int)log2(n) + 1];
    preprocess(arr, n, st);

    printf("Enter number of queries: ");
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int L, R;
        printf("Enter the range [L, R]: ");
        scanf("%d %d", &L, &R);
        printf("Minimum value in range [%d, %d] is: %d\n", L, R, query(st, L, R));
    }

    return 0;
}
