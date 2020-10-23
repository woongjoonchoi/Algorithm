#include <iostream>
#include <sstream>
#include <vector>
using namespace std;



int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int dfs(int x , int y , int **matrix , int sizeOfMatrix,vector<vector<int> > &visited , int realm){
		if(visited[x][y]) return realm;
		visited[x][y]  = 1;
		realm+=1;
		for(int i = 0; i< 4 ; i++){
			if(dx[i]+x >= 0 && dx[i]+x < sizeOfMatrix && dy[i]+y >= 0 && dy[i]+y < sizeOfMatrix 
            && matrix[dx[i]+x][dy[i]+y]){
				realm = dfs(dx[i]+x,dy[i]+y,matrix, sizeOfMatrix,visited,realm);
			}
		}
	return realm;
}

void solution(int sizeOfMatrix, int **matrix) {
  // TODO: 이곳에 코드를 작성하세요.
	vector<vector<int> > visited(sizeOfMatrix , vector<int>(sizeOfMatrix,0));
	int count=0;
	vector<int> ter;
	for(int i = 0; i < sizeOfMatrix;i++){
		for(int j = 0; j < sizeOfMatrix;j++){
			if(*(*(matrix+i)+j) == 1) {
				int realm = 0;
				realm =dfs(i,j,matrix,sizeOfMatrix,visited,realm);
				
				if(realm>0) {
					count+=1;
					ter.push_back(realm);
				}
			}
			// cout<<*(*(inputData.matrix+i)+j)<<' ';
		}
		// cout<<endl;
	}
	cout<<count<<endl;
}

struct input_data {
  int sizeOfMatrix;
  int **matrix;
};

void process_stdin(struct input_data& inputData) {
  string line;
  istringstream iss;

  getline(cin, line);
  iss.str(line);
  iss >> inputData.sizeOfMatrix;

  inputData.matrix = new int*[inputData.sizeOfMatrix];
  for (int i = 0; i < inputData.sizeOfMatrix; i++) {
    getline(cin, line);
    iss.clear();
    iss.str(line);
    inputData.matrix[i] = new int[inputData.sizeOfMatrix];
    for (int j = 0; j < inputData.sizeOfMatrix; j++) {
      iss >> inputData.matrix[i][j];
    }
  }
}

int main() {
  struct input_data inputData;
  process_stdin(inputData);

  solution(inputData.sizeOfMatrix, inputData.matrix);
  return 0;
}