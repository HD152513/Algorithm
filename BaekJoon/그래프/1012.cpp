#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int field[50][50] ={0,}; //���߹� ���� 
int visited[50][50] = {0,}; //�湮 ó�� 
int m, n; //���߹��� ���α��� m, ���α��� n; 

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
			if( (nextX>=0 && nextX< n) && (nextY>=0 && nextY<m) && field[nextY][nextX] &&visited[nextY][nextX]==0){ //���� ������Ʈ�� ��ǥ�� �����ϴ� ��ǥ�̰�, �ش� �� ��ǥ�� ����߰� �ɾ����ְ�, �湮���� �ʾҴ�  ��ǥ�̸�,  
				q.push(make_pair(nextY, nextX)); //q�� ���� ��ǥ�� �־��ش�.  
				visited[nextY][nextX] = 1; //�ش���ǥ �湮 ó��  
			} 
		}
	}
}

int main(){
	int t, k; //t: �׽�Ʈ ���̽�, k: ���߰� �ɾ����ִ� ��ġ�� ���� 
	int x, y; //������ ��ġ x,y 
	scanf("%d", &t); //�׽�Ʈ ���̽� ���� �Է� 
	for(int l=0; l<t; l++){//
		int cnt = 0; //������������ ������ 
		scanf("%d%d%d", &m, &n, &k); //���߹��� ����, ���� ũ�⸦ �Է¹޴´�.   
		for(int i=0; i<k; i++){
			scanf("%d%d", &x, &y);
			field[x][y] = 1;
		}
		for(int i=0; i<m; i++){ 
			for(int j=0; j<n; j++){
				if(visited[i][j] == 0 && field[i][j]==1){ //���� �湮���� ���� ���̰�, ���߰� �ɾ����ִٸ�,  
					BFS(j,i);
					cnt++; //������������ �� ++ 
				}
			}
		}
		fill(visited[0], visited[50], 0); //�湮 ó���� 0���� �ʱ�ȭ  
		fill(field[0], field[50], 0); //���߹絵 0���� �ʱ�ȭ  
		printf("%d\n", cnt);
	}
}
