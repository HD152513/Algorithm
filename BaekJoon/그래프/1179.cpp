#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define P pair<int, int>

int visited[10001]; //�湮 ���� 
vector<P> edge[10001]; //���� ����  

int prim(){
	int cost= 0; //��� 
	priority_queue<P, vector<P>, greater<P> > pq; //�켱���� ť - 
	pq.push(P(0,1)); //1������ ���� 
	
	while(!pq.empty()){ //ť�� �������� ��� �ݺ� 
		P current = pq.top(); //cur�� ť�� ž ���� 
		pq.pop(); //pop 
		if(visited[current.second]){ //�̹� �湮���� ��� while������ ���ư� 
			continue;
		}else{ //�湮���� �ʟ��� ��� �湮 ó��  
			visited[current.second] = 1;
		}  
		cost += current.first; //��ü ����� ����  
		for(int i=0; i<edge[current.second].size(); i++){
			if(!visited[edge[current.second][i].second]){
				pq.push(edge[current.second][i]); //ť�� ����ִ´�.  
			}
		}
	}
	return cost; //cost�� ���� �Ѵ�.  
}

int main(){
	int v,e; //������ ���� v, ������ ���� e 
	cin>>v>>e; //�Է� 
	for(int i=0; i<e; i++){
		int a,b,c; //a�� ������ b�� ������ ����ġ c�� �������� ���� 
		cin>>a>>b>>c;
		edge[a].push_back(P(c,b)); //a, b������ �մ� ���� ��� ��� c 
		edge[b].push_back(P(c,a)); //b, a������ �մ� ���� ��� ��� c 
	}
	cout<<prim();//����� ����Ѵ�.  
	return 0;
}

