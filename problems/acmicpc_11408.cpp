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
		vertex const *from;
		vertex const *to;
		int capacity;
		int weight;
		edge *reverse;
		edge(vertex const *from, vertex const *to, int capacity, int weight) : from(from), to(to), capacity(capacity), weight(weight), reverse(nullptr) {}
		static pair<edge*, edge*> make_edge(vertex const *from, vertex const *to, int capacity, int weight) {
			auto forward = new edge(from, to, capacity, weight);
			auto reverse = new edge(to, from, 0, -weight);
			forward->reverse = reverse;
			reverse->reverse = forward;
			return { forward, reverse };
		}
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
	int n;
	vertex *vertices;
public:
	graph(int n) : n(n), vertices(new vertex[n]) {}
	void add_edge(int from, int to, int capacity, int weight) {
		vertices[from].add_edge(vertices + to, capacity, weight);
	}
	pair<int, int> find_path() { // flow, weight
		vector<pair<int, edge*>> dist(n);
		fill(dist.data() + 1, dist.data() + n, make_pair(M, nullptr));
		dist[0].second = nullptr;
		bool flag;
		for(int i = 0; i < n; i++) {
			flag = true;
			for(int now = 0; now < n; now++) {
				if(dist[now].first == M) continue;
				for(auto e : vertices[now].edges) {
					auto const next = e->to - vertices;
					if(e->capacity && dist[next].first > dist[now].first + e->weight) {
						flag = false;
						dist[next].first = dist[now].first + e->weight;
						dist[next].second = e;
					}
				}
			}
			if(flag) break;
		}
		if(dist[1].second == nullptr) return { 0, 0 };
		int flow = 1, weight = 0;
		edge *now = dist[1].second;
		while(now) {
			now->fill(flow);
			weight += flow * now->weight;
			now = dist[now->from - vertices].second;
		}
		return { flow, weight };
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	graph g(n + m + 2);
	for(int i = 1; i <= n; i++) {
		g.add_edge(0, i + 1, 1, 0);
	}
	for(int i = 1; i <= m; i++) {
		g.add_edge(i + n + 1, 1, 1, 0);
	}
	for(int i = 1; i <= n; i++) {
		int k; cin >> k; while(k--) {
			int x, y; cin >> x >> y;
			g.add_edge(i + 1, x + n + 1, 1, y);
		}
	}
	pair<int, int> total, now;
	while((now = g.find_path()).first) total.first += now.first, total.second += now.second;
	cout << total.first << '\n' << total.second;
}