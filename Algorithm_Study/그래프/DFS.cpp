#include <iostream>
#include <vector>
using namespace std;

int number = 7;
int visited[7]; //�湮 üũ
vector<int> node[8]; // node �� ���� 1���� �� �� �ֵ��� 8�� ���� 
 
void DFS(int x){
	if(visited[x]){ //x��带 �湮�ߴٸ�,  ����  
		return; 
	}
	visited[x] = true; //ó�� �湮�� ����� �湮ó�� 
	printf("%d ", x);
	for(int i=0; i<node[x].size(); i++){ //x �� ������ node�� �湮�Ѵ�.  
		int y = node[x][i]; //���� ��忡 ���� dfs�� �����Ѵ�.  
		DFS(y);
	}
}

int main(){
	//�� ��带 �����Ѵ�.  
	node[1].push_back(2);
	node[2].push_back(1);
	
	node[1].push_back(3);
	node[3].push_back(1);
	
	node[2].push_back(3);
	node[3].push_back(2);
	
	node[2].push_back(4);
	node[4].push_back(2);
	
	node[2].push_back(5);
	node[5].push_back(2);
	
	node[3].push_back(6);
	node[6].push_back(3);
	
	node[3].push_back(7);
	node[7].push_back(3);
	
	node[4].push_back(5);
	node[5].push_back(4);
	 
	node[6].push_back(7);
	node[7].push_back(6);
	
	DFS(1); //dfs ����
	return 0;  
} 
