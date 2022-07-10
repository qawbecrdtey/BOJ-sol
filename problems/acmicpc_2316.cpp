#include <iostream>
#include <memory>
#include <queue>
#include <vector>
using namespace std;
class flow {
	class vertex;
	class edge {
	public:
		vertex const *from;
		vertex const *to;
	private:
		edge *reverse;
		int capacity;
		edge(vertex const *from, vertex const *to, int capacity) : from(from), to(to), reverse(nullptr), capacity(capacity) {}
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
		[[nodiscard]] int size() const { return capacity; }
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
	int vertex_size;
	vertex *vertices;
public:
	explicit flow(int vertex_size) : vertex_size(vertex_size), vertices(new vertex[vertex_size]) {}
	void add_edge(int from, int to) {
		vertices[from].add_edge(vertices + to, 1);
	}
	int search() {
		struct info { int now; edge *prev; int flow; };
		auto before = make_unique<edge*[]>(vertex_size);
		queue<info> q;
		q.push({ 0, nullptr, 1987654321 });
		while(!q.empty()) {
			auto [now, in_edge, in_flow] = q.front(); q.pop();
			if(before[now]) continue;
			before[now] = in_edge;
			if(now == 1) {
				while(in_edge) {
					in_edge->fill(in_flow);
					in_edge = before[in_edge->from - vertices];
				} return in_flow;
			}
			for(auto e : vertices[now].edges) {
				int const next = int(e->to - vertices);
				if(!next || before[next] || e->full()) continue;
				q.push({ next, e, min(in_flow, e->size()) });
			}
		} return 0;
	}
};
inline int from(int n) {
	if(n < 3) return n - 1;
	return ((n - 2) << 1) | 1;
}
inline int to(int n) {
	if(n < 3) return n - 1;
	return (n - 2) << 1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, p; cin >> n >> p;
	flow F(n * 2 - 2);
	for(int i = 1; i < n - 1; i++) F.add_edge(i << 1, (i << 1) | 1);
	for(int i = 0; i < p; i++) {
		int x, y; cin >> x >> y;
		int const fromx = from(x), tox = to(x);
		int const fromy = from(y), toy = to(y);
		F.add_edge(fromx, toy);
		F.add_edge(fromy, tox);
	}
	int res = 0, f;
	while((f = F.search())) res += f;
	cout << res;
}