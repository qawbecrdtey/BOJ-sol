#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
#include <memory>
using namespace std;
constexpr int N = 52;
inline int index(char c) {
	if(c >= 'a') return c - 'a' + 26;
	return c - 'A';
}
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
			auto reverse = new edge(v, u, capacity);
			forward->reverse = reverse;
			reverse->reverse = forward;
			return { forward, reverse };
		}
		void fill(int f) {
			capacity -= f;
			reverse->capacity += f;
		}
		[[nodiscard]] vertex *next() const { return v; }
		[[nodiscard]] bool full() const { return !capacity; }
		[[nodiscard]] int size() const { return capacity; }
	};
	class vertex {
	public:
		vector<edge*> edges;
		void add_edge(vertex *v, int capacity) {
			auto const p = edge::make_edge(this, v, capacity);
			edges.push_back(p.first);
			v->edges.push_back(p.second);
		}
	};
	int n;
	vertex *vertices;
public:
	graph() : n(N), vertices(new vertex[N]) {}
	void add_edge(char u, char v, int capacity) {
		vertices[index(u)].add_edge(vertices + index(v), capacity);
	}
	int find_path() {
		int const start = index('A'), end = index('Z');
		queue<pair<int, pair<int, vector<edge*>>>> q;
		q.push({ start, { 1001, vector<edge*>() } });
		auto visited = make_unique<bool[]>(n);
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
				auto const next = e->next() - vertices;
				if(visited[next] || e->full()) continue;
				auto v = now.second.second;
				v.push_back(e);
				q.push({ next, { min(now.second.first, e->size()), v } });
			}
		}
		return 0;
	}
};
int main() {
	int n;
	scanf("%d", &n);
	graph g;
	for(int i = 0; i < n; i++) {
		char a[2], b[2]; int c;
		scanf("%s%s%d", a, b, &c);
		g.add_edge(*a, *b, c);
	}
	int res = 0, flow;
	while(flow = g.find_path()) res += flow;
	printf("%d", res);
}