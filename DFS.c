#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100

// Function to perform Depth-First Search
void dfs(int adj_matrix[MAX_NODES][MAX_NODES], bool visited[MAX_NODES], int num_nodes, int current_node) {
    // Mark the current node as visited and print it
    visited[current_node] = true;
    printf("%d ", current_node);

    // Explore adjacent nodes of the current node
    for (int neighbor = 0; neighbor < num_nodes; neighbor++) {
        if (adj_matrix[current_node][neighbor] == 1 && !visited[neighbor]) {
            // Recursively call DFS for the unvisited neighbor
            dfs(adj_matrix, visited, num_nodes, neighbor);
        }
    }
}

int main() {
    // Example adjacency matrix
    int adjacency_matrix[MAX_NODES][MAX_NODES] = {
        {0, 1, 0, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 1, 1},
        {0, 0, 0, 1, 1, 1, 0},
        {1, 1, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 0, 1},
        {0, 1, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0}
    };

    int num_nodes = 7;
    bool visited[MAX_NODES];

    // Initialize visited array
    for (int i = 0; i < MAX_NODES; i++) {
        visited[i] = false;
    }

    // Choose a starting node for DFS
    int start_node = 0;

    printf("DFS traversal starting from node %d: ", start_node);
    dfs(adjacency_matrix, visited, num_nodes, start_node);

    return 0;
}

