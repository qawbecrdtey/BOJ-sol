#include <algorithm>
#include <memory>
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
class graph {
	class vertex;
	class edge {
		vertex *u;
		vertex *v;
		int capacity;
		edge *reverse;

		edge(vertex *u, vertex *v, int capacity) : u(u), v(v), capacity(capacity), reverse(nullptr) {}
	public:
		static pair<edge*, edge*> make_edge(vertex *u, vertex *v, int capacity) {
			auto forward = new edge(u, v, capacity);
			auto reverse = new edge(v, u, 0);
			forward->reverse = reverse;
			reverse->reverse = forward;
			return { forward, reverse };
		}
		void fill(int c) {
			capacity -= c;
			reverse->capacity += c;
		}
		[[nodiscard]] bool full() const { return !capacity; }
		[[nodiscard]] vertex *next() const { return v; }
		[[nodiscard]] int size() const { return capacity; }
	};
	class vertex {
		vector<edge*> edges;
	public:
		friend class graph;
		void add_edge(vertex *v, int capacity) {
			auto const p = edge::make_edge(this, v, capacity);
			edges.push_back(p.first);
			v->edges.push_back(p.second);
		}
	};
	int find_path(int start, int end) {
		queue<pair<int, pair<int, vector<edge*>>>> q;
		q.push(make_pair(start, make_pair(1, vector<edge*>())));
		auto visited = make_unique<bool[]>(n + 1);
		while(!q.empty()) {
			auto now = q.front(); q.pop();
			if(visited[now.first]) continue;
			visited[now.first] = true;
			if(now.first == end) {
				auto const flow = now.second.first;
				for(auto e : now.second.second) {
					e->fill(flow);
				}
				return flow;
			}
			for(auto e : vertices[now.first].edges) {
				auto next = e->next();
				if(visited[next - vertices] || e->full()) continue;
				auto v = now.second.second;
				v.push_back(e);
				q.push(make_pair(next - vertices, make_pair(min(now.second.first, e->size()), v)));
			}
		}
		return 0;
	}
	int n;
	vertex *vertices;

public:
	explicit graph(int n) : n(n), vertices(new vertex[n + 1]) {}

	void add_edge(int u, int v, int capacity) {
		vertices[u].add_edge(vertices + v, capacity);
	}

	int find_path() { return find_path(1, 2); }
};
int main() {
	int n, p;
	scanf("%d%d", &n, &p);
	graph g(n);
	for(int i = 0; i < p; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		g.add_edge(x, y, 1);
	}
	int res = 0;
	int flow;
	while((flow = g.find_path())) res += flow;
	printf("%d", res);
}