#include <string.h>
#include <stdio.h>
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

int lcs(char *a, char *b, int m, int n);
int main(void)
{
    char *first = "AGGTAB";
    char *second = "GXTXAYB";
    int m = strlen(first);
    int n = strlen(second);
    printf("%d", lcs(first, second, m, n));
    return 0;
}
// Implementation of Longest Common Subsequence using Dynamic Programming
int lcs(char *a, char *b, int m, int n)
{
    // Extra 2-D Array
    int lcsArr[m + 1][n + 1];
    int i, j;
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                lcsArr[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
                lcsArr[i][j] = 1 + lcsArr[i - 1][j - 1];
            else
                lcsArr[i][j] = MAX(lcsArr[i - 1][j], lcsArr[i][j - 1]);
        }
    }
    return lcsArr[m][n];
}