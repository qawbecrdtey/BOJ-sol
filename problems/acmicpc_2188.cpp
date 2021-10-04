#include <iostream>
#include <memory>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
class graph {
	class edge;
	class vertex {
	public:
		vector<edge*> edges;
		void add_edge(vertex *v) {
			auto p = edge::make_edge(this, v);
			edges.push_back(p.first);
			v->edges.push_back(p.second);
		}
	};
	class edge {
		vertex *u, *v;
		int capacity;
		edge *reverse;
		edge(vertex *u, vertex *v, int capacity) : u(u), v(v), capacity(capacity), reverse(nullptr) {}
	public:
		static pair<edge*, edge*> make_edge(vertex *u, vertex *v) {
			auto const forward = new edge(u, v, 1);
			auto const backward = new edge(v, u, 0);
			forward->reverse = backward;
			backward->reverse = forward;
			return { forward, backward };
		}
		[[nodiscard]] vertex *next() const { return v; }
		[[nodiscard]] bool empty() const { return capacity == 0; }
		void fill(int f) {
			capacity -= f;
			reverse->capacity += f;
		}
	};
	int from, to;
	vertex *vertices;
	static void add_edge(vertex *u, vertex *v) { u->add_edge(v); }

	[[nodiscard]] vertex* start(int x) const { return vertices + x + 1; }
	[[nodiscard]] vertex* end(int x) const { return vertices + x + from + 1; }
public:
	graph(int from, int to) : from(from), to(to), vertices(new vertex[from + to + 2]) {
		for(int i = 1; i <= from; i++) {
			add_edge(vertices, start(i));
		}
		for(int i = 1; i <= to; i++) {
			add_edge(end(i), vertices + 1);
		}
	}
	void add_edge(int u, int v) { add_edge(start(u), end(v)); }
	int flow() {
		auto visited = make_unique<bool[]>(from + to + 2);
		queue<pair<int, pair<vector<edge*>, int>>> q;
		q.push({ 0, { {}, 1 } });
		while(!q.empty()) {
			auto const now = q.front(); q.pop();
			if(visited[now.first]) continue;
			visited[now.first] = true;
			if(now.first == 1) {
				for(auto e : now.second.first) {
					e->fill(1);
				}
				return 1;
			}
			for(auto e : vertices[now.first].edges) {
				auto const next = e->next() - vertices;
				if(e->empty() || visited[next]) continue;
				auto v = now.second.first;
				v.push_back(e);
				q.push({ next, { v, 1 } });
			}
		}
		return 0;
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	graph g(n, m);
	for(int i = 1; i <= n; i++) {
		int t, x;
		cin >> t;
		for(int j = 0; j < t; j++) {
			cin >> x;
			g.add_edge(i, x);
		}
	}
	int flow, res = 0;
	while((flow = g.flow())) res += flow;
	cout << res;
}