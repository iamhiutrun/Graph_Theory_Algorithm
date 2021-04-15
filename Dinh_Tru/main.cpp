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

void Dinh_Tru()
{
    vector<int> vector;
    for (int i = 1; i <= n; i++)
    {
        visited[i] = 1;
        if (i == 1)
        {
            if (DFS(2) != n - 1)
                vector.push_back(i);
        }
        else
        {
            if (DFS(1) != n - 1)
                vector.push_back(i);
        }
        reInit();
    }
    cout << "Cac dinh tru la: ";
    for (int item : vector)
    {
        cout << item << " ";
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
    Dinh_Tru();
    return 0;
}
