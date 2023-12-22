# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean

#1.거리 배열

#2.큐를 선언
def point_valid(x , y , n) :
    return x >= 0 and x < n and  y>= 0 and y< n
def bfs(matr,n,start,parent):
    dist = [[float('inf') for _ in range(n)] for _ in range(n)]
    q = []
    q.append(start)

    d = [ [1,0] ,[0,1] , [0,-1] , [-1,0]]
    parent[start[0]][start[1]].append(-1)
    dist[start[0]][start[1]] = 0
    while q :
        u  = q[0]
        q.pop(0)
        for l in d :

            if point_valid(u[0] + l[0] , u[1] + l[1] , n) and matr[u[0] + l[0]][u[1] + l[1] ] == '1':
                if dist[u[0]+ l[0]][u[1] + l[1]] > dist[u[0]][u[1]] + 1 :
                    dist[u[0]+ l[0]][u[1] + l[1]] = dist[u[0]][u[1]] + 1 
                    q.append((u[0]+l[0] , u[1]+l[1]))
                    parent[u[0]+ l[0]][u[1] + l[1]].clear()
                    parent[u[0]+ l[0]][u[1] + l[1]].append(u)
                elif dist[u[0]+ l[0]][u[1] + l[1]] == dist[u[0]][u[1]] + 1 :
                    parent[u[0]+ l[0]][u[1] + l[1]].append(u)

    print(dist)
					
def find_path(paths,path,n,u,parent )	:

    if parent[u[0]][u[1]][0]== -1 :
        paths.append(path.copy())
        return paths
    for p in parent[u[0]][u[1]] :
        path.append(p)
        find_path(paths,path,n,p,parent)
        path.pop()
def print_path(matr , n,start,end):
    # start = (0,0)
    paths=[]
    path=[]
    parent=[[[] for _ in range(n)] for _ in range(n)]
    bfs(matr,n,start,parent)
    find_path(paths,path,n,end,parent)
    for k in paths:
        print(k)
n = int(input())
matr=[]
for i in range(n):
	matr.append(input().split())
print(matr)
print(n)
start = (0,0)
end = (n-1,n-1)
# parent=[[[] for _ in range(n)] for _ in range(n)]
# bfs(matr,n,start,parent)
print_path(matr,n,start,end)
# print(dist)