#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// Directions for movement (right, down, left, up)
int dirX[] = {0, 1, 0, -1};
int dirY[] = {1, 0, -1, 0};

// Struct for Queue used in BFS
typedef struct {
    int x, y;
    int dist;
} QueueNode;

typedef struct {
    QueueNode items[MAX * MAX];
    int front, rear;
} Queue;

// Initialize Queue
void initQueue(Queue* q) {
    q->front = 0;
    q->rear = 0;
}

// Check if the Queue is empty
int isEmpty(Queue* q) {
    return q->front == q->rear;
}

// Enqueue element into the Queue
void enqueue(Queue* q, int x, int y, int dist) {
    q->items[q->rear].x = x;
    q->items[q->rear].y = y;
    q->items[q->rear].dist = dist;
    q->rear++;
}

// Dequeue element from the Queue
QueueNode dequeue(Queue* q) {
    return q->items[q->front++];
}

// BFS to find the shortest path in a grid
int bfs(int grid[MAX][MAX], int m, int n, int startX, int startY, int endX, int endY) {
    bool visited[MAX][MAX] = {false};
    Queue q;
    initQueue(&q);

    // Mark start as visited
    visited[startX][startY] = true;

    // Enqueue the starting point
    enqueue(&q, startX, startY, 0);

    // BFS loop
    while (!isEmpty(&q)) {
        QueueNode node = dequeue(&q);
        int x = node.x, y = node.y, dist = node.dist;

        // If we reached the destination, return the distance
        if (x == endX && y == endY) {
            return dist;
        }

        // Explore all 4 possible directions
        for (int i = 0; i < 4; i++) {
            int newX = x + dirX[i];
            int newY = y + dirY[i];

            // Check if the new position is valid and not visited
            if (newX >= 0 && newX < m && newY >= 0 && newY < n && !visited[newX][newY] && grid[newX][newY] == 0) {
                visited[newX][newY] = true;
                enqueue(&q, newX, newY, dist + 1);
            }
        }
    }

    // If no path exists
    return -1;
}

int main() {
    int m, n;
    printf("Enter the dimensions of the grid (m n): ");
    scanf("%d %d", &m, &n);

    int grid[MAX][MAX];
    printf("Enter the grid (0 for empty cell, 1 for blocked cell):\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    int startX, startY, endX, endY;
    printf("Enter start position (x1 y1): ");
    scanf("%d %d", &startX, &startY);
    printf("Enter end position (x2 y2): ");
    scanf("%d %d", &endX, &endY);

    int result = bfs(grid, m, n, startX, startY, endX, endY);
    if (result == -1) {
        printf("No path exists from start to end.\n");
    } else {
        printf("The shortest path length is: %d\n", result);
    }

    return 0;
}

