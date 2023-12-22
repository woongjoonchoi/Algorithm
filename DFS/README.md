# DFS.CPP

### 갈 수 있을 때 까지 간다.

## Application
 
1.Spanning Tree

2.Path FInding

0321 : 최단경로 저장을 어떻게 해야하는가
    스택을 사용

주의점 : 최소 경로를 찾는데 DFS는 적합하지 않다.

Q: 행렬에서 영역의 개수를 구하고 영역의 넓이를 출력하시오
    영역: 1로 이루어진 부분

## input: standard input

first row: matrix size

second row: matrix

## output: 

first row : count of realm

second row : area of realm (increasing order)


ex)
input:

6

0 1 1 0 0 0  
0 1 1 0 1 1  
0 0 0 0 1 1  
0 0 0 0 1 1  
1 1 0 0 1 0  
1 1 1 0 0 0  

output:

3  
4 5 7
