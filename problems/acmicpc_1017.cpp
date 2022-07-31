#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
inline vector<int> get_primes() {
	vector<int> primes{2, 3};
	vector<bool> visited(2000);
	int i = 5, d = 4;
	for(; i * i <= 2000; i += (d = 6 - d)) {
		if(!visited[i]) {
			primes.push_back(i);
			for(int j = i; j <= 2000; j += (i << 1)) {
				visited[j] = true;
			}
		}
	}
	for(; i <= 2000; i += (d = 6 - d)) {
		if(!visited[i]) primes.push_back(i);
	}
	return primes;
}
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
		~vertex() { for(auto e : edges) delete e; }
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
	flow(flow const &f) : vertex_cnt(f.vertex_cnt), vertices(new vertex[vertex_cnt]) {
		for(int i = 0; i < vertex_cnt; i++) {
			for(auto e : f.vertices[i].edges) {
				if(e->from - f.vertices < e->to - f.vertices) {
					add_edge(i, (int)(e->to - f.vertices));
				}
				else if(e->to - f.vertices == 1) {
					add_edge(i, 1);
				}
			}
		}
	}
	~flow() { delete[] vertices; }
	void add_edge(int from, int to) {
		vertices[from].add_edge(vertices + to);
	}
	int find_flow(int adj) {
		struct info { int now; edge *in_edge; int in_flow; };
		queue<info> q;
		q.push({ 0, nullptr, 1 });
		vector<edge*> visited(vertex_cnt);
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
				if(!next || visited[next] || next == adj || next == 2 || e->full()) continue;
				q.push({ next, e, min(in_flow, e->size()) });
			}
		}
		return 0;
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	auto primes = get_primes();
	int n; cin >> n;
	auto a = new int[n];
	flow F(2 * n + 2);
	vector<int> adjacent_nodes;
	for(int i = 0; i < n; i++) {
		F.add_edge(0, 2 + i);
		F.add_edge(2 + n + i, 1);
		cin >> a[i];
	}
	for(int i = 0; i < n; i++) {
		if((a[i] & 1) == (a[0] & 1)) {
			for(int j = 0; j < n; j++) {
				if(i == j) continue;
				if(binary_search(primes.begin(), primes.end(), a[i] + a[j])) {
					F.add_edge(2 + i, 2 + n + j);
					if(!i) adjacent_nodes.push_back(2 + n + j);
				}
			}
		}
	}
	vector<int> res;
	for(int adj : adjacent_nodes) {
		flow FF(F);
		int total_flow = 0, f;
		while ((f = FF.find_flow(adj))) total_flow += f;
		if(total_flow == n / 2 - 1) res.push_back(a[adj - n - 2]);
	}
	if(res.empty()) {
		cout << -1;
		return 0;
	}
	sort(res.begin(), res.end());
	for(int now : res) {
		cout << now << ' ';
	}
}