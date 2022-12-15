#include <iostream>
#include <string>
#include <vector>

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

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t n, m;
    std::cin >> n >> m;

    ComponentSet cs(n);
    for (size_t i = 0; i < m; ++i) {
        std::string type;
        std::cin >> type;

        if (type == "persist") {
            cs.persist();
        }
        if (type == "union") {
            unsigned u, v;
            std::cin >> u >> v;

            cs.merge(u - 1, v - 1);
            std::cout << cs.count() << '\n';
        }
        if (type == "rollback") {
            cs.rollback();
            std::cout << cs.count() << '\n';
        }
    }

    return 0;
}
