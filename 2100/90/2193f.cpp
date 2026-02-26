#include <iostream>
#include <map>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

unsigned distance(unsigned s, unsigned t, unsigned u)
{
    return std::max(s, t) - std::min(s, t) + std::max(t, u) - std::min(t, u);
}

void solve(const std::vector<unsigned>& x, const std::vector<unsigned>& y)
{
    const size_t m = x.size();

    std::map<unsigned, std::pair<unsigned, unsigned>> r;
    for (size_t i = 0; i < m; ++i) {
        const auto s = r.emplace(x[i], std::make_pair(y[i], y[i]));
        if (!s.second) {
            s.first->second.first = std::min(s.first->second.first, y[i]);
            s.first->second.second = std::max(s.first->second.second, y[i]);
        }
    }

    std::vector<std::pair<unsigned, unsigned>> q;
    for (auto it = r.rbegin(); it != r.rend(); ++it)
        q.push_back(it->second);

    integer d[2] = { 0, 0 };
    for (size_t i = 1; i < q.size(); ++i) {
        const integer e[2] = {
            std::min(d[0] + distance(q[i-1].first, q[i].second, q[i].first), d[1] + distance(q[i-1].second, q[i].second, q[i].first)),
            std::min(d[0] + distance(q[i-1].first, q[i].first, q[i].second), d[1] + distance(q[i-1].second, q[i].first, q[i].second)),
        };
        d[0] = e[0];
        d[1] = e[1];
    }

    answer(x[m-1] - x[m-2] + std::min(d[0], d[1]));
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned ax, ay, bx, by;
    std::cin >> ax >> ay >> bx >> by;

    std::vector<unsigned> x(n), y(n);
    std::cin >> x >> y;

    x.push_back(ax);
    y.push_back(ay);

    x.push_back(bx);
    y.push_back(by);

    solve(x, y);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
