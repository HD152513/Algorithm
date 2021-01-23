#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int number = 8; //����� ����
int visited[8]; //�湮 üũ
vector<int> node[9]; // node �� ���� 1���� �� �� �ֵ��� 8�� ���� 

void BFS(int start){
	queue<int> q; //queue ����
	q.push(start); //queue�� �������� �ִ´�. 
	visited[start] = true;//�湮�ϸ� true 
	while(!q.empty()){ //q�� empty�� �ƴҶ����� �ݺ� 
		int current = q.front(); //q�� �� �պκ��� current�� ���� 
		q.pop(); //pop 
		printf("%d ", current); //current�� ��� 
		for(int i=0; i<node[current].size(); i++){ //current �� ������ node�� �湮�Ѵ�.  
			int next = node[current][i]; //current �� ������ node�� next 
			if(!visited[next]){ //�湮���� ���� ����� 
				q.push(next); //q�� next�� �־��ش�. 
				visited[next] = true; //�湮ó��  
			}
		}
	}
}

int main(){
	//�� ��带 �����Ѵ�.  
	node[1].push_back(2);
	node[2].push_back(1);
	
	node[1].push_back(3);
	node[3].push_back(1);
	
	node[2].push_back(4);
	node[4].push_back(2);
	
	node[2].push_back(5);
	node[5].push_back(2);
	
	node[3].push_back(6);
	node[6].push_back(3);
	
	node[3].push_back(7);
	node[7].push_back(3);
	
	node[5].push_back(8);
	node[8].push_back(5);
	
	BFS(1); //bfs ����
	return 0;  
} 
