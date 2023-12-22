#include<vector>
#include<list>
#include<iostream>
#include<queue>


using namespace std;


// 1.Visited,  Child(Queue)  , 

class Graph 
{ 
    int V;    // No. of vertices 
  
    // Pointer to an array containing adjacency 
    // lists 
    list<int> *adj;    
public: 
    Graph(int V);  // Constructor 
  
    // function to add an edge to graph 
    void addEdge(int v, int w);  
  
    // prints BFS traversal from a given source s 
    void BFS(int s);   
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); // Add w to v’s list. 
} 
  
void Graph::BFS(int s)
{
    vector<bool> visited(V, false);

    queue<int> child;

    child.push(s);

    // visited[s] = true;
    while(!child.empty())
    {
        int node = child.front();
        // visited[node] = true;
        child.pop();
        for(auto k : adj[node]){
            if(!visited[k]){
                visited[k]=true;
                child.push(k);
            }
        }
    }
    
    // Vertexsize를 조건으로 하면  Vertex가 경로에 연결되지 않은경우
    // 무한루프에 걸릴 것이다.

}

int main()
{

    // vector<bool> visited(V,false);
    // Create a graph given in the above diagram 
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n"; 
    g.BFS(2); 
    return 0;
}