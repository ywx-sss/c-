#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
struct point {
    int x, y, t;
    point(int dx, int dy, int dt) : x(dx), y(dy), t(dt) {}
};
bool visited[1001][1001];
bool judge(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}
int bfs(vector<string>& mapp, int n, int m, int k, int sx, int sy, int ex, int ey) {
    memset(visited, false, sizeof(visited));
    queue<point> q;
    q.push(point(sx, sy, 0));
    visited[sx][sy] = true;
    while (!q.empty()) {
        point now = q.front();
        q.pop();
        if (now.x == ex && now.y == ey) {
            return now.t;
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 1; j <= k; j++) {
                int nx = now.x + dx[i] * j;
                int ny = now.y + dy[i] * j;
                if (!judge(nx, ny, n, m) || mapp[nx][ny] == '#') {
                    break;
                }
                if (visited[nx][ny]) {
                    break;
                }
                q.push(point(nx, ny, now.t + 1));
                visited[nx][ny] = true;
                if (mapp[nx][ny] == '#') {
                    break;
                }
            }
        }
    }
    return -1;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> mapp(n);
    int sx, sy, ex, ey;
    for (int i = 0; i < n; i++) {
        cin >> mapp[i];
    }
    cin >> sx >> sy >> ex >> ey;
    sx--;sy--;ex--;ey--;
    int result = bfs(mapp, n, m, k, sx, sy, ex, ey);
    cout << result << endl;

    return 0;
}