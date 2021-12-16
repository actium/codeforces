#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::pair<size_t, size_t>>& v)
{
    std::cout << v.size() << '\n';

    for (const std::pair<size_t, size_t>& x : v)
        std::cout << 1+x.first << ' ' << 1+x.second << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    const size_t n = a.size();

    std::vector<std::pair<size_t, unsigned>> d, u;
    for (size_t i = 0; i < n; ++i) {
        if (a[i] > b[i])
            d.emplace_back(i, a[i] - b[i]);

        if (a[i] < b[i])
            u.emplace_back(i, b[i] - a[i]);
    }

    std::vector<std::pair<size_t, size_t>> o;
    while (!d.empty() && !u.empty()) {
        const unsigned k = std::min(d.back().second, u.back().second);
        o.insert(o.end(), k, std::make_pair(d.back().first, u.back().first));

        d.back().second -= k;
        if (d.back().second == 0)
            d.pop_back();

        u.back().second -= k;
        if (u.back().second == 0)
            u.pop_back();
    }

    u.empty() && d.empty() ? answer(o) : no_answer();
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n), b(n);
    std::cin >> a >> b;

    solve(a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
