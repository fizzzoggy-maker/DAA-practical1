
#include <iostream>
#include <algorithm>
using namespace std;

#define V 5
#define E 7

struct Edge {
    int src, dest, weight;
};

int parent[V];

int find(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent[i]);
}

void unionSet(int u, int v) {
    parent[find(u)] = find(v);
}

void kruskalMST(Edge edges[]) {
    sort(edges, edges + E,
         [](Edge a, Edge b) {
             return a.weight < b.weight;
         });

    for (int i = 0; i < V; i++)
        parent[i] = i;

    int totalCost = 0;
    int count = 0;

    cout << "Edges in Minimum Spanning Tree:\n";

    for (int i = 0; i < E && count < V - 1; i++) {
        int u = find(edges[i].src);
        int v = find(edges[i].dest);

        if (u != v) {
            cout << edges[i].src << " - "
                 << edges[i].dest << " : "
                 << edges[i].weight << endl;

            totalCost += edges[i].weight;
            unionSet(u, v);
            count++;
        }
    }

    if (count != V - 1) {
        cout << "Graph is disconnected!\n";
        return;
    }

    cout << "Total Minimum Cost: " << totalCost << endl;
}

int main() {
    Edge edges[E] = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };

    kruskalMST(edges);

    return 0;
}
