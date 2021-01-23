#include <iostream>
#include <vector>
using namespace std;

int number = 10;
int visited[10]; //�湮 üũ
vector<int> node[11]; // node �� ���� 1���� �� �� �ֵ��� 8�� ���� 
 
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
	
	node[1].push_back(5);
	node[5].push_back(1);
	
	node[1].push_back(9);
	node[9].push_back(1);
	
	node[2].push_back(3);
	node[3].push_back(2);
	
	node[5].push_back(6);
	node[6].push_back(5);
	
	node[5].push_back(8);
	node[8].push_back(5);
	
	node[9].push_back(10);
	node[10].push_back(9);
	
	node[3].push_back(4);
	node[4].push_back(3);
	 
	node[6].push_back(7);
	node[7].push_back(6);
	
	DFS(1); //dfs ����
	return 0;  
} 
