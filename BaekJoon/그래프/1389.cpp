#include <iostream>
using namespace std;
int INF = 99999999;

int arr[101][101]; //�迭 �ʱ�ȭ  

void floydWarshall(int number){ //�÷��̵� �ͼ� �Լ� ����  
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
	
	//�ɺ� ������ 
	int idx = 0; //�ɺ� �������� ���� ���� ���� idx�� ã�� ���� 
	int min = 99999999; //�ּҰ� min 
	for(int i=0; i<number; i++){
		int sum=0; //sum�� 0���� �ʱ�ȭ  
		for(int j=0; j<number; j++){
			sum+=result[i][j]; //�ɺ����� ���� ���Ѵ�.  
		}
		if(sum<min){ //min���� ���� �۴ٸ� ������Ʈ  
			idx = i;  
			min = sum;
		}
	}
	cout<<idx+1;
} 
int main(){
	int n,m,a,b,i,j;
	cin>>n>>m;//�����Ǽ� n, ģ�� ������ �� m 
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(i!=j) arr[i][j] = INF; //ģ�� ���踦 �Է� �ޱ��� �迭 ��� ���� inf�� �ʱ�ȭ  
		}
	}
	for(i=0; i<m; i++){
		cin>>a>>b; //ģ������ �Է�  
		arr[a-1][b-1] = 1; //����ġ�� 1�� ����
		arr[b-1][a-1] = 1;
	}
	floydWarshall(n); //�÷��̵� �ͼ�  
	return 0;
}
