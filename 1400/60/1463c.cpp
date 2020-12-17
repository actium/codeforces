#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

struct State {
    unsigned t;
    int x;
};

std::istream& operator >>(std::istream& input, State& v)
{
    return input >> v.t >> v.x;
}

void solve(const std::vector<State>& c)
{
    const size_t n = c.size();

    unsigned k = 0;

    State current = { 0, 0 }, target = { 0, 0 };
    int velocity = 0;
    for (size_t i = 0; i < n; ++i) {
        const auto [t, x] = c[i];

        if (t < target.t) {
            current.x += velocity * (t - current.t);
        } else {
            current = target;
            velocity = 0;
        }

        current.t = t;

        if (velocity == 0 && x != current.x) {
            target.x = x;
            target.t = current.t + abs(target.x - current.x);
            velocity = (target.x < current.x ? -1 : 1);
        }

        unsigned dt = target.t - current.t;
        if (i + 1 < n)
            dt = std::min(dt, c[i+1].t - current.t);

        const int next_x = current.x + velocity * dt;
        if (x >= std::min(current.x, next_x) && x <= std::max(current.x, next_x))
            ++k;
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<State> c(n);
    std::cin >> c;

    solve(c);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

