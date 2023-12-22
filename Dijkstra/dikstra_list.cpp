#include<vector>
#include<list>
#include<queue>
#include<set>
#include<iostream>

using namespace std; 
# define INF 0x3f3f3f3f 
  
// This class represents a directed graph using  
// adjacency list representation 
class Graph 
{ 
    int V;    // No. of vertices 
  
    // In a weighted graph, we need to store vertex  
    // and weight pair for every edge 
    list< pair<int, int> > *adj; 
  
public: 
    Graph(int V);  // Constructor 
  
    // function to add an edge to graph 
    void addEdge(int u, int v, int w); 
  
    // prints shortest path from s 
    void shortestPath(int s); 
}; 
  
// Allocates memory for adjacency list 
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list< pair<int, int> >[V]; 
} 
  
void Graph::addEdge(int u, int v, int w) 
{ 
    adj[u].push_back(make_pair(v, w)); 
    adj[v].push_back(make_pair(u, w)); 
} 


// Time Complexity :O(ElogV)
// Why O(ElogV)?
// We need MinHeap
// We need operation, DecreaseKey, ExtractMin

// 1.Parent , Vertices,ready
// Set all vertices INF, Parent Null
// Set  src node vertice 0
// DataStructure Set to check in SPT


//  2. select minimum distances node
// if node exists in SPT , pass
// traverse node, andcheck and update min distance
struct cmp
{
    bool operator()(pair<int,int> &a , pair<int,int> &b){
        return a.second>b.second;
    }
};


void Graph::shortestPath(int src)
{
    // 1
    vector<int> Vertices(V,INF);
    vector<int> Parent(V,-1);

    set<int> visited;
    priority_queue< pair<int,int> , vector<pair<int,int>> , cmp> mh; 
    // mh , <node, weight>
    
    Vertices[src] = 0;

    // 2
    mh.push(make_pair(src,0));

    while(!mh.empty()){
        int node = mh.top().first;
        visited.insert(node);
        mh.pop();

        for(auto i : adj[node]){
            // if( visited.find(i.first) != visited.end()) continue;
            
            if(Vertices[i.first] > Vertices[node] + i.second){
                Vertices[i.first] = Vertices[node] + i.second;
                mh.push(make_pair(i.first,i.second));
                Parent[i.first] = node;
            }
        }
    }

    for(int i = 0; i<V;i++){
        cout<<Vertices[i]<<endl;
    }
    int a = 0;


}


// Driver program to test methods of graph class 
int main() 
{ 
    // create the graph given in above fugure 
    int V = 9; 
    Graph g(V); 
  
    //  making above shown graph 
    g.addEdge(0, 1, 4); 
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
  
    g.shortestPath(0); 
  
    return 0; 
} 