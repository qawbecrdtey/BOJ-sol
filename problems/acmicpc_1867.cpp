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
	private:
		int capacity;
		edge *reverse;
		edge(vertex const *from, vertex const *to, int capacity) : from(from), to(to), capacity(capacity), reverse(nullptr) {}
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
		[[nodiscard]] int size() const { return capacity; }
	};
	class vertex {
	public:
		vector<edge*> edges;
		void add_edge(vertex *to, int capacity) {
			auto [forward, reverse] = edge::make_edge(this, to, capacity);
			edges.push_back(forward);
			to->edges.push_back(reverse);
		}
	};
	int vertex_cnt;
	vertex *vertices;
public:
	flow(int vertex_cnt) : vertex_cnt(vertex_cnt), vertices(new vertex[vertex_cnt]()) {}
	void add_edge(int from, int to, int capacity) {
		vertices[from].add_edge(&vertices[to], capacity);
	}
	int find_flow() {
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
				} return in_flow;
			}
			for(auto e : vertices[now].edges) {
				auto const next = (int)(e->to - vertices);
				if(!next || visited[next] || e->full()) continue;
				q.push({ next, e, min(in_flow, e->size()) });
			}
		} return 0;
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, k; cin >> n >> k;
	flow F(2 * n + 2);
	for(int i = 2; i <= n + 1; i++) {
		F.add_edge(0, i, 1);
	}
	for(int i = n + 2; i <= 2 * n + 1; i++) {
		F.add_edge(i, 1, 1);
	}
	for(int i = 0; i < k; i++) {
		int x, y; cin >> x >> y;
		F.add_edge(x + 1, n + y + 1, 1);
	}
	int total_flow = 0, f;
	while((f = F.find_flow())) total_flow += f;
	cout << total_flow;
}