#include <iostream>
#include <stack>
#include <vector>
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

void reInit()
{
    for (int i = 1; i <= n; i++)
    {
        visited[i] = 0;
    }
}

int DFS(int u)
{
    int count = 0;
    stack<int> stack;
    int arr[100];
    stack.push(u);

    while (!stack.empty())
    {
        int v = stack.top();
        visited[v] = 1;
        count++;
        stack.pop();

        for (int i = 1; i <= n; i++)
        {
            if (A[v][i] == 1 && visited[i] == 0)
            {
                stack.push(i);
                visited[i] = 1;
            }
        }
    }
    return count;
}

void Canh_cau()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (A[i][j] == 1)
            {
                A[i][j] = A[j][i] = 0;
                if (DFS(1) != n)
                {
                    cout << i << "," << j << " la canh cau\n";
                }
                A[i][j] = A[j][i] = 1;
                reInit();
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
    Canh_cau();
    return 0;
}
