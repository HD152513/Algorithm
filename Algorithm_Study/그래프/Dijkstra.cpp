#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int number = 6;
int INF = 10000000;

vector<pair<int, int> > edge[7]; // ���� ����
int cost[7]; //�ּ� ���

void dijkstra(int start){
	cost[start] = 0;
	priority_queue<pair<int, int> > pq; //�켱���� ť ����
	pq.push(make_pair(start, 0));
	while(!pq.empty()){ //���� ť�� ������� �ʴٸ� ��� �ݺ� 
		int current = pq.top().first; //current�� ���� ť�� top�� ����  
		int distance = -pq.top().second; //ª�� ���� ���� ������ ����ȭ  
		pq.pop(); //pop 
		if(cost[current] < distance){ //�ִ� ��찡 �ƴѰ�� continue
			continue;
		}
		for(int i = 0; i<edge[current].size(); i++){
			int next = edge[current][i].first; //���� ����� ������ ��� next 
			int nextDistatnce = distance + edge[current][i].second; //���� ��带 ���� ��� next�� ���� ���� ���  
			if(nextDistatnce < cost[next]){ //���� ���� ���� �۴ٸ�, �ּҺ�� ��ü  
				cost[next] = nextDistatnce;
				pq.push(make_pair(next, -nextDistatnce)); //ť�� push  
			}
		}
	} 
}

int main(void){
	for(int i=1; i<=number; i++){ //�ʱ����� ��� ���Ѵ�� �ʱ�ȭ�Ѵ�.  
		cost[i] = INF;
	}
	//���������� �Է¹޴´�.  
	edge[1].push_back(make_pair(2, 7));
	edge[1].push_back(make_pair(3, 9));
	edge[1].push_back(make_pair(6, 14));
	
	edge[2].push_back(make_pair(1, 7));
	edge[2].push_back(make_pair(3, 10));
	edge[2].push_back(make_pair(4, 15));
	
	edge[3].push_back(make_pair(1, 9));
	edge[3].push_back(make_pair(2, 10));
	edge[3].push_back(make_pair(4, 11));
	edge[3].push_back(make_pair(6, 2));
	
	edge[4].push_back(make_pair(2, 15));
	edge[4].push_back(make_pair(3, 11));
	edge[4].push_back(make_pair(5, 6));
	
	edge[5].push_back(make_pair(4, 6));
	edge[5].push_back(make_pair(6, 9));
	
	edge[6].push_back(make_pair(1, 14));
	edge[6].push_back(make_pair(3, 2));
	edge[6].push_back(make_pair(5, 9));
	
	dijkstra(1);
	for(int i=1; i<=number; i++){
		printf("%d ", cost[i]);
	}
}
