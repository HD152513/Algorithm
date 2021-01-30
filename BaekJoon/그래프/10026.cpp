#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

char grid[100][100]; //�׸��� ���� 
char visited[100][100] = {0,}; //�湮 ó�� 
int n; //�׸��� ũ�� 

void BFS(int x, int y, int f){ //f: ���ϻ����� ����. 1�̸� ���ϻ��� 
	int xx[4] = {0, -1, 0, 1}; // �����¿� Ž�� �õ� 
	int yy[4] = {1, 0, -1, 0};
	queue<pair<int, int> > q; //queue ����
	q.push(make_pair(y, x)); //queue�� �������� �ִ´�.
	visited[y][x] = 1;
	if(grid[y][x]=='R'&& f == 1){ //���ϻ����̶�� ������ -> �ʷϻ� ���� �ٲ� 
		grid[y][x] = 'G';
	}
	char memo = grid[y][x]; //memo = ���� ������ Ž���ؾ� �ϱ� ������ RGB�� �ϳ��� ���� 
	
	while(!q.empty()){ //q�� empty�� �ƴҶ����� �ݺ� 
		int currentY = q.front().first; //q�� �� �պκ� Y�� current�� ����
		int currentX = q.front().second; //q�� �� �պκ�X�� current�� ���� 
		q.pop(); //pop 
		
		for(int i=0; i<4; i++){
			int nextY = currentY + yy[i]; //��ǥ ������Ʈ  
			int nextX =  currentX + xx[i]; //��ǥ ������Ʈ 
			if(grid[nextY][nextX]=='R' && f ==1){  //���ϻ����̶�� ������ -> �ʷϻ� ���� �ٲ� 
				grid[nextY][nextX] = 'G';
			}
			if( (nextX>=0 && nextX< n) && (nextY>=0 && nextY<n) && grid[nextY][nextX]== memo &&visited[nextY][nextX]==0){ //���� ������Ʈ�� ��ǥ�� �����ϴ� ��ǥ�̰�, �׸��� ��ǥ�� memo�� ���� �����̰�, �湮���� �ʾҴ�  ��ǥ�̸�,  
				q.push(make_pair(nextY, nextX)); //q�� ���� ��ǥ�� �־��ش�.  
				visited[nextY][nextX] = 1; //�ش� ��ǥ �湮 ó��  
			} 
		}
	}
}

int main(){
	int cnt = 0; //���ϻ����� �ƴ� ����� ���� ���� ������ ��  
	int cnt_f = 0; //���ϻ����� ����� ���� ���� ������ ��  
	scanf("%d", &n); //�׸����� ũ�⸦ �Է¹޴´�.   
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf(" %c", &grid[i][j]); 
		}
	}
	//���ϻ����� �ƴ� ����� ���� ���� ������ ���� ���� 
	for(int i=0; i<n; i++){ 
		for(int j=0; j<n; j++){
			if(visited[i][j]==0){ //���� �湮���� ���� �׸��尡 �ִٸ�, �װ����� BFSŽ���� ���� 
				BFS(j,i,0);
				cnt++; //������ ��++ 
			}
		}
	}
	//���ϻ����� ����� ���� ���� ������ ���� ���� 
	fill(visited[0], visited[100], 0); //�湮 ó���� 0���� �ʱ�ȭ 
	for(int i=0; i<n; i++){ 
		for(int j=0; j<n; j++){
			if(visited[i][j]==0){ //���� �湮���� ���� �׸��尡 �ִٸ�, �װ����� BFSŽ���� ���� 
				BFS(j,i,1);
				cnt_f++; //������ ��++ 
			}
		}
	}
	printf("%d %d\n", cnt, cnt_f);
}
