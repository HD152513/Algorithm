#include <iostream>
using namespace std;
int main(){
	int n, k, i, cnt = 0; //n: �ؼ��̰� �������ִ� ���� �� k: ������� ��ġ�� ��, cnt: ���������� �ּҰ�  
	cin>>n>>k;
	int *value = new int[n]; //������ ��ġ�� ������ �迭�� �����Ҵ�  
	for(i = 0; i<n; i++){
		cin>>value[i];
	}
	for(i = n-1; i>=0; i--){
		if(k>=value[i]){ //���� ��ǥ ��ġ �պ��� ������ ��ġ(value[i])�� ũ�ٸ�  
			k-=value[i]; //��ǥ ��ġ �տ��� ������ ��ġ�� ����,  
			cnt++; //���� ������ 1 �ø���.  
			i++; //��ǥ ��ġ �պ��� ������ ��ġ(value[i])�� ū�� �ٽ� Ȯ���ϱ� ���� for���� ����.  
		}
	}
	cout<<cnt;
} 
