// Represent a given graph using adjacency matrix/list to perform DFS and using adjacency
// list to perform BFS. Use the map of the area around the college as the graph. Identify
// the prominent land marks as nodes and perform DFS and BFS on that.

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int const N = 30;

class GraphwMatrix
{
private:
    int nVertices;
    int nEdges;
    int data[N][N];
    int Visited[N] = {0};

public:
    GraphwMatrix()
    {
        nVertices = 0;
        nEdges = 0;
        for (int i = 0; i < nVertices; i++)
        {
            for (int j = 0; j < nVertices; j++)
            {
                data[i][j] = 0;
            }
        }
    }

    GraphwMatrix(int nv)
    {
        nVertices = nv;
        nEdges = 0;
        for (int i = 0; i < nVertices; i++)
        {
            for (int j = 0; j < nVertices; j++)
            {
                data[i][j] = 0;
            }
        }
    }

    GraphwMatrix(int nv, int ne)
    {
        nVertices = nv;
        nEdges = ne;
        for (int i = 0; i < nVertices; i++)
        {
            for (int j = 0; j < nVertices; j++)
            {
                data[i][j] = 0;
            }
        }
        for (int i = 0; i < nEdges; i++)
        {
            int u, v;
            cout << "Enter u,v";
            cin >> u >> v;
            data[v][u] = 1;
            data[u][v] = 1;
        }
    }

    void getGraph(int nv, int ne)
    {
        nVertices = nv;
        nEdges = ne;
        for (int i = 0; i < nVertices; i++)
        {
            for (int j = 0; j < nVertices; j++)
            {
                data[i][j] = 0;
            }
        }
        for (int i = 0; i < nEdges; i++)
        {
            int u, v;
            cout << "Enter u,v";
            cin >> u >> v;
            data[v][u] = 1;
            data[u][v] = 1;
        }
    }

    void display()
    {
        if (nVertices > 0)
        {
            for (int i = 0; i < nVertices; i++)
            {
                for (int j = 0; j < nVertices; j++)
                {
                    cout << data[i][j] << "  ";
                }
                cout << endl;
            }
        }
        else
            cout << "Null Graph" << endl;
    }

    void bfs_traversal(int startVertex)
    {
        int u, v;
        int visited[N] = {0};
        queue<int> q;

        q.push(startVertex);
        visited[startVertex] = 1;

        while (!q.empty())
        {
            u = q.front();
            q.pop();
            cout << u << " ";
            for (int v = 0; v < nVertices; v++)
            {
                if (data[u][v] == 1 && visited[v] == 0)
                {
                    q.push(v);
                    visited[v] = 1;
                }
            }
        }
    }

    void dfs_traversal(int startvertex)
    {

        dfs_rec(startvertex);
    }

    void dfs_rec(int startvertex)
    {

        if (Visited[startvertex] == 0 && startvertex < nVertices) // for unvisited vertex
        {

            cout << startvertex << " ";
            Visited[startvertex] = 1; // it become visited now
            for (int v = 0; v < N; v++)
            {
                if (data[startvertex][v] == 1 && Visited[v] == 0)
                {
                    dfs_rec(v); // HERE We've used stack using recursion hence no need to add our external stack
                }
            }
        }
    }
};

int main()
{
    int ch;
    GraphwMatrix g1;
    while (1)
    {
        cout << "\n1.Create a graph \n2. Display \n3. BFS Traversal \n4. DFS Traversal \n0.EXIT  " << endl;
        cout << "Enter Your Choice : ";
        cin >> ch;

        if (ch == 0) // EXIT CALL
        {
            return 0;
        }
        else if (ch == 1) // Create
        {
            int nv, ne;
            cout << "Enter the No. of Vertices and No. of Edges : ";
            cin >> nv >> ne;
            g1.getGraph(nv, ne);
        }
        else if (ch == 2) // Display
        {
            g1.display();
        }
        else if (ch == 3) // BFS Traversal
        {
            int sv;
            cout << "Enter the start vertex : ";
            cin >> sv;
            g1.bfs_traversal(sv);
        }
        else if (ch == 4) // DFS Traversal
        {
            int sv;
            cout << "Enter the start vertex : ";
            cin >> sv;
            g1.dfs_traversal(sv);
        }

        else
        {
            cout << "WRONG CHOICE!!!!";
        }
    }
    return 0;
}
