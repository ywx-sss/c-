#include <stdio.h>
#include <stdlib.h>

int main() {
    int m1, n1, k1, m2, n2, k2, m, n, k = 0;
    int *a, *b, *c;
    int i, j, p, q, r;

    scanf("%d%d%d", &m1, &n1, &k1);
    a = (int*)malloc(k1 * 3 * sizeof(int));
    for (i = 0; i < k1; i++) scanf("%d%d%d", &a[i * 3], &a[i * 3 + 1], &a[i * 3 + 2]);

    scanf("%d%d%d", &m2, &n2, &k2);
    b = (int*)malloc(k2 * 3 * sizeof(int));
    for (i = 0; i < k2; i++) scanf("%d%d%d", &b[i * 3], &b[i * 3 + 1], &b[i * 3 + 2]);

    m = m1; n = n2;
    c = (int*)malloc(m * n * sizeof(int));
    for (i = 0; i < m * n; i++) c[i] = 0;

    for (i = 0; i < k1; i++) {
        p = a[i * 3] - 1;
        q = a[i * 3 + 1] - 1;
        r = a[i * 3 + 2];
        for (j = 0; j < k2; j++) {
            if (q == b[j * 3] - 1) {
                c[p * n + b[j * 3 + 1] - 1] += r * b[j * 3 + 2];
            }
        }
    }

    int *d;
    d = (int*)malloc(m * n * 3 * sizeof(int));
    for (i = 0; i < m * n; i++) if (c[i] != 0) {
        d[k * 3] = i / n + 1;
        d[k * 3 + 1] = i % n + 1;
        d[k * 3 + 2] = c[i];
        k++;
    }

    printf("%d\n%d\n%d\n", m, n, k);
    for (i = 0; i < k; i++) printf("%d,%d,%d\n", d[i * 3], d[i * 3 + 1], d[i * 3 + 2]);

    free(a);
    free(b);
    free(c);
    free(d);
    return 0;
}
