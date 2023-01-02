#include <stdio.h>
#define MAX 100
typedef struct edge
{
    int v1, v2, cost;
} edge;

// input -> sort_cost(sorted) -> group

int group[MAX];

void Kruskal(edge sorted[], int Vertexx);
void Prim(int Vertexx, edge input[Vertexx][Vertexx]);
void Union(int change_to, int be_changed, int Vertexx);
void group_init();
void sort(edge sorted[], int array_size);

void Prim(int Vertexx, edge input[Vertexx][Vertexx])
{
    int edge_number = 0;
    int total_cost = 0;
    int selected[Vertexx];
    for (int i = 0; i < Vertexx; i++)
    {
        selected[i] = 0;
    }

    selected[0] = 1;

    while (edge_number != Vertexx - 1)
    {
        int min_i;
        int min_j;
        int min = 999999;
        for (int i = 0; i < Vertexx; i++)
        {
            if (selected[i] == 1)
            {
                for (int j = 0; j < Vertexx; j++)
                {
                    if (selected[j] == 0 && input[i][j].cost != 0)
                    {
                        if (input[i][j].cost < min)
                        {
                            min = input[i][j].cost;
                            min_i = i;
                            min_j = j;
                        }
                    }
                }
            }
        }
        total_cost += min;
        edge_number++;
        selected[min_j] = 1;
    }

    printf("Prim minimum cost: %d\n", total_cost);
}

void Union(int change_to, int be_changed, int Vertexx)
{
    for (int i = 0; i < Vertexx; i++)
    {
        if (group[i] == be_changed)
        {
            group[i] = change_to;
        }
    }
}

void Kruskal(edge sorted[], int Vertexx)
{
    int ans = 0;
    for (int i = 0; i < Vertexx; i++)
    {
        if (group[sorted[i].v1] == group[sorted[i].v2])
        { // same group -> create cicle
            continue;
        }
        ans += sorted[i].cost;
        Union(group[sorted[i].v1], group[sorted[i].v2], Vertexx);
    }
    printf("Kruskal minimum cost: %d\n", ans);
}

void group_init()
{
    for (int i = 0; i < MAX; i++)
    {
        group[i] = i;
    }
}

void sort(edge sorted[], int array_size)
{

    for (int i = 0; i < array_size - 1; i++)
    {
        for (int j = 0; j < array_size - i - 1; j++)
        {
            if (sorted[j].cost > sorted[j + 1].cost)
            {
                edge temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    while (n != -1)
    {
        group_init();
        edge input[n][n];

        // take the input
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                input[i][j].v1 = i;
                input[i][j].v2 = j;
                scanf("%d", &input[i][j].cost);
            }
        }

        int Vertexx = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (input[i][j].cost != 0)
                {
                    Vertexx++;
                }
            }
        }
        edge sorted[Vertexx];

        // 2d to 1d
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (input[i][j].cost != 0)
                {
                    sorted[count] = input[i][j];
                    count++;
                }
            }
        }
        sort(sorted, Vertexx);
        Kruskal(sorted, Vertexx);
        Prim(n, input);
        scanf("%d", &n);
    }

    return 0;
}
