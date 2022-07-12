#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class flow {
	class vertex;
	class edge {
	public:
		vertex const *from;
		vertex const *to;
		edge *reverse;
		int capacity;
	private:
		edge(vertex const *from, vertex const *to, int capacity) : from(from), to(to), reverse(nullptr), capacity(capacity) {}
	public:
		static pair<edge*, edge*> make_edge(vertex const *from, vertex const *to, int capacity) {
			auto forward = new edge(from, to, capacity);
			auto reverse = new edge(to, from, 0);
			forward->reverse = reverse;
			reverse->reverse = forward;
			return { forward, reverse };
		}
		void fill(int f) {
			capacity -= f;
			reverse->capacity += f;
		}
		[[nodiscard]] bool full() const { return !capacity; }
	};
	class vertex {
	public:
		vector<edge*> edges;
		void add_edge(vertex *to, int capacity) {
			auto const [forward, reverse] = edge::make_edge(this, to, capacity);
			edges.push_back(forward);
			to->edges.push_back(reverse);
		}
	};
	int dfs(vector<bool> &visited, int now, int in_flow) {
		visited[now] = true;
		if(now == 1) return in_flow;
		for(auto e : vertices[now].edges) {
			auto const next = (int)(e->to - vertices);
			if(visited[next] || e->full()) continue;
			auto const f = dfs(visited, next, min(in_flow, e->capacity));
			if(f) {
				e->fill(f);
				return f;
			}
		} return 0;
	}
	int vertex_cnt;
	vertex *vertices;
public:
	explicit flow(int vertex_cnt) : vertex_cnt(vertex_cnt), vertices(new vertex[vertex_cnt]) {}
	void add_edge(int from, int to, int capacity) {
		vertices[from].add_edge(vertices + to, capacity);
	}
	int find_flow() {
		vector<bool> visited(vertex_cnt);
		return dfs(visited, 0, 10000);
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m, k; cin >> n >> m >> k;
	flow F(n + m + 3);
	F.add_edge(0, 2, k);
	for(int i = 1; i <= n; i++) {
		F.add_edge(0, i + 2, 1);
		F.add_edge(2, i + 2, k);
		int j; cin >> j;
		while(j--) {
			int x; cin >> x;
			F.add_edge(i + 2, x + n + 2, 1);
		}
	}
	for(int i = 1; i <= m; i++) {
		F.add_edge(n + i + 2, 1, 1);
	}
	int total_flow = 0, f;
	while((f = F.find_flow())) total_flow += f;
	cout << total_flow;
}