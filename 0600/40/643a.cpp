#include <iostream>
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
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& t)
{
    const size_t n = t.size();

    std::vector<unsigned> q(n);
    for (size_t i = 0; i < n; ++i) {
        std::vector<unsigned> f(1 + n);
        for (size_t j = i, x = 0; j < n; ++j) {
            ++f[t[j]];

            if (f[t[j]] > f[x] || f[t[j]] == f[x] && t[j] < x)
                x = t[j];

            ++q[x-1];
        }
    }

    answer(q);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> t(n);
    std::cin >> t;

    solve(t);

    return 0;
}
