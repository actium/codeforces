#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Query {
    char t;
    unsigned u;
    unsigned v;
};

std::istream& operator >>(std::istream& input, Query& v)
{
    input >> v.t;
    if (v.t != '?') {
        input >> v.u >> v.v;
    }
    return input;
}

class ComponentSet {
public:
    explicit ComponentSet(size_t size);

    size_t operator [](size_t x) const noexcept;

    void merge(size_t x, size_t y);

    size_t count() const noexcept;

    void persist();

    void rollback() noexcept;

private:
    void save(size_t x);

    void load(size_t t) noexcept;

private:
    std::vector<int> roots_;
    size_t count_;

private:
    struct State {
        size_t index;
        int value;
        size_t count;
    };

    std::vector<State> states_;
    std::vector<size_t> points_;

}; // class ComponentSet

inline ComponentSet::ComponentSet(size_t size) :
    roots_(size, -1), count_(size)
{}

inline size_t ComponentSet::operator [](size_t x) const noexcept
{
    const int root = roots_[x];
    return root < 0 ? x : (*this)[root];
}

inline void ComponentSet::merge(size_t x, size_t y)
{
    auto rx = operator [](x), ry = operator [](y);
    if (rx == ry)
        return;

    if (roots_[rx] > roots_[ry])
        std::swap(rx, ry);

    save(rx);
    save(ry);

    roots_[rx] += roots_[ry];
    roots_[ry] = rx;
    --count_;
}

inline size_t ComponentSet::count() const noexcept
{
    return count_;
}

inline void ComponentSet::persist()
{
    points_.push_back(states_.size());
}

inline void ComponentSet::rollback() noexcept
{
    load(points_.back());
    points_.pop_back();
}

inline void ComponentSet::save(size_t x)
{
    State state;
    state.index = x;
    state.value = roots_[x];
    state.count = count_;
    states_.push_back(state);
}

inline void ComponentSet::load(size_t t) noexcept
{
    while (states_.size() > t) {
        const State& state = states_.back();
        roots_[state.index] = state.value;
        count_ = state.count;
        states_.pop_back();
    }
}

struct Edge {
    unsigned u;
    unsigned v;
    size_t lb;
    size_t ub;
};

void solve(ComponentSet& cs, size_t lb, size_t ub, const std::vector<Edge>& e, std::vector<unsigned>& v)
{
    cs.persist();

    std::vector<Edge> se;
    for (const Edge& x : e) {
        if (x.lb <= lb && x.ub >= ub) {
            cs.merge(x.u - 1, x.v - 1);
        } else if (x.lb <= ub && x.ub >= lb) {
            se.push_back(x);
        }
    }

    if (lb != ub) {
        const size_t mid = (lb + ub) / 2;
        solve(cs, lb, mid, se, v);
        solve(cs, mid + 1, ub, se, v);
    } else if (lb < v.size()) {
        v[lb] = cs.count();
    }

    cs.rollback();
}

void solve(size_t n, const std::vector<Query>& q)
{
    const size_t m = q.size();

    std::map<std::pair<unsigned, unsigned>, std::vector<std::pair<size_t, size_t>>> g;
    for (size_t i = 0; i < m; ++i) {
        if (q[i].t == '+') {
            const std::pair<unsigned, unsigned> e = std::minmax(q[i].u, q[i].v);
            g[e].emplace_back(i, m);
        }
        if (q[i].t == '-') {
            const std::pair<size_t, size_t> e = std::minmax(q[i].u, q[i].v);
            g[e].back().second = i - 1;
        }
    }

    std::vector<Edge> e;
    for (const auto& x : g) {
        for (const auto& r : x.second) {
            Edge edge;
            edge.u = x.first.first;
            edge.v = x.first.second;
            edge.lb = r.first;
            edge.ub = r.second;
            e.push_back(edge);
        }
    }

    std::vector<unsigned> v(m);
    {
        ComponentSet cs(n);
        solve(cs, 0, m, e, v);
    }

    for (size_t i = 0; i < m; ++i) {
        if (q[i].t == '?')
            std::cout << v[i] << '\n';
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<Query> q(m);
    std::cin >> q;

    solve(n, q);

    return 0;
}
