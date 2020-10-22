#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <limits.h>
#include <set>
using namespace std;
int min_dist(vector<int> dist ,set<int> visited)
{
    int min_d = INT_MAX , index = -1;

    for(int i = 0 ; i<dist.size();i++){
        if(dist[i]<min_d && visited.find(i)==visited.end() ){
            index = i; min_d = dist[i];
        }
    }
    return index;
}
void printSolution(vector<int> dist) 
{ 
    printf("Vertex \t\t Distance from Source\n"); 
    for (int i = 0; i < dist.size(); i++) 
        printf("%d \t\t %d\n", i, dist[i]); 
} 
void dijkstra(vector<vector<int>> graph , int src)
{
    // 1. set dist INF , parent -1
    vector<int> dist(graph.size(),INT_MAX);
    vector<int> parent(graph.size(),-1);
    set<int> visited;
    // 추가사항 방문했는지에 대한 노드가 필요
    // 2. set strat_node(src) dist 0
    dist[src] = 0;
    // 3. select minium dist node and update  minimum spaning tree 
    while(visited.size() != graph.size()) {
        int node = min_dist(dist, visited);

        for(int j = 0 ; j< graph.size();j++){
            if(graph[node][j] != 0 && dist[j] > dist[node] + graph[node][j]  ){
                dist[j] = dist[node] + graph[node][j];
                parent[j] = node;
            }
        }
        visited.insert(node);
    }
    printSolution(dist);
    // dist

}

int main()
{
    
    vector<vector<int>> graph(9,vector<int>(9));
    vector<int> temp;
    // cout<<"graph size: "<<graph.size()<<"  graph[0].size() : "<<graph[0].size()<<endl;
    int graph2[][9] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                    { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                    { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                    { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                    { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                    { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                    { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                    { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                    { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
    for(int i  = 0 ; i< 9; i++){
        // cout<<*(*graph2+i)<<endl;
        copy(*(graph2+i), *(graph2+i)+9 ,graph[i].begin());
    }
    // for(auto c: graph){
    //     for(auto k : c){
    //         cout<< k << " ";
    //     }
    //     cout<<endl;
    // }
    dijkstra(graph,0);
    return 0;
}