# Dijkstra


## Algorithm

Dijkstar is Algorithm to get  Minimum SPT

1. Set Vertex_Distacne   INF , Set Parent -1.    
Set start  Vertex_Distance 0
We use Vector dist to save Vertex_Distance , and Vector parent to save before visited node to print Spanining Tree 

2. While All Graph's node(vertex) not in SPT , Select minimum Vertex_Distance's Node(vertex)  u ,
And For All Node v(or All Edge) , Compare dist[v]  and dist[u] + weight(u-v)  , if dist[v]  > dist[u] + weight(u-v).     
Update dist[v] to dist[u] + weight(u-v)



### Time Complexity O(V**2)


Graph Representation By Adjacency Matrix


Referrence: https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/?ref=lbp

### Time Complexity O(E*Log(E))


Graph Representation By Adjacency List, 
And Use Priority Queue , Set in C++ STL to get mininum Distance

### Time Complexity O(E*Loge(V))

Graph Representation By Adjacency List , 
And Use Heap ,
We must implementate Decrease Key , and extractMin .

Different From Second Method ,  We use Heap to save Vertex_Distance , and When dist[v] > dist[u] + weight(u-v) , update Heap

