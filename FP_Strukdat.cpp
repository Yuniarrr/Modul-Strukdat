#include <bits/stdc++.h>
#include <list>
#include <graphics.h>
using namespace std;

#define INF 0x3f3f3f3f // The distance to other vertices is initialized as infinite
// iPair ==> Integer Pair
typedef std::pair<int, int> iPair;

class Vertex
{
private:
    int urut;
    int x, y;
    string tempat;

public:
    Vertex(int _urut)
    {
        urut = _urut;
    }

    Vertex(int _urut, int _x, int _y, string _tempat)
    {
        x = _x;
        y = _y;
        urut = _urut;
        tempat = _tempat;
    }

    int get_urut()
    {
        return urut;
    }

    int get_x()
    {
        return x;
    }

    int get_y()
    {
        return y;
    }

    string get_tempat()
    {
        return tempat;
    }
};

class compare
{
public:
    bool operator()(const iPair &lhs, const iPair &rhs)
    {
        return rhs.first < lhs.first;
    }
};

class Graph // Graph structure
{
    int V;            // No. of vertices in the graph
    list<iPair> *adj; // the list of pair to store vertex and its weight
    list<Vertex> *vertex;

public:
    // Constructor that accept number of vertices in graph
    Graph(int V) // allocate the vertex memory
    {
        this->V = V;              // assign the vertex
        adj = new list<iPair>[V]; // allocate space for vertices
        vertex = new list<Vertex>[V];
    }
    void addEdge(int u, int v, int w); // add edges in the graph
    void storeVertex(int urut, int x, int y, string tempat); // store the vertex

    void tampilList();               // menampilkan adjacency list

    // prints shortest path from s
    void shortestPathingraph(int s); // pass source vertex

    void shortestPathingraphWithDestination(int s, int d); // pass source vertex

    void shortestPathingraphWithDestination(string s, string d); // pass source vertex

    void printPath(int currentVertex, vector<int> parent);

    void printSolution(int src, vector<int> dist, vector<int> parent); // print the solution
    
    void printSolutionWithDestination(int src, int dest, vector<int> dist, vector<int> parent); // print the solution
};

// menampilkan adjacency list
void Graph::tampilList()
{
    list<int> la;
    list<iPair>::iterator i;

    for (int v = 0; v < V; v++)
    {
        cout << v;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            cout << "-> " << (*i).first;
        }
        cout << ("\n");
    }
    cout << endl;
}

// store the vertex
void Graph::storeVertex(int urut, int x, int y, string tempat)
{
    vertex[urut].push_back(Vertex(urut, x, y, tempat));
}

void Graph::addEdge(int u, int v, int w) // add an edge
{
    adj[u].push_back(make_pair(v, w)); // make a pair of vertex and weight and // add it to the list
    adj[v].push_back(make_pair(u, w)); // add oppositely by making a pair of weight and vertex
}
// Calling function outside the Graph class
void Graph::shortestPathingraph(int src) // src is the source vertex
{
    // Create a priority queue to store vertices that
    // are being preprocessed.
    std::priority_queue<iPair, std::vector<iPair>, compare> pq;
    vector<int> dist(V, INF);   // All distance from source are infinite
    pq.push(make_pair(0, src)); // push spurce node into the queue
    dist[src] = 0;              // distance of source will be always 0

    // Create a vector for parent array to store shortest path tree
    vector<int> parent(V);

    // Initialize parent of source vertex as -1
    parent[src] = -1;

    /* Looping till priority queue becomes empty (or all
    distances are not finalized) */
    while (!pq.empty())
    {
        // The first vertex in pair is the minimum distance
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        int u = pq.top().second;
        pq.pop();

        // 'i' is used to get all adjacent vertices of a vertex
        list<iPair>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = (*i).first;
            int weight = (*i).second;

            //  If there is shorted path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                // Updating distance of v
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
                parent[v] = u;
            }
        }
    }

    // print shortest distances stored in dist[]
    printSolution(src, dist, parent);

    // printf("\nVertex \tDistance from Source %d: \n", src); // Print the result
    // for (int i = 0; i < V; ++i)
    // {
    //     printf("%d \t\t %d\n", i, dist[i]); // The shortest distance from source
    // }
}

void Graph::shortestPathingraphWithDestination(int src, int dest) // src is the source vertex
{
    // Create a priority queue to store vertices that
    // are being preprocessed.
    std::priority_queue<iPair, std::vector<iPair>, compare> pq;
    vector<int> dist(V, INF);   // All distance from source are infinite
    pq.push(make_pair(0, src)); // push spurce node into the queue
    dist[src] = 0;              // distance of source will be always 0

    // Create a vector for parent array to store shortest path tree
    vector<int> parent(V);

    // Initialize parent of source vertex as -1
    parent[src] = -1;

    /* Looping till priority queue becomes empty (or all
    distances are not finalized) */
    while (!pq.empty())
    {
        // The first vertex in pair is the minimum distance
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        int u = pq.top().second;
        pq.pop();

        // 'i' is used to get all adjacent vertices of a vertex
        list<iPair>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = (*i).first;
            int weight = (*i).second;

            //  If there is shorted path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                // Updating distance of v
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
                parent[v] = u;
            }
        }
    }

    // print shortest distances stored in dist[]
    // printSolution(src, dist, parent);
    printSolutionWithDestination(src, dest, dist, parent);

    // printf("\nVertex \tDistance from Source %d: \n", src); // Print the result
    // for (int i = 0; i < V; ++i)
    // {
    //     printf("%d \t\t %d\n", i, dist[i]); // The shortest distance from source
    // }
}

void Graph::shortestPathingraphWithDestination(string source, string destination) // src is the source vertex
{
    list<Vertex>::iterator i;
    int src, dest;

    for (int v = 0; v < V; v++)
    {
        for (i = vertex[v].begin(); i != vertex[v].end(); ++i)
        {
            if ((*i).get_tempat() == source)
            {
                src = (*i).get_urut();
            }
            if ((*i).get_tempat() == destination)
            {
                dest = (*i).get_urut();
            }
        }
    }
    // Create a priority queue to store vertices that
    // are being preprocessed.
    std::priority_queue<iPair, std::vector<iPair>, compare> pq;
    vector<int> dist(V, INF);   // All distance from source are infinite
    pq.push(make_pair(0, src)); // push spurce node into the queue
    dist[src] = 0;              // distance of source will be always 0

    // Create a vector for parent array to store shortest path tree
    vector<int> parent(V);

    // Initialize parent of source vertex as -1
    parent[src] = -1;

    /* Looping till priority queue becomes empty (or all
    distances are not finalized) */
    while (!pq.empty())
    {
        // The first vertex in pair is the minimum distance
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        int u = pq.top().second;
        pq.pop();

        // 'i' is used to get all adjacent vertices of a vertex
        list<iPair>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = (*i).first;
            int weight = (*i).second;

            //  If there is shorted path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                // Updating distance of v
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
                parent[v] = u;
            }
        }
    }

    // print shortest distances stored in dist[]
    // printSolution(src, dist, parent);
    printSolutionWithDestination(src, dest, dist, parent);
}

void Graph::printSolutionWithDestination(int src, int dest, vector<int> dist, vector<int> parent)
{
    list<Vertex>::iterator i;

    int x, y;
    string s;
    string Tempat;

    initwindow(800, 600, "Tugas Nama 5027211025");

    int n = dist.size();
    printf("Vertex\t Distance\tPath"); // Print the result

    for (int i = 0; i < n; i++)
    {
        if(i == dest){
            printf("\n%d -> %d \t %d\t\t ", src, i, dist[i]);
            printPath(i, parent);
        }
    }

    char sNum[10];
    char sTempat[20];
    for (int v = 0; v < V; v++)
    {
        for (i = vertex[v].begin(); i != vertex[v].end(); ++i)
        {
            x = (*i).get_x();
            y = (*i).get_y();
            s = to_string((*i).get_urut());
            Tempat = (*i).get_tempat();
            strcpy(sNum, s.c_str());
            strcpy(sTempat, Tempat.c_str());
            circle(x, y, 10);
            outtextxy(x, y + 15, sNum);
            outtextxy(x, y + 30, sTempat);
        }
    }

    while (!kbhit())
    {
        delay(200);
    }
}

void Graph::printSolution(int src, vector<int> dist, vector<int> parent)
{
    list<Vertex>::iterator i;

    int x, y;
    string s;

    initwindow(800, 600, "Tugas Nama 5027211025");

    int n = dist.size();
    printf("Vertex\t Distance\tPath"); // Print the result

    for (int i = 0; i < n; i++)
    {
        if(i != src){
            printf("\n%d -> %d \t %d\t\t ", src, i, dist[i]);
            printPath(i, parent);
        }
    }

    for (int v = 0; v < V; v++)
    {
        for (i = vertex[v].begin(); i != vertex[v].end(); ++i)
        {
            x = (*i).get_x();
            y = (*i).get_y();
            char sNum[10];
            s = to_string((*i).get_urut());
            strcpy(sNum, s.c_str());
            circle(x, y, 10);
            outtextxy(x, y + 15, sNum);
        }
    }
    
    for (int i = 0; i < V; i++)
    {
        for (list<iPair>::iterator j = adj[i].begin(); j != adj[i].end(); j++)
        {
            for (list<Vertex>::iterator k = vertex[i].begin(); k != vertex[i].end(); k++)
            {
                for (list<Vertex>::iterator l = vertex[(*j).first].begin(); l != vertex[(*j).first].end(); l++)
                {
                    if(parent[(*j).first] == i){
                        setcolor(RED);
                        line((*k).get_x(), (*k).get_y(), (*l).get_x(), (*l).get_y());
                    }
                }
            }
        }
    }

    while (!kbhit())
    {
        delay(200);
    }
}

// Function to print shortest path from source to j
// using parent array
void Graph::printPath(int currentVertex, vector<int> parent)
{
    // Base Case : If j is source
    if (currentVertex == -1) {
		return;
	}

	printPath(parent[currentVertex], parent);
    printf("%d ", currentVertex);

    if(parent[currentVertex] != -1){
        list<Vertex>::iterator i = vertex[currentVertex].begin();
        list<Vertex>::iterator j = vertex[parent[currentVertex]].begin();

        int x1 = (*i).get_x();
        int y1 = (*i).get_y();

        int x2 = (*j).get_x();
        int y2 = (*j).get_y();

        line(x1, y1, x2, y2);
    }
}

int main()
{
    int V = 9;          // vertices in given graph are 9
    Graph g(V);         //  call Constructor by creating an object of graph
    g.addEdge(0, 1, 4); // add root node with neighour vertex and weight
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.storeVertex(0, 100, 250, "A");
    g.storeVertex(1, 200, 150, "B");
    g.storeVertex(2, 300, 150, "C");
    g.storeVertex(3, 400, 150, "D");
    g.storeVertex(4, 500, 250, "E");
    g.storeVertex(5, 400, 350, "F");
    g.storeVertex(6, 300, 350, "G");
    g.storeVertex(7, 200, 350, "H");
    g.storeVertex(8, 300, 250, "I");

    g.tampilList();
    // g.shortestPathingraph(0); // call the function to find shortest path of graph
    // g.shortestPathingraphWithDestination(0, 5);

    // string src, dest;
    // cout << "Masukkan tempat awal : ";
    // cin >> src;
    // cout << "Masukkan tempat tujuan : ";
    // cin >> dest;

    g.shortestPathingraphWithDestination("A", "F");
    
    return 0;                 // end of main function()
}