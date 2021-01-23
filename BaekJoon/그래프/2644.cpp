#include <iostream>
#include <queue>
#include <vector>
using namespace std;
 
int p1, p2;
int depth[101] ={0,}; //���� 
vector<int> node[101]; // node �� ���� 1���� �� �� �ֵ��� 8�� ���� 
 
void BFS(int start){
    queue<int> q; //queue ����
    q.push(start); //queue�� �������� �ִ´�. 
    while(!q.empty()){ //q�� empty�� �ƴҶ����� �ݺ� 
        int current = q.front(); //q�� �� �պκ��� current�� ���� 
        q.pop(); //pop 
        for(int i=0; i<node[current].size(); i++){ //current �� ������ node�� �湮�Ѵ�.  
            int next = node[current][i]; //current �� ������ node�� next 
            if(!depth[next]){ //�湮���� ���� ����� 
                q.push(next); //q�� next�� �־��ش�. 
                depth[next] = depth[current]+1; //���� ���� 
            }
        }
    }
}
 
int main(){
    int n, m; //��ü ����� �� 
    scanf("%d%d%d%d", &n, &p1, &p2, &m); //��ü ����� �� n, �̼� ��� �ؾ��ϴ� ��� p1, �� �� ����ؾ��ϴ� �ٸ� ��� p2 
    for(int i=0; i<m; i++){
        int x, y; // ������ �����ϴ� �� ���� x,y(�θ��ڽİ��� ���踦 ��Ÿ��);
        cin>>x>>y; 
        //�� ������ ������ ������ ���� 
        node[x].push_back(y);
        node[y].push_back(x);
    }
    BFS(p1);
    if(depth[p2]==0){
        printf("-1"); //���̰� 0�̸� p2�� �湮���� ���ߴٴ� ���̹Ƿ� -1��� 
    }else{
        printf("%d", depth[p2]); //����(�̼�)�� ����Ѵ�. 
    }
    return 0; 
} 
