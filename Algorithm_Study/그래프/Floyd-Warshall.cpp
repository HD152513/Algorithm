#include <iostream>

int number = 4;
int INF = 10000000;

int arr[4][4] = { //�迭  �ʱ�ȭ 
	{INF, INF, -2, INF},
	{4, INF, 3, INF},
	{INF, INF, INF, 2},
	{INF, -1, INF, INF}
};

void floydWarshall(){ //�÷��̵� �ͼ� �Լ� ����  
	int result[number][number]; //��� �׷��� 
	for(int i=0; i<number; i++){ //��� �׷����� arr�׷����� �ʱ�ȭ  
		for(int j=0; j<number; j++){
			result[i][j] = arr[i][j];
		}
	}
	for(int k=0; k<number; k++){ //k: ���İ��� ��� 
		for(int i=0; i<number; i++){ //i: ��� ���  
			for(int j=0; j<number; j++){  //j: ���� ���  
				if(result[i][k] + result[k][j] < result[i][j]){
					result[i][j] = result[i][k] + result[k][j];
				}
			}
		}
	}
	for(int i =0; i<number; i++){
		for(int j=0; j<number; j++){
			printf("%3d ", result[i][j]); //��� �׷��� ���  
		}
		printf("\n");
	}
} 
int main(){
	floydWarshall();
}
