#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#define INF 9999999;

int V;                // define number of vertices
int matrix[100][100]; // create a matrix of weight
int selected[100];    //  create a array to track selected vertices
struct edge
{
    int u;
    int v;
    int w;
};

void init()
{
    ifstream file("graph.txt", ios::in);
    file >> V;
    int n = V;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            file >> matrix[i][j];
        }
        selected[i] = 0;
    }
}

void output()
{
    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void prim()
{
    init();
    int no_edge = 0;
    selected[1] = true;
    while (no_edge < V - 1)
    {
        int x, y;
        int min = INF;
        for (int i = 1; i <= V; i++)
        {
            if (selected[i])
            {
                for (int j = 1; j <= V; j++)
                {
                    if (!selected[j] && matrix[i][j])
                    {
                        if (min > matrix[i][j])
                        {
                            min = matrix[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        selected[y] = 1;
        no_edge++;
        cout << x << " - " << y << " :  " << matrix[x][y] << endl;
    }
}

int main()
{
    prim();
    return 0;
}