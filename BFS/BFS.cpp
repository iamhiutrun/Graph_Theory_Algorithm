#include <iostream>
#include <queue>
#include <fstream>

using namespace std;

int n;
int A[100][100];
int visited[100];

void init()
{
    ifstream file("graph.txt", ios::in);
    file >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            file >> A[i][j];
        }
        visited[i] = 0;
    }
}

void BFS(int u)
{
    cout << "Duyet(" << u << "): ";
    queue<int> queue;
    queue.push(u);
    visited[u] = 1;
    while (!queue.empty())
    {
        int v = queue.front();
        cout << v << " ";
        queue.pop();
        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == 0 && A[v][i] == 1)
            {
                queue.push(i);
                visited[i] = 1;
            }
        }
    }
}

void matrix()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    init();
    int u;
    cout << "Dinh bat dau duyet: ";
    cin >> u;
    BFS(u);
    return 0;
}