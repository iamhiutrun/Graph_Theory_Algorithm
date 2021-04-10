#include <stdio.h>

#define MAX_Vertices 20
#define MAX_Length 20
#define MAX_Element 40

typedef struct
{
    int A[MAX_Vertices][MAX_Vertices];
    int n;
} Graph;

void init_graph(Graph *G, int n)
{
    G->n = n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            G->A[i][j] = 0;
        }
    }
}

// Them cung vao do thi
void add_edge(Graph *G, int x, int y)
{
    G->A[x][y] = 1;
    G->A[y][x] = 1;
}

void read_file(Graph *G)
{
    freopen("graph.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    // Khoi tao do thi
    init_graph(G, n);

    int u, v;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        add_edge(G, u, v);
    }
}

// Kiem tra x va y co phai ket noi voi nhau khong?
int adjacent(Graph G, int x, int y)
{
    return (G.A[x][y] == 1 || G.A[y][x] == 1);
}

// Khai bao cau truc danh sach List
typedef struct
{
    int data[MAX_Length];
    int size;
} List;

// Tao danh sach rong
void init_list(List *list)
{
    list->size = 0;
}

// Lay mot dinh trong list vi tri i
int element_at(List list, int i)
{
    return list.data[i];
}

// Them mot dinh vao cuoi danh sach
void push_back(List *list, int x)
{
    list->size++;
    list->data[list->size] = x;
}

// Tim lang gieng cua dinh x
List neighbors(Graph G, int x)
{
    List L;
    init_list(&L);
    for (int i = 1; i <= G.n; i++)
    {
        if (adjacent(G, x, i))
        {
            push_back(&L, i);
        }
    }
    return L;
}

// in ra matrix dinh - dinh
void matrix(Graph G)
{
    printf("\nMatrix: Vertex - Vertext\n");
    for (int i = 1; i <= G.n; i++)
    {
        for (int j = 1; j <= G.n; j++)
        {
            printf("%d ", G.A[i][j]);
        }
        printf("\n");
    }
}

//Khai bao cau truc ngan xep
typedef struct
{
    int data[MAX_Element];
    int size;
} Stack;

//Khoi tao stack
void init_stack(Stack *stack)
{
    stack->size = 0;
}

//Them 1 phan tu vao stack
void push_stack(Stack *stack, int x)
{
    stack->size++;
    stack->data[stack->size] = x;
}

// Lay mot phan tu trong Stack
int top(Stack stack)
{
    return stack.data[stack.size];
}

void pop(Stack *stack)
{
    stack->size--;
}

// Lay ra 1 phan tu va xoa no
int pop_stack(Stack *stack)
{
    int x = stack->data[stack->size];
    stack->size--;
    return x;
}

// Kiem tra xem stack co rong hay khong?
int isEmpty(Stack stack)
{
    return stack.size == 0;
}

// Depth First Search
List depth_first_search(Graph G, int x)
{
    Stack stack;
    init_stack(&stack);

    List list_dfs;
    init_list(&list_dfs);

    push_stack(&stack, x);
    int mark[MAX_Vertices];

    for (int i = 1; i <= G.n; i++)
    {
        mark[i] = 0;
    }

    while (!isEmpty(stack))
    {
        int u = pop_stack(&stack);
        if (mark[u] == 1)
            continue;
        else
            mark[u] = 1;

        push_back(&list_dfs, u);

        List neighbor_list = neighbors(G, u);
        for (int i = 1; i <= neighbor_list.size; i++)
        {
            int v = element_at(neighbor_list, i);
            if (mark[v] == 0)
            {
                push_stack(&stack, v);
            }
        }
    }
    return list_dfs;
}

int main()
{
    Graph G;
    read_file(&G);

    //neighbors_result(G);
    int mark_dfs[MAX_Vertices];
    for (int i = 1; i <= G.n; i++)
    {
        mark_dfs[i] = 0;
    }
    for (int i = 1; i <= G.n; i++)
    {
        if (mark_dfs[i] == 0)
        {
            List dfs = depth_first_search(G, i);
            for (int j = 1; j <= dfs.size; j++)
            {
                int k = element_at(dfs, j);
                printf("Duyet: %d\n", k);
                mark_dfs[k] = 1;
            }
        }
    }

    matrix(G);
    return 0;
}