#include <vector>
#include<regex>
#include<iostream>
#include<sstream>
using namespace std;

int MOD = 20170805;


vector<vector<int>>update(501,vector<int>(501,0));
vector<vector<vector<int>>> path(501, vector<vector<int>> (501,vector<int>(2,0)));

// vector<vector<vector<int>>> path(501, vector<vector<int>> (501,vector<int>()));
// temp : 0 : 왼쪽에서 옴, 1: 위에서옴
// 코드의 return을 vector바꿧으므로 , -2 위치가 아닌 -1위치에서 0,1 index위치의값을 받는다.
// update,path변수를 만들어서 두번할일을 한번한다.
// path구할때 %MOD를 해준다.
void dyn(vector<vector<int>> city_map,int m , int n )
{

    for(int i = 0;i <m;i++){
        for(int j= 0;j<n;j++){
            if(i==0 &&j==0){
                // path[i][j] = vector<int>(2,0);
                path[i][j][0] = 0;
                path[i][j][1] = 0;
                continue;
            }
            // 
            int left= 0,up=0;
            if(j>=1){
                if(city_map[i][j-1] == 2) left = path[i][j-1][0];
                if(i==0 && j==1) left = 1;
                else if(city_map[i][j-1] == 0) left = (path[i][j-1][0] + path[i][j-1][1])%MOD ;
            }
            if(i>=1){
                if(city_map[i-1][j] == 2) up = path[i-1][j][1];
                if(i==1 && j==0) up = 1;
                else if(city_map[i-1][j] == 0) up = (path[i-1][j][0] + path[i-1][j][1])%MOD ;
            }
            path[i][j][0]=left;
            path[i][j][1]=up;

            // path[i][j].push_back(left);
            // path[i][j].push_back(up);
            
        }
    }
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer=0;
    dyn(city_map,m,n);
    answer= (path[m-1][n-1][0]+path[m-1][n-1][1])%MOD;
    answer = answer % MOD;
    return answer;
}

int main()
{
    vector<vector<int>> city_map(3,vector<int>());
    regex re1("\\d");
    smatch match;
    string s = "";
    // cin>>s;
    
    int m =0,n=0,k=0;
    getline(cin,s);
    cout<<s<<endl;
    int count=0,count1=0;
    while(regex_search(s,match,re1)){
        stringstream ss;
        if(count==0 && m==0){
            ss<<match[0];
            ss>>m;
            count+=1;
        }
        else if(count==1 && n==0){
            ss<<match[0];
            cout<<match[0];
            ss>>n;
            count=0;
        }
        else{
            ss<<match[0];
            ss>>k;
            city_map[count1].push_back(k);
            count+=1;
            if(count==n){
                count=0;
                count1+=1;
            }
        }
        
        // for(int i = 0; i<match.size();i++){
        //     cout<<"match : "<<match[i]<<endl;
        // }
        
        s= match.suffix();
    }

    solution(m,n,city_map);
    return 0;


}