#include <iostream>
#include <vector>
#include <queue>
#include <chrono>

using namespace std;
using namespace chrono;

class Network
{
    int vertices;
    vector<vector<int>> connections;

public:

    Network(int n)
    {
        vertices = n;
        connections.resize(vertices);
    }

    // Add an undirected edge
    void connect(int a, int b)
    {
        connections[a].push_back(b);
        connections[b].push_back(a);
    }

    // Recursive DFS helper
    void exploreDFS(int current, vector<bool>& marked)
    {
        marked[current] = true;
        cout << current << " ";

        for (int next : connections[current])
        {
            if (!marked[next])
            {
                exploreDFS(next, marked);
            }
        }
    }

    // DFS traversal
    void performDFS(int source)
    {
        vector<bool> marked(vertices, false);
        exploreDFS(source, marked);
    }

    // BFS traversal
    void performBFS(int source)
    {
        vector<bool> marked(vertices, false);
        queue<int> pending;

        marked[source] = true;
        pending.push(source);

        while (!pending.empty())
        {
            int current = pending.front();
            pending.pop();

            cout << current << " ";

            for (int next : connections[current])
            {
                if (!marked[next])
                {
                    marked[next] = true;
                    pending.push(next);
                }
            }
        }
    }
};

int main()
{
    int vertices, edges;

    cout << "Enter total vertices: ";
    cin >> vertices;

    Network graph(vertices);

    cout << "Enter total edges: ";
    cin >> edges;

    cout << "Enter each edge (source destination):\n";

    for (int i = 0; i < edges; i++)
    {
        int source, destination;
        cin >> source >> destination;

        graph.connect(source, destination);
    }

    int startingPoint;

    cout << "Enter starting vertex: ";
    cin >> startingPoint;

    // -------- DFS PERFORMANCE --------

    auto dfsBegin = high_resolution_clock::now();

    cout << "\nDFS Traversal: ";
    graph.performDFS(startingPoint);

    auto dfsFinish = high_resolution_clock::now();

    auto dfsDuration =
        duration_cast<nanoseconds>(dfsFinish - dfsBegin);


    // -------- BFS PERFORMANCE --------

    auto bfsBegin = high_resolution_clock::now();

    cout << "\n\nBFS Traversal: ";
    graph.performBFS(startingPoint);

    auto bfsFinish = high_resolution_clock::now();

    auto bfsDuration =
        duration_cast<nanoseconds>(bfsFinish - bfsBegin);


    // -------- DISPLAY TIME --------

    cout << "\n\n-----------------------------";
    cout << "\n      EXECUTION TIME";
    cout << "\n-----------------------------";

    cout << "\nDFS Time : "
         << dfsDuration.count() << " ns";

    cout << "\nBFS Time : "
         << bfsDuration.count() << " ns";

    cout << "\n";

    return 0;
}
