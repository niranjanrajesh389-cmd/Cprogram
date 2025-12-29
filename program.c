 #include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[10];
int visited[10];
int n;

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = adj[src];
    adj[src] = newNode;

    newNode = createNode(src);
    newNode->next = adj[dest];
    adj[dest] = newNode;
}

void DFS(int v) {
    printf("%d ", v);
    visited[v] = 1;

    struct Node* temp = adj[v];
    while(temp != NULL) {
        if(!visited[temp->vertex])
            DFS(temp->vertex);
        temp = temp->next;
    }
}

void BFS(int start) {
    int queue[10], front = 0, rear = -1;
    int vis[10] = {0};

    vis[start] = 1;
    queue[++rear] = start;

    printf("BFS traversal starting from vertex %d: ", start);
    while(front <= rear) {
        int v = queue[front++];
        printf("%d ", v);

        struct Node* temp = adj[v];
        while(temp != NULL) {
            if(!vis[temp->vertex]) {
                queue[++rear] = temp->vertex;
                vis[temp->vertex] = 1;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main() {
    int edges, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for(int i=0; i<n; i++)
        adj[i] = NULL;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for(int i=0; i<edges; i++) {
        printf("Enter edge %d (source destination): ", i+1);
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printf("Enter starting vertex for traversal: ");
    scanf("%d", &start);

    printf("\nDFS traversal starting from vertex %d: ", start);
    for(int i=0; i<n; i++)
        visited[i] = 0;
    DFS(start);
    printf("\n");

    BFS(start);

    return 0;
}