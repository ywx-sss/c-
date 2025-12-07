#include<bits/stdc++.h> 
using namespace std;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
struct point {
    int x, y, t;
    point(int dx, int dy, int dt): x(dx), y(dy), t(dt) {}
};
bool visited[2001][2001];
bool isE[2001][2001]; 
bool e_visited[2001][2001]; 
bool judge(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}
int bfs(vector<string>& mapp, int n, int m, int sx, int sy) {
    memset(visited, false, sizeof(visited));
    memset(e_visited, false, sizeof(e_visited));
    queue<point> q;
    q.push(point(sx, sy, 0));
    visited[sx][sy] = true;
    
    while(!q.empty()) {
        point now = q.front();
        q.pop();
        
        if(mapp[now.x][now.y] == 'C') {
            return now.t;
        }
        for(int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];
            if(judge(nx, ny, n, m) && mapp[nx][ny] != 'M' && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push(point(nx, ny, now.t + 1));
            }
        }
        if(mapp[now.x][now.y] == 'E' && !e_visited[now.x][now.y]) {
            e_visited[now.x][now.y] = true;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(mapp[i][j] == 'E' && !visited[i][j] && !e_visited[i][j]) {
                        visited[i][j] = true;
                        q.push(point(i, j, now.t));
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);  
    int n,m;
    cin>>n>>m;
    vector<string> mapp(n);
    int sx, sy;   
    memset(isE, false, sizeof(isE)); 
    for(int i=0; i<n; i++) {
        cin>>mapp[i];
        for(int j=0; j<m; j++) {
            if(mapp[i][j]=='N') {
                sx=i;
                sy=j;
            }
            if(mapp[i][j]=='E') {
                isE[i][j]=true;
            }
        }
    }
    
    int result=bfs(mapp,n,m,sx,sy);
    if(result!=-1) cout<<result<<endl;
    else cout<<"Bad Eureka"<<endl;
    return 0;
}