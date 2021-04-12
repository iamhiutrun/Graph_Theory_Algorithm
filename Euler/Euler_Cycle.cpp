#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int n;
int A[100][100];

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
    }
}

void Euler_Cycle(int u)
{
    stack<int> stack, CE;
    stack.push(u);

    while (!stack.empty())
    {
        int count = 0;
        int s = stack.top();
        for (int i = 1; i <= n; i++)
        {
            if (A[i][s] == 1)
            {
                count++;
                break;
            }
        }
        if (count != 0)
        {
            for (int i = 1; i <= n; i++)
            {
                if (A[i][s] == 1)
                {
                    stack.push(i);
                    A[i][s] = A[s][i] = 0;
                    break;
                }
            }
        }
        else
        {
            CE.push(s);
            stack.pop();
        }
    }
    cout << "\nDuyet(" << u << "): ";
    while (!CE.empty())
    {
        cout << CE.top();
        CE.pop();
        if (!CE.empty())
            cout << "->";
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
    cout << endl
         << endl;
    matrix();
    Euler_Cycle(u);
    return 0;
}