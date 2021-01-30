#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int maze[100][100]; //�̷� ���� 
int visited[100][100] = {0,}; //���������κ����� �Ÿ�
int n, m; //��, �� 

void BFS(int x, int y){
	int xx[4] = {0, -1, 0, 1}; // �����¿� Ž�� �õ� 
	int yy[4] = {1, 0, -1, 0};
	queue<pair<int, int> > q; //queue ����
	q.push(make_pair(y, x)); //queue�� �������� �ִ´�.
	visited[y][x] = 1;
	
	while(!q.empty()){ //q�� empty�� �ƴҶ����� �ݺ� 
		int currentY = q.front().first; //q�� �� �պκ� Y�� current�� ����
		int currentX = q.front().second; //q�� �� �պκ�X�� current�� ���� 
		q.pop(); //pop 
		
		for(int i=0; i<4; i++){
			int nextY = currentY + yy[i]; //��ǥ ������Ʈ  
			int nextX =  currentX + xx[i]; //��ǥ ������Ʈ 
			if( (nextX>=0 && nextX< m) && (nextY>=0 && nextY<n) && maze[nextY][nextX]==1 &&visited[nextY][nextX]==0){ //���� ������Ʈ�� ��ǥ�� �����ϴ� ��ǥ�̰�, �̷���ǥ�� 1(�湮 ����),�湮���� �ʾҴ�  ��ǥ�̸�,  
				q.push(make_pair(nextY, nextX)); //q�� ���� ��ǥ�� �־��ش�.  
				visited[nextY][nextX] = visited[currentY][currentX] + 1; //�Ÿ� + 1 
			} 
		}
	}
}

int main(){
	scanf("%d%d", &n, &m); //�̷��� ���� n, ���� m�� �Է¹޴´�.   
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			scanf("%1d", &maze[i][j]); 
		}
	}
	BFS(0, 0); 
	printf("%d\n", visited[n-1][m-1]);
}
