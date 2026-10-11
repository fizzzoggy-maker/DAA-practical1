
#include <iostream>
using namespace std;

int n = 4;
int cost[4][4] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int visited[4] = {0};
int minCost = 99999;

void tsp(int city, int count, int totalCost) {
    if (count == n) {
        if (cost[city][0] != 0) {
            int finalCost = totalCost + cost[city][0];

            if (finalCost < minCost)
                minCost = finalCost;
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && cost[city][i] != 0) {
            visited[i] = 1;

            tsp(i, count + 1, totalCost + cost[city][i]);

            visited[i] = 0;
        }
    }
}

int main() {
    visited[0] = 1;

    tsp(0, 1, 0);

    cout << "Minimum travelling cost = " << minCost;

    return 0;
}
