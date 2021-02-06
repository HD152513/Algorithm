#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int INF = 10000000;
int n;
vector<pair<int, int> > edge[100001]; // ���� ����
int cost[100001]; //�ּ� ���

void dijkstra(int start){
	int sum = 0, lastCom = 0;
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
	for(int i=1; i<=n; i++){
		if(cost[i] != INF){ //cost�� INF�� �ƴ϶��  
			sum++; //�����Ǵ� ��ǻ�ͼ� +1 
			if(lastCom < cost[i]){ // ������ ��ǻ�Ͱ� �����Ǳ���� �ɸ��� �ð�
				lastCom = cost[i];
			}  
		}
	} 
	cout<<sum<<" "<<lastCom<<endl; //���  
}

int main(void){
	int t;
	cin>>t; //�׽�Ʈ���̽� ���� �Է�  
	for(int k=0; k<t; k++){
		int d,c; 
		cin>>n>>d>>c; // ��ǻ�� ���� n, ������ ����d, ��ŷ���� ��ǻ�� ��ȣ c 
		for(int i=1; i<=n; i++){ //�ʱ����� ��� ���Ѵ�� �ʱ�ȭ�Ѵ�.  
			cost[i] = INF;
			edge[i].clear(); //�ʱ�ȭ  
		}
		//���������� �Է¹޴´�.  
		for(int i=0; i<d; i++){
			int a,b,s;
			cin>>a>>b>>s;
			edge[b].push_back(make_pair(a,s));
		}
		dijkstra(c); //���ͽ�Ʈ�� �Լ� ȣ��  
	}
}
