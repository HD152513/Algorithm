#include<iostream>
using namespace std;

void quickSort(int arr[], int start, int end){
	
	if(start >= end){ //���Ұ� 1���� ��� ���� 
		return;
	}
	int pivot = start; //pivot�� start��ġ�� ���ҷ� �д�. 
	int left = start+1;
	int right = end;
	int temp;
	while(left<=right){ //left�� right�� ������ ������ �ݺ��Ѵ�. 
		while(left<=end && arr[left] <= arr[pivot]){ //pivot���� ū ���� ���������� left++ 
			left++;
		}
		while(right>start && arr[right] >= arr[pivot]){ //pivot���� ���� ���� ���������� right-- 
			right--;
		}
		if(left>right){ //left�� right�� ������ ���¸� pivot���� right���� swap 
			temp = arr[right];
			arr[right] = arr[pivot];
			arr[pivot] = temp;
		}else{ //�������� �ʾҴٸ� left�� right ���� swap 
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
		}
		quickSort(arr, start, right-1); //�պκ� ����
		quickSort(arr, right+1, end); //�޺κ� ����  
	}
}
int main(){
	int arr[10] = {8, 1, 2, 4, 9, 3, 6, 5, 10, 7}; //������ �迭 
	quickSort(arr, 0, 9); //quickSort�Լ� ȣ��(0 ~ n-1 ����) 
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++) {
        printf("%d ", arr[i]); //���ĵ� �迭�� ��� 
    }
    return 0;
}
