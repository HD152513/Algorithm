#include <iostream>
using namespace std;
int main(){
	int n, i; // n: ������ ���� 
	long long cost=0, min=1000000001; // cost: �ּҺ��, min: ���ʹ簡���� �ּҰ� 
	cin>>n;	//������ ������ �Է¹޴´�.  
	int *road = new int[n-1]; //�� ���� ������ ���� ���̸� �����ϴ� �迭�� �����Ҵ�
	int *city = new int[n]; // �� ���� �ֿ���� ���ʹ� ������ �����ϴ� �迭�� �����Ҵ� 
	for(i=0; i<n-1; i++){
		cin>>road[i];
	}
	for(i=0; i<n; i++){
		cin>>city[i];

	}
	for(i=0; i<n-1; i++){
		if(city[i]<min){ //���� ������ ���ʹ� ������ ���� �ּҰ�(min)���� �۴ٸ� �ּҰ��� ��ü 
			min = city[i];
		}
		cost += min * road[i]; //�ּҺ���� ���ʹ� ������ �ּҰ��� �� ���� ���̸� ���� ���� ������. 
	}
	cout<<cost; //�ּҺ���� ���  
}
