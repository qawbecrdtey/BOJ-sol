#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;
constexpr int M = numeric_limits<int>::max() >> 1;
class graph {
	class vertex;
	class edge {
	public:
		vertex const *from, *to;
		int capacity, weight;
		edge *reverse;
		edge(vertex const *from, vertex const *to, int capacity, int weight) : from(from), to(to), capacity(capacity), weight(weight), reverse(nullptr) {}
		static pair<edge*, edge*> make_edge(vertex const *from, vertex const *to, int capacity, int weight) {
			auto forward = new edge(from, to, capacity, weight);
			auto reverse = new edge(to, from, 0, -weight);
			forward->reverse = reverse;
			reverse->reverse = forward;
			return { forward, reverse };
		};
		void fill(int f) {
			capacity -= f;
			reverse->capacity += f;
		}
	};
	class vertex {
	public:
		vector<edge*> edges;
		void add_edge(vertex *to, int capacity, int weight) {
			auto [forward, reverse] = edge::make_edge(this, to, capacity, weight);
			edges.push_back(forward);
			to->edges.push_back(reverse);
		}
	};
	int n; vertex *const vertices;
public:
	graph(int n) : n(n), vertices(new vertex[n]) {}
	void add_edge(int from, int to, int capacity, int weight) {
		vertices[from].add_edge(vertices + to, capacity, weight);
	}
	pair<int, int> find_edge() {
		struct info { int cost, in_flow; edge *in_edge; };
		vector<info> dist(n);
		dist[0] = { 0, M, nullptr };
		fill(dist.data() + 1, dist.data() + n, info{ M, M, nullptr });
		bool flag;
		for(int i = 1; i < n; i++) {
			flag = true;
			for(int now = 0; now < n; now++) {
				if(dist[now].cost == M) continue;
				for(auto e : vertices[now].edges) {
					auto const next = e->to - vertices;
					if(e->capacity && dist[next].cost > dist[now].cost + e->weight) {
						dist[next] = { dist[now].cost + e->weight, min(dist[now].in_flow, e->capacity), e };
						flag = false;
					}
				}
			}
			if(flag) break;
		}
		if(dist[1].cost == M) return { 0, 0 };
		auto now = dist[1].in_edge;
		int const flow = dist[1].in_flow;
		int weight = 0;
		while(now) {
			now->fill(flow);
			weight += now->weight * flow;
			now = dist[now->from - vertices].in_edge;
		} return { flow, weight };
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n; graph g((n + 1) << 1);
	for(int i = 1; i <= n; i++) {
		g.add_edge(0, i + 1, 1, 0);
		g.add_edge(i + n + 1, 1, 1, 0);
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			int x; cin >> x;
			g.add_edge(i + 1, j + n + 1, 1, x);
		}
	}
	pair<int, int> total, flow;
	while((flow = g.find_edge()).first) total.first += flow.first, total.second += flow.second;
	cout << total.second;
}