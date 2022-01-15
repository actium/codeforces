#include <iostream>
#include <set>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<size_t>& v)
{
    std::cout << "YES" << '\n';

    const char* separator = "";
    for (const size_t x : v) {
        std::cout << separator << 1+x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& h, size_t m, unsigned x)
{
    const size_t n = h.size();

    std::set<std::pair<unsigned, size_t>> t;
    for (size_t i = 0; i < m; ++i)
        t.emplace(0, i);

    std::vector<size_t> p(n);
    for (size_t i = 0; i < n; ++i) {
        const auto it = t.begin();
        p[i] = it->second;

        const unsigned s = it->first + h[i];
        t.erase(it);
        t.emplace(s, p[i]);
    }

    answer(p);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    unsigned x;
    std::cin >> x;

    std::vector<unsigned> h(n);
    std::cin >> h;

    solve(h, m, x);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
