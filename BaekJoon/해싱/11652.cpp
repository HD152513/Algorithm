#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(const pair<long long, int> &v1, const pair<long long, int> &v2){
	if(v1.second == v2.second){
		return v1.first < v2.first;
	}
	return v1.second > v2.second;
}
int main(){
    int n; // �ر԰� ������ �ִ� ���� ī���� ���� : n
    long long number;
    cin>>n;// n �Է�  
    map<long long, int> m; // key: ���� ī�忡 �����ִ� ����, value: ������ ���� 
	vector<pair<long long, int> > v; // map �� �����ϱ����� vector ����  
	for(int i=0; i<n; i++){
		 cin>>number; //���� ī�忡 �����ִ� ���� �Է�  
		 m[number]++; //�ش� ������ key�� ���� value ++ 
	}
	copy(m.begin(), m.end(), back_inserter(v)); //�Է¹��� map�� vector�� ����  
	sort(v.begin(), v.end(), cmp); //���� 
	cout<<v[0].first; //���ĵ� vector���� ù��° ���� ��� 
}
