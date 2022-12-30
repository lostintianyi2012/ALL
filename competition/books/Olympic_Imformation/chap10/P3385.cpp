#include <bits/stdc++.h>

using namespace std;
const int N = 2e3 + 10, M = 3e3 + 10;
int h[N], ne[M<<1], e[M<<1], w[M<<1];
int q[N*M];
long long cnt[N];
int idx;
int dist[N];
bool st[N];
int n, m;

inline void add(int a, int b, int c){
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

bool spfa(){
 	 memset(cnt, 0, sizeof cnt);
	memset(st, 0, sizeof st);
	memset(dist, 0x3f, sizeof dist);
	int hh = 0, tt = -1;
	q[++tt] = 1;
	cnt[1] = 1;
	dist[1] = 0;
	st[1] = true;

	while(hh <= tt){
		int ver = q[hh++];
		st[ver] = false;

		for(int i = h[ver]; ~i; i = ne[i]){
			int j = e[i];

			if(dist[j] > dist[ver] + w[i]){
				dist[j] = dist[ver] + w[i];

				if(!st[j]){
					if(dist[i] < dist[j])
						q[--hh] = j;
					else
						q[++tt] = j;

					cnt[j]++;
					st[j] = true;
					if(cnt[j] >= n)
						return true;
				}
			}
		}
	}
	return false;
}


int main(){
	freopen("P3385.in", "r", stdin);
	int T;
	scanf("%d", &T);
	while(T--){
	    idx = 0;
		memset(h, -1, sizeof h);
		scanf("%d%d", &n, &m);
		int a, b, c;
		for(int i = 1; i <= m; i++){
			scanf("%d%d%d", &a, &b, &c);
			if(c >= 0)
				add(a, b, c), add(b, a, c);
			else
				add(a, b, c);
		}
		if(spfa())
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
