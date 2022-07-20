#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
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
		static pair<edge*, edge*> make_edge(vertex const *from, vertex const *to) {
			auto forward = new edge(from, to, 1);
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
		void add_edge(vertex *to) {
			auto [forward, reverse] = edge::make_edge(this, to);
			edges.push_back(forward);
			to->edges.push_back(reverse);
		}
	};
	int source, sink;
	int vertex_cnt;
	vertex *vertices;

public:
	flow(int vertex_cnt, int source, int sink, vector<pair<int, int>> const &edges)
	  :	source((source << 1) | 1), sink(sink << 1), vertex_cnt(vertex_cnt << 1), vertices(new vertex[vertex_cnt << 1]()) {
		// -> 2k -> 2k+1 ->
		for(int i = 0; i < vertex_cnt; i++) {
			vertices[i << 1].add_edge(&vertices[(i << 1) | 1]);
		}
		for(auto [f, t] : edges) {
			if(f != sink && t != source) vertices[(f << 1) | 1].add_edge(&vertices[t << 1]);
			if(f != source && t != sink) vertices[(t << 1) | 1].add_edge(&vertices[f << 1]);
		}
	}
	int find_path() {
		struct info { int now; edge *in_edge; int in_flow; };
		vector<edge*> visited(vertex_cnt);
		queue<info> q;
		q.push({ source, nullptr, 2 });
		while(!q.empty()) {
			auto [now, in_edge, in_flow] = q.front(); q.pop();
			if(visited[now]) continue;
			visited[now] = in_edge;
			if(now == sink) {
				while(in_edge) {
					in_edge->fill(in_flow);
					in_edge = visited[in_edge->from - vertices];
				} return in_flow;
			}
			for(auto e : vertices[now].edges) {
				auto const next = (int)(e->to - vertices);
				if(next == source || visited[next] || e->full()) continue;
				q.push({ next, e, min(in_flow, e->size()) });
			}
		} return 0;
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	auto a = new string[n];
	int source, sink;
	vector<pair<int, int>> edges;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		for(int j = 0; j < m; j++) {
			if(a[i][j] == '#') continue;
			if(a[i][j] == 'K') source = i * m + j;
			else if(a[i][j] == 'H') sink = i * m + j;
			if(i && a[i - 1][j] != '#') edges.emplace_back(((i - 1) * m + j), (i * m + j));
			if(j && a[i][j - 1] != '#') edges.emplace_back((i * m + j - 1), (i * m + j));
		}
	}
	if(abs(source / m - sink / m) + abs(source % m - sink % m) == 1) {
		cout << -1;
		return 0;
	}
	flow F(n * m, source, sink, edges);
	int total_flow = 0, f;
	while((f = F.find_path())) total_flow += f;
	cout << total_flow;
}