#include <iostream>
#include <stack>
#include <queue>
#include <fstream>

using namespace std;

int n;
int A[100][100];
int visited[100];
int front_point[100];

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
        front_point[i] = 0;
    }
}

void DFS(int u)
{
    stack<int> stack;
    int arr[100];
    stack.push(u);

    while (!stack.empty())
    {

        int v = stack.top();
        visited[v] = 1;
        stack.pop();
        for (int i = 1; i <= n; i++)
        {
            if (A[i][v] == 1 && visited[i] == 0)
            {
                stack.push(i);
                visited[i] = 1;
                front_point[i] = v;
            }
        }
    }
}

void Search_Path(int s, int e)
{
    if (front_point[e] == 0)
    {
        cout << "There is no path from " << s << " to " << e;
    }
    else
    {
        cout << "Path from " << s << " to " << e << ": ";
        while (e != s)
        {
            cout << e << " ";
            e = front_point[e];
        }
        cout << s;
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

    int s, e;
    cin >> s >> e;
    DFS(s);
    Search_Path(s, e);
    return 0;
}
