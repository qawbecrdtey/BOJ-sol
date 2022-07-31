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
		~vertex() { for(auto e : edges) delete e; }
		vector<edge*> edges;
		void add_edge(vertex *to) {
			auto [forward, reverse] = edge::make_edge(this, to);
			edges.push_back(forward);
			to->edges.push_back(reverse);
		}
	};
	int vertex_cnt;
	vertex *vertices;
public:
	explicit flow(int vertex_cnt) : vertex_cnt(vertex_cnt), vertices(new vertex[vertex_cnt]) {}
	flow(flow const &f) : vertex_cnt(f.vertex_cnt), vertices(new vertex[f.vertex_cnt]){
		for(int i = 0; i < vertex_cnt; i++) {
			for(auto e : f.vertices[i].edges) {
				if(i < int(e->to - f.vertices)) {
					add_edge(i, int(e->to - f.vertices));
				}
			}
		}
	}
	~flow() { delete[] vertices; }
	void add_edge(int from, int to) {
		vertices[from].add_edge(vertices + to);
	}
	int find_flow() {
		struct info { int now; edge *in_edge; int in_flow; };
		queue<info> q;
		q.push({ 0, nullptr, 1 });
		vector<edge*> visited(vertex_cnt);
		while(!q.empty()) {
			auto [now, in_edge, in_flow] = q.front(); q.pop();
			if(visited[now]) continue;
			visited[now] = in_edge;
			if(now == vertex_cnt - 1) {
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
		}
		return 0;
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t; while(t--) {
		int n, m; cin >> n >> m;
		auto a = new string[n];
		flow F(n * m + 2);
		int tot = 0;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			for(char c : a[i]) {
				tot += (c == '.');
			}
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j += 2) {
				if(a[i][j] == 'x') continue;
				F.add_edge(0, 1 + i * m + j);
				if(j) {
					if(i && a[i - 1][j - 1] != 'x') {
						F.add_edge(1 + i * m + j, 1 + (i - 1) * m + (j - 1));
					}
					if(a[i][j - 1] != 'x') {
						F.add_edge(1 + i * m + j, 1 + i * m + (j - 1));
					}
					if(i < n - 1 && a[i + 1][j - 1] != 'x') {
						F.add_edge(1 + i * m + j, 1 + (i + 1) * m + (j - 1));
					}
				}
				if(j < m - 1) {
					if(i && a[i - 1][j + 1] != 'x') {
						F.add_edge(1 + i * m + j, 1 + (i - 1) * m + (j + 1));
					}
					if(a[i][j + 1] != 'x') {
						F.add_edge(1 + i * m + j, 1 + i * m + (j + 1));
					}
					if(i < n - 1 && a[i + 1][j + 1] != 'x') {
						F.add_edge(1 + i * m + j, 1 + (i + 1) * m + (j + 1));
					}
				}
			}
			for(int j = 1; j < m; j += 2) {
				if(a[i][j] == 'x') continue;
				F.add_edge(1 + i * m + j, n * m + 1);
			}
		}
		int total_flow = 0, f;
		while((f = F.find_flow())) total_flow += f;
		cout << tot - total_flow << '\n';
		delete[] a;
	}
}