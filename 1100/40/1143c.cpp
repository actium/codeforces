#include <iostream>
#include <vector>

void answer(const std::vector<size_t>& v)
{
    const char* separator = "";
    for (const size_t x : v) {
        std::cout << separator << 1+x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<unsigned>& c, const std::vector<std::vector<size_t>>& s)
{
    const size_t n = c.size();

    const auto f = [&](size_t v) {
        for (const size_t u : s[v]) {
            if (c[u] == 0)
                return false;
        }
        return true;
    };

    std::vector<size_t> v;
    for (size_t i = 0; i < n; ++i) {
        if (c[i] == 1 && f(i))
            v.push_back(i);
    }

    v.empty() ? no_answer() : answer(v);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> c(n);
    std::vector<std::vector<size_t>> s(n);
    for (size_t i = 0; i < n; ++i) {
        int p;
        std::cin >> p >> c[i];

        if (p != -1)
            s[p-1].push_back(i);
    }

    solve(c, s);

    return 0;
}
