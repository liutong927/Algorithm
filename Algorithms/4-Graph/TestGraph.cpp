//**************************************************************
//          main test routine for graph algorithms
//**************************************************************

#include <fstream>
#include <iostream>
#include "Graph.h"
#include "DepthFirstSearch.h"
#include "DepthFirstPaths.h"
#include "BreadthFirstPaths.h"

using namespace std;

void GraphConstruct_TestClient()
{
    ifstream inputFile("tinyG.txt");
    Graph g(inputFile);
    cout << g.ToString() << endl;
}

void GraphDFS_TestClient(int source)
{
    ifstream inputFile("tinyG.txt");
    Graph g(inputFile);
    DepthFirstSearch dfs(g, source);

    cout << "All vertices connected to source vertex " << source << ":" << endl;

    // loop all vertices, print vertices connected to source.
    for (int v = 0; v < g.Vertices(); v++)
    {
        if (dfs.Marked(v))
        {
            cout << v << " " << endl;
        }
    }

    // print whether the graph is connected.
    // the graph is connected if and only if the search marked all of its vertices.
    cout << "The graph is ";
    if (dfs.Count() != g.Vertices())
    {
        cout << "NOT";
    }
    cout << " connected.\n" << endl;
}

void GraphDFSPaths_TestClient(int source)
{
    ifstream inputFile("tinyCG.txt");
    Graph g(inputFile);
    DepthFirstPaths paths(g, source);

    cout << "DFS Paths from source " << source << " to each vertex connected to source:" << endl;

    // loop all vertices, print paths connected to source.
    for (int v = 0; v < g.Vertices(); v++)
    {
        cout << source << " to " << v << ": ";
        if (paths.HasPathTo(v))
        {
            std::stack<int> pathStack(paths.PathTo(v));

            // get path vertex from start by pop the stack.
            while (!pathStack.empty())
            {
                int pathNode = pathStack.top();

                if (pathNode == source)
                {
                    cout << pathNode;
                }
                else
                {
                    cout << "-" << pathNode;
                }

                pathStack.pop();
            }
            cout << endl;
        }
    }
}

void GraphBFSPaths_TestClient(int source)
{
    ifstream inputFile("tinyCG.txt");
    Graph g(inputFile);
    BreadthFirstPaths paths(g, source);

    cout << "BFS Paths from source " << source << " to each vertex connected to source:" << endl;

    // loop all vertices, print paths connected to source.
    for (int v = 0; v < g.Vertices(); v++)
    {
        cout << source << " to " << v << ": ";
        if (paths.HasPathTo(v))
        {
            std::stack<int> pathStack(paths.PathTo(v));

            // get path vertex from start by pop the stack.
            while (!pathStack.empty())
            {
                int pathNode = pathStack.top();

                if (pathNode == source)
                {
                    cout << pathNode;
                }
                else
                {
                    cout << "-" << pathNode;
                }

                pathStack.pop();
            }
            cout << endl;
        }
    }
}

int main()
{
    GraphConstruct_TestClient();
    GraphDFS_TestClient(0);
    GraphDFS_TestClient(9);
    GraphDFSPaths_TestClient(0);
    GraphBFSPaths_TestClient(0);
}
