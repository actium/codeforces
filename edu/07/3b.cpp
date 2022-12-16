#include <algorithm>
#include <iostream>
#include <vector>

using edge_t = std::pair<unsigned, unsigned>;
using query_t = std::pair<unsigned, unsigned>;

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

class ComponentSet {
public:
    explicit ComponentSet(size_t size);

    size_t operator [](size_t x) noexcept;

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

inline size_t ComponentSet::operator [](size_t x) noexcept
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

void answer(const std::vector<unsigned>& v)
{
    for (const unsigned x : v)
        std::cout << x << '\n';
}

void solve(size_t n, const std::vector<edge_t>& e, const std::vector<query_t>& q)
{
    const size_t k = q.size();

    size_t block_size = 1;
    while (block_size * block_size < k)
        ++block_size;

    std::vector<size_t> order(k);
    for (size_t i = 0; i < k; ++i)
        order[i] = i;

    std::sort(order.begin(), order.end(), [&](size_t i, size_t j) {
        if (q[i].first / block_size != q[j].first / block_size)
            return q[i].first < q[j].first;

        return q[i].second < q[j].second;
    });

    std::vector<unsigned> answers(k);
    {
        ComponentSet cs(0);

        size_t t = 0, r = 0;
        for (const size_t i : order) {
            const size_t b = q[i].first / block_size + 1;
            if (b != t) {
                cs = ComponentSet(n);
                t = b;
                r = b * block_size;
            }

            for ( ; r < q[i].second; ++r) {
                cs.merge(e[r].first - 1, e[r].second - 1);
            }

            cs.persist();
            for (size_t j = q[i].first - 1, ub = std::min<size_t>(q[i].second, b * block_size); j < ub; ++j) {
                cs.merge(e[j].first - 1, e[j].second - 1);
            }
            answers[i] = cs.count();
            cs.rollback();
        }
    }
    answer(answers);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<edge_t> e(m);
    std::cin >> e;

    size_t k;
    std::cin >> k;

    std::vector<query_t> q(k);
    std::cin >> q;

    solve(n, e, q);

    return 0;
}
