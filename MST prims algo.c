#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

int V, len;

int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}


int printMST(int parent[], int graph[V][V])
{
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++){
        printf("%d - %d \t%d \n", parent[i], i,graph[i][parent[i]]);
        len+=graph[i][parent[i]];
    }
}

void primMST(int graph[V][V])
{

    int parent[V];
    int key[V];
    bool mstSet[V];


    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;


    key[0] = 0;
    parent[0] = -1;


    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false
                && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    printMST(parent, graph);
}

int main()
{
    printf("Enter number of node: ");
    scanf("%d",&V);
    int graph[V][V];
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            graph[i][j]=0;
        }
    }
    printf("Enter number of edge: ");
    int e;
    scanf("%d",&e);

    printf("Enter edge and cost: \n");

    for(int i=0; i<e; i++){
        int x,y,c;
        scanf("%d %d %d",&x,&y,&c);
        graph[x][y]=graph[y][x]=c;
    }

    len=0;
    primMST(graph);
    printf("\nMinimum length of cable: %d\n",len);
    printf("Minimum cost: %d BDT\n\n",len*700);

    return 0;
}
