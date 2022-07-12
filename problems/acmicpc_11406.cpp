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
		int capacity;
	private:
		edge *reverse;
		edge(vertex const *from, vertex const *to, int capacity) : from(from), to(to), capacity(capacity), reverse(nullptr) {}
	public:
		static pair<edge*, edge*> make_edge(vertex const *from, vertex const *to, int capacity) {
			auto const forward = new edge(from, to, capacity);
			auto const reverse = new edge(to, from, 0);
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
	int vertex_cnt;
	vertex *vertices;
public:
	explicit flow(int vertex_cnt) : vertex_cnt(vertex_cnt), vertices(new vertex[vertex_cnt]) {}
	void add_edge(int from, int to, int capacity) {
		vertices[from].add_edge(vertices + to, capacity);
	}
	int find_path() {
		struct info { int now; edge *in_edge; int in_flow; };
		vector<edge*> visited(vertex_cnt);
		queue<info> q;
		q.push({ 0, nullptr, 1987654321 });
		while(!q.empty()) {
			auto [now, in_edge, in_flow] = q.front(); q.pop();
			if(visited[now]) continue;
			visited[now] = in_edge;
			if(now == 1) {
				while(in_edge) {
					in_edge->fill(in_flow);
					in_edge = visited[in_edge->from - vertices];
				}
				return in_flow;
			}
			for(auto e : vertices[now].edges) {
				auto const next = (int)(e->to - vertices);
				if(!next || visited[next] || e->full()) continue;
				q.push({ next, e, min(in_flow, e->capacity) });
			}
		} return 0;
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	flow F(n + m + 2);
	for(int i = 1; i <= n; i++) {
		int x; cin >> x;
		F.add_edge(0, i + 1, x);
	}
	for(int i = 1; i <= m; i++) {
		int x; cin >> x;
		F.add_edge(i + n + 1, 1, x);
	}
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			int x; cin >> x;
			if(x) F.add_edge(j + 1, i + n + 1, x);
		}
	}
	int total_flow = 0, f;
	while((f = F.find_path())) total_flow += f;
	cout << total_flow;
}