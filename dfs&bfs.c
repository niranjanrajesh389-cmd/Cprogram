#include <stdio.h>
#include <stdlib.h>

struct node
{
    int vertex;
    struct node* next;
};

struct node* createNode(int v)
{
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->vertex = v;
    n->next = NULL;
    return n;
}

struct Graph
{
    int numVertices;
    struct node** adjLists;
    int* visited;
};

struct Graph* createGraph(int vertices)
{
    struct Graph* g = (struct Graph*)malloc(sizeof(struct Graph));
    g->numVertices = vertices;
    g->adjLists = (struct node*)malloc(vertices*sizeof(struct node));
    g->visited = (int*)malloc(vertices*sizeof(int));
    for(int i=0;i<vertices;i++)
    {
        g->adjLists[i] = NULL;
        g->visited[i] = 0;
    }
    return g;
}

void addEdge(struct Graph* g,int src,int dest)
{
    struct node* n = createNode(dest);
    n->next = g->adjLists[src];
    g->adjLists[src] = n;

    n = createNode(src);
    n->next = g->adjLists[dest];
    g->adjLists[dest] = n;
}

void DFS(struct Graph* g,int v)
{
    g->visited[v] = 1;
    printf("%d ",v);
    struct node* temp = g->adjLists[v];
    while(temp)
    {
        if(!g->visited[temp->vertex])
            DFS(g,temp->vertex);
        temp = temp->next;
    }
}

void BFS(struct Graph* g,int start)
{
    int* queue = (int*)malloc(g->numVertices*sizeof(int));
    int f=-1,r=-1;
    int* visited = (int*)malloc(g->numVertices*sizeof(int));
    for(int i=0;i<g->numVertices;i++) visited[i]=0;

    queue[++r] = start;
    visited[start]=1;

    while(f<r)
    {
        int v = queue[++f];
        printf("%d ",v);
        struct node* temp = g->adjLists[v];
        while(temp)
        {
            if(!visited[temp->vertex])
            {
                queue[++r] = temp->vertex;
                visited[temp->vertex] = 1;
            }
            temp = temp->next;
        }
    }
    free(queue);
    free(visited);
}

int main()
{
    int vertices, edges, src, dest;
    printf("Enter number of vertices: ");
    scanf("%d",&vertices);
    struct Graph* g = createGraph(vertices);

    printf("Enter number of edges: ");
    scanf("%d",&edges);

    for(int i=0;i<edges;i++)
    {
        printf("Enter edge %d (source destination): ", i+1);
        scanf("%d %d",&src,&dest);
        addEdge(g,src,dest);
    }

    printf("DFS starting from vertex 0: ");
    DFS(g,0);

    printf("\nBFS starting from vertex 0: ");
    BFS(g,0);

    return 0;
}