#include <stdio.h>
#include <stdlib.h>

#define MAX 5

void bfs(int adj[][MAX], int visited[], int start) {
    int queue[MAX], rear = -1, front = -1;

    for (int i = 0; i < MAX; i++) {
        visited[i] = 0;
    }

    queue[++rear] = start;
    ++front;
    visited[start] = 1;

    while (rear >= front) {
        start = queue[front++];
        printf("%d->", start);

        for (int j = 0; j < MAX; j++) {
            if (adj[start][j] && visited[j] == 0) {
                queue[++rear] = j;
                visited[j] = 1;
            }
        }
    }
}

void dfs(int adj[][MAX], int visited[], int start) {
    int stack[MAX], top = -1;

    for (int i = 0; i < MAX; i++) {
        visited[i] = 0;
    }

    stack[++top] = start;
    visited[start] = 1;

    while (top != -1) {
        start = stack[top--];
        printf("%d->", start);

        for (int j = 0; j < MAX; j++) {
            if (adj[start][j] && visited[j] == 0) {
                stack[++top] = j;
                visited[j] = 1;
            }
        }
    }
}

int main() {
    int visited[MAX] = {0};
    int adj[MAX][MAX];
    int option;

    do {
        printf("\nMenu:\n");
        printf("1. Enter adjacency matrix\n");
        printf("2. BFS traversal\n");
        printf("3. DFS traversal\n");
        printf("4. Exit\n");
        scanf("%d", &option);

        switch(option) {
        case 1:
            printf("Enter the adjacency matrix (5x5):\n");
            for (int i = 0; i < MAX; i++) {
                for (int j = 0; j < MAX; j++) {
                    scanf("%d", &adj[i][j]);
                }
            }
            break;
        case 2:
            printf("BFS Traversal starting from node 0:\n");
            bfs(adj, visited, 0);
            break;
        case 3:
            printf("DFS Traversal starting from node 0:\n");
            dfs(adj, visited, 0);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid option. Please try again.\n");
        }
    } while (option != 4);

    return 0;
}
