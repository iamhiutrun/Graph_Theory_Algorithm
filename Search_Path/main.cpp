#include <iostream>
#include <stack>
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

void DFS(int u)
{
    stack<int> stack;
    int arr[100];
    stack.push(u);
    cout << "DFS(" << u << ") ";

    while (!stack.empty())
    {

        int v = stack.top();
        visited[v] = 1;
        stack.pop();
        cout << v << " ";
        for (int i = 1; i <= n; i++)
        {
            if (A[i][v] == 1 && visited[i] == 0)
            {
                stack.push(i);
                visited[i] = 1;
            }
        }
    }
    cout << endl;
}

void BFS(int u)
{
    queue<int> queue;
    queue.push(u);
    visited[u] = 1;

    while (!queue.empty())
    {
        int v = queue.front();
        cout << v << endl;
        queue.pop();

        for (int i = 1; i <= n; i++)
        {
            if (A[i][v] == 1 && visited[i] == 0)
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

    return 0;
}