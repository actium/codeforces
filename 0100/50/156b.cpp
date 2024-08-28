#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    constexpr const char* t[3] = { "Lie", "Truth", "Not defined" };

    for (const unsigned x : v)
        std::cout << t[x] << '\n';
}

void solve(const std::vector<std::string>& a, unsigned m)
{
    const size_t n = a.size();

    std::vector<std::vector<size_t>> p(n), q(n);
    for (size_t i = 0; i < n; ++i) {
        const unsigned x = std::stoi(a[i].substr(1));
        (a[i][0] == '+' ? p : q)[x-1].push_back(i);
    }

    unsigned r = 0;
    for (size_t i = 0; i < n; ++i)
        r += q[i].size();

    std::vector<bool> x(n);
    for (size_t i = 0; i < n; ++i) {
        if (p[i].size() + (r - q[i].size()) == m)
            x[i] = true;
    }

    unsigned c = 0;
    for (size_t i = 0; i < n; ++i)
        c += x[i];

    std::vector<unsigned> d(n, 2);
    for (size_t i = 0; i < n; ++i) {
        if (x[i] && c == 1) {
            for (const size_t j : p[i])
                d[j] = 1;
            for (const size_t j : q[i])
                d[j] = 0;
        }
        if (!x[i] && c == 1) {
            for (const size_t j : p[i])
                d[j] = 0;
            for (const size_t j : q[i])
                d[j] = 1;
        }
        if (!x[i] && c > 1) {
            for (const size_t j : p[i])
                d[j] = 0;
            for (const size_t j : q[i])
                d[j] = 1;
        }
    }

    answer(d);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned m;
    std::cin >> m;

    std::vector<std::string> a(n);
    std::cin >> a;

    solve(a, m);

    return 0;
}
