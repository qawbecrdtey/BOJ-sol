#include <cassert>
#include <iostream>
#include <limits>
#include <memory>
#include <queue>
#include <utility>
#include <vector>

class graph {
	class vertex;
	class edge {
	public:
		vertex const *from;
		vertex const *to;

	private:
		edge *reverse;
		uint32_t capacity;

		edge(vertex const *from, vertex const *to, uint32_t capacity)
		  :	from(from), to(to), reverse(nullptr), capacity(capacity) {}

	public:
		static std::pair<std::unique_ptr<edge>, std::unique_ptr<edge>> make_edge(vertex const *from, vertex const *to, uint32_t capacity, bool bidirectional) {
			auto forward = std::unique_ptr<edge>(new edge(from, to, capacity));
			auto reverse = std::unique_ptr<edge>(new edge(to, from, capacity * bidirectional));
			forward->reverse = reverse.get();
			reverse->reverse = forward.get();
			return std::make_pair(std::move(forward), std::move(reverse));
		}

		void fill(uint32_t flow) {
			capacity -= flow;
			reverse->capacity += flow;
		}

		[[nodiscard]] bool full() const { return capacity == 0; }
		[[nodiscard]] uint32_t size() const { return capacity; }
	};

	class vertex {
	public:
		std::vector<std::unique_ptr<edge>> edges;
		void add_edge(vertex *v, uint32_t capacity, bool bidirectional) {
			auto [forward, reverse] = edge::make_edge(this, v, capacity, bidirectional);
			edges.emplace_back(std::move(forward));
			v->edges.emplace_back(std::move(reverse));
		}
	};

	static constexpr ptrdiff_t source = 0;
	static constexpr ptrdiff_t sink = 1;
	uint32_t vertex_cnt;
	std::unique_ptr<vertex[]> vertices;

	uint64_t ford_fulkerson_dfs(std::vector<bool> &visited, ptrdiff_t now, uint64_t in_flow) {
		if(now == sink) return in_flow;

		uint64_t flow;
		visited[now] = true;
		for(auto &e : vertices[now].edges) {
			auto const next = e->to - vertices.get();
			if(visited[next]) continue;
			uint64_t out_flow = std::min<uint64_t>(in_flow, e->size());
			if(out_flow && (flow = ford_fulkerson_dfs(visited, next, out_flow))) {
				e->fill(flow);
				return flow;
			}
		}
		return 0;
	}

	uint64_t edmonds_karp_bfs() {
		struct info { ptrdiff_t now; edge *in_edge; uint64_t flow; };
		auto before = std::make_unique<edge*[]>(vertex_cnt);
		std::queue<info> q;

		q.push({ source, nullptr, std::numeric_limits<uint64_t>::max() });

		while(!q.empty()) {
			auto [now, in_edge, flow] = q.front();
			q.pop();

			if(before[now]) continue;
			before[now] = in_edge;

			if(now == sink) {
				while(in_edge) {
					in_edge->fill(flow);
					in_edge = before[in_edge->from - vertices.get()];
				}
				return flow;
			}

			for(auto &e : vertices[now].edges) {
				auto const next = e->to - vertices.get();
				if(next == source || before[next] || e->full()) continue;
				assert(e->size() != 0);
				q.push({ next, e.get(), std::min<uint64_t>(flow, e->size()) });
			}
		}
		return 0;
	}

public:
	explicit graph(uint32_t vertex_cnt)
	  :	vertex_cnt(vertex_cnt), vertices(std::make_unique<vertex[]>(vertex_cnt)) { assert(vertex_cnt >= 2); }

	void add_edge(uint32_t from, uint32_t to, uint32_t capacity, bool bidirectional = false) {
		assert(from < vertex_cnt && to < vertex_cnt);
		vertices[from].add_edge(&vertices[to], capacity, bidirectional);
	}

	uint64_t flow_ford_fulkerson() {
		uint64_t total_flow = 0, flow = 0;
		std::vector<bool> visited(vertex_cnt);
		do {
			total_flow += flow;
			std::fill(visited.begin(), visited.end(), false);
			flow = ford_fulkerson_dfs(visited, 0, std::numeric_limits<uint64_t>::max());
		} while(flow);
		return total_flow;
	}

	uint64_t flow_edmonds_karp() {
		uint64_t total_flow = 0, flow;
		while((flow = edmonds_karp_bfs())) total_flow += flow;
		return total_flow;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	uint32_t n, m, k;
	std::cin >> n >> m >> k;

	graph G(n + m + 4);

	G.add_edge(0, 2, n);
	G.add_edge(0, 3, k);
	for(uint32_t i = 4; i < n + 4; i++) {
		G.add_edge(2, i, 1);
		G.add_edge(3, i, 1);

		uint32_t c, x;
		std::cin >> c;
		while(c--) {
			std::cin >> x;
			G.add_edge(i, n + x + 3, 1);
		}
	}
	for(uint32_t i = n + 4; i < n + m + 4; i++) {
		G.add_edge(i, 1, 1);
	}

	std::cout << G.flow_ford_fulkerson();
}