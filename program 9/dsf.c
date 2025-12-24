#include <stdio.h>

void dfs(int);

int n, i, j;
int a[10][10], vis[10];
int count = 0;   /* initialize count */

int main()
{
    printf("Enter the number of vertices\n");
    scanf("%d", &n);

    printf("Enter the adjacency matrix\n");
    for (i = 1; i <= n; i++)
    {
        vis[i] = 0;
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("DFS traversal\n");
    for (i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
            dfs(i);
    }

    for (i = 1; i <= n; i++)
    {
        if (vis[i] == 1)
            count++;
    }

    if (count == n)
        printf("\nGraph is connected\n");
    else
        printf("\nGraph is not connected\n");

    return 0;
}

void dfs(int v)
{
    vis[v] = 1;
    printf("%d ", v);

    for (j = 1; j <= n; j++)
    {
        if (a[v][j] == 1 && vis[j] == 0)
        {
            dfs(j);
        }
    }
}

