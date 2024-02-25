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
    std::cout << "Possible" << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer(const char* x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& f, const std::vector<unsigned>& b)
{
    const size_t n = f.size(), m = b.size();

    std::vector<std::vector<size_t>> x(1 + n);
    for (size_t i = 0; i < n; ++i)
        x[f[i]].push_back(i);

    std::vector<unsigned> a(m);
    for (size_t i = 0; i < m; ++i) {
        if (x[b[i]].empty())
            return no_answer("Impossible");

        if (x[b[i]].size() == 1)
            a[i] = 1 + x[b[i]][0];
    }

    for (size_t i = 0; i < m; ++i) {
        if (a[i] == 0)
            return no_answer("Ambiguity");
    }

    answer(a);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> f(n), b(m);
    std::cin >> f >> b;

    solve(f, b);

    return 0;
}
