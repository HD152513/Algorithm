#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int maze[100][100];
int visited[100][100] = {0,};
int n, m;

void BFS(int x, int y){
	int xx[4] = {0, 1, 0, -1}; // �Ʒ�, ����, ��, ���� ������ Ž�� �õ� 
	int yy[4] = {-1, 0, 1, 0};
	queue<pair<int, int> > q; //queue ����
	q.push(make_pair(x, y)); //queue�� �������� �ִ´�.
	visited[x][y]++; 
	while(!q.empty()){ //q�� empty�� �ƴҶ����� �ݺ� 
		int currentX = q.front().first; //q�� �� �պκ� x�� current�� ����
		int currentY = q.front().second; //q�� �� �պκ�y�� current�� ���� 
		q.pop(); //pop 
		for(int i=0; i<4; i++){
			int nextX =  x + xx[i]; //��ǥ ������Ʈ 
			int nextY = y + yy[i]; //��ǥ ������Ʈ  
			if( (nextX>0 && nextX< n) && (nextY>0 && nextY<m)){ //���� ������Ʈ�� ��ǥ�� �����ϴ� ��ǥ���,  
				q.push(make_pair(nextX, nextY)); //q�� ���� ��ǥ�� �־��ش�.  
				visited[nextX][nextY] = visited[currentX][currentY] + 1; //�湮 ó�� 
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
	printf("%d\n", visited[n-1][m-1]+1);
}
