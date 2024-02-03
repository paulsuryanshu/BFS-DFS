#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100

// Function to perform Breadth-First Search
void bfs(int adj_matrix[MAX_NODES][MAX_NODES], int num_nodes, int start_node) {
    // Array to keep track of visited nodes
    bool visited[MAX_NODES];
    for (int i = 0; i < MAX_NODES; i++) {
        visited[i] = false;
    }

    // Create a queue for BFS
    int queue[MAX_NODES];
    int front = 0, rear = -1;

    // Mark the start node as visited and enqueue it
    visited[start_node] = true;
    queue[++rear] = start_node;

    while (front <= rear) {
        // Dequeue a vertex from the queue and print it
        int current_node = queue[front++];
        printf("%d ", current_node);

        // Explore adjacent nodes of the current node
        for (int neighbor = 0; neighbor < num_nodes; neighbor++) {
            if (adj_matrix[current_node][neighbor] == 1 && !visited[neighbor]) {
                // Mark the neighbor as visited and enqueue it
                visited[neighbor] = true;
                queue[++rear] = neighbor;
            }
        }
    }
}

int main() {
    // Example adjacency matrix
    int adjacency_matrix[MAX_NODES][MAX_NODES] = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 1, 1},
        {0, 0, 1, 0, 1},
        {1, 1, 1, 1, 0}
    };

    int num_nodes = 5;
    int start_node = 0;

    printf("BFS traversal starting from node %d: ", start_node);
    bfs(adjacency_matrix, num_nodes, start_node);

    return 0;
}

