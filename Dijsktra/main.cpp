#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#define MAX 100
#define INF 9999

int G[MAX][MAX], n, u;
int parent[MAX];
int visited[MAX];

void init()
{
    ifstream file("graph.txt", ios::in);
    file >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            file >> G[i][j];
            if (G[i][j] == 0)
            {
                G[i][j] = INF;
            }
        }
    }
}

void dijkstra(int startnode)
{
    int distance[MAX];
    for (int i = 1; i <= n; i++)
    {
        distance[i] = G[startnode][i];
        parent[i] = startnode;
        visited[i] = 0;
    }

    distance[startnode] = 0;
    visited[startnode] = 1;
    int count = 1;
    int min_node;
    while (count < n - 1)
    {
        int min = INF;
        //Tim dinh co trong so nho nhat
        for (int i = 1; i <= n; i++)
        {
            if (distance[i] < min && !visited[i])
            {
                min = distance[i];
                min_node = i;
            }
        }
        // Danh dau da duyet
        visited[min_node] = 1;

        // Tinh tong khoang cach tu node dau qua node duoc chon den
        // cac node con lai

        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                if (min + G[min_node][i] < distance[i])
                {
                    distance[i] = min + G[min_node][i];
                    parent[i] = min_node;
                }
            }
        }
        count++;
    }

    //In ra duong di ngan nhat
    for (int i = 1; i <= n; i++)
    {
        if (i != startnode)
        {
            cout << "Duong di ngan nhat den " << i << " = " << distance[i];
            cout << endl
                 << "Duong di: " << i;
            int j = i;
            do
            {
                j = parent[j];
                cout << "<-" << j;
            } while (j != startnode);
            cout << endl;
        }
    }
}

int main()
{

    init();
    printf("\nEnter the starting node:");
    scanf("%d", &u);
    dijkstra(u);

    return 0;
    return 0;
}