#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	int n, m, cnt=0; //���ڿ��� ���� n�� m, ������ ���ϱ� ���� cnt 
	map<string, string> mp;//���ڿ��� ���� map ����  
	string str; 
	cin>>n>>m; //n, m �Է� 
	for(int i=0; i<n; i++){
		cin>>str;
		mp.insert({str, str}); //map�� string ����ֱ�  
	}
	for(int i=0; i<m; i++){
		cin>>str;
		if(mp.find(str) != mp.end()){ //map���� �ش� string�� �ִ��� ã�´�.  
			cnt++; //������ cnt++ 
		}
	}
	cout<<cnt; //���� ��� 
}
