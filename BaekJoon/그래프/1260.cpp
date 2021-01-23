#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
 
int visited[1001]; //�湮 üũ
vector<int> node[1001]; // node �� ���� 1���� �� �� �ֵ��� 1001�� ���� 
 
void DFS(int x){
    if(visited[x]){ //x��带 �湮�ߴٸ�,  ����  
        return; 
    }
    visited[x] = true; //ó�� �湮�� ����� �湮ó�� 
    printf("%d ", x);
    for(int i=0; i<node[x].size(); i++){ //x �� ������ node�� �湮�Ѵ�.  
        int y = node[x][i]; //���� ��忡 ���� dfs�� �����Ѵ�.  
        DFS(y);
    }
}
 
void BFS(int start){
    queue<int> q; //queue ����
    q.push(start); //queue�� �������� �ִ´�. 
    visited[start] = true;//�湮�ϸ� true 
    while(!q.empty()){ //q�� empty�� �ƴҶ����� �ݺ� 
        int current = q.front(); //q�� �� �պκ��� current�� ���� 
        q.pop(); //pop 
        printf("%d ", current); //current�� ��� 
        for(int i=0; i<node[current].size(); i++){ //current �� ������ node�� �湮�Ѵ�.  
            int next = node[current][i]; //current �� ������ node�� next 
            if(!visited[next]){ //�湮���� ���� ����� 
                q.push(next); //q�� next�� �־��ش�. 
                visited[next] = true; //�湮ó��  
            }
        }
    }
}
 
int main(){
    int n, m, v;
    scanf("%d%d%d", &n, &m, &v); //���� ����n, ���� ���� m, Ž�� ������ ���� ��ȣ v 
    for(int i=0; i<m; i++){
        int a, b; // ������ �����ϴ� �� ���� a,b;
        cin>>a>>b; 
        //�� ������ ������ ������ ���� 
        node[a].push_back(b);
        node[b].push_back(a);
    }
    for(int i=0; i<=n; i++){ 
        //���� ��ȣ�� ���� ���� ���� �湮�ؾ��ϱ� ������ �����Ѵ�.  
        sort(node[i].begin(), node[i].end()); 
    }
    DFS(v);
    printf("\n"); 
    //dfs �� ������ �� �湮 üũ�� �����Ƿ�, �ʱ�ȭ�ؾ� �Ѵ�.
    fill_n(visited, 1001, 0);
    BFS(v);
    return 0; 
} 

