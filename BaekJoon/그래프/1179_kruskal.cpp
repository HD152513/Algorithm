#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[10001];

struct edge{ //u, v, c�� ������ edge 
	int u,v,w;
	edge(int u, int v, int w){
		this->u = u; //���� 
		this->v = v; //���� 
		this->w = w; //����ġ 
	}
};

int find(int u){ //��Ʈ�� ã�´�.  
	if(u == parent[u]){ //�ڽ��� �θ� ���� �ڽ��̸�  
		return u; //�ڽ��� ��Ʈ�̹Ƿ� ����  
	}
	return parent[u] = find(parent[u]); //��Ʈ�� ��� ã�´�.  
}

void merge(int u, int v){ //������ ��ģ��.  
	u = find(u); //���� u�� ���� ��Ʈ�� ã�´�.  
	v = find(v); //���� v�� ���� ��Ʈ�� ã�´�.  
	parent[v] = u; //��ģ��.  
}
int compare_comp(const edge &a, const edge &b){ //sort �ʰ�  
	return a.w < b.w; //����ġ�� �������� �Ѵ�.  
}

int kruskal(vector<edge> &edges){ //ũ�罺Į �Լ�  
	int cost = 0; //��� �ʱ�ȭ 
	sort(edges.begin(), edges.end(), compare_comp); //����ġ�� �������� �������� ����  
	for(int i=0; i<edges.size(); i++){ 
		if(find(edges[i].u)==find(edges[i].v)){ //����Ŭ ���θ� Ȯ���Ѵ�.  
			continue;
		}
		merge(edges[i].u, edges[i].v); //�� ������ �ϳ��� ��ģ��.  
		cost += edges[i].w;
	}
	return cost;
}
int main(){
	int v,e; //������ ���� v, ������ ���� e 
	cin>>v>>e; //�Է�
	vector<edge> edges; 
	for(int i=1; i<=v; i++){
		parent[i] = i;
	}
	for(int i=0; i<e; i++){ //edge�� �Է¹޴´�.  
		int a,b,c;
		cin>>a>>b>>c;
		edges.push_back(edge(a,b,c)); //edge�� �ִ´�.  
		edges.push_back(edge(b,a,c));
	}
	cout<<kruskal(edges);//����� ����Ѵ�.  
	return 0;
}

