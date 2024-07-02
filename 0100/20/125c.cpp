#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator <<(std::ostream& output, const std::vector<T>& v)
{
    const char* separator = "";
    for (const T x : v) {
        output << separator << x;
        separator = " ";
    }
    return output;
}

void answer(const std::vector<std::vector<unsigned>>& v)
{
    std::cout << v.size() << '\n';

    for (const std::vector<unsigned>& x : v)
        std::cout << x <<'\n';
}

void solve(unsigned n)
{
    unsigned k = 3;
    while (k * (k + 1) <= 2 * n)
        ++k;

    std::vector<std::vector<unsigned>> g(k);
    for (unsigned i = 0, x = 1; i < k; ++i) {
        for (unsigned j = i + 1; j < k; ++j, ++x) {
            g[i].push_back(x);
            g[j].push_back(x);
        }
    }

    for (unsigned x = k * (k - 1) / 2 + 1; x <= n; ++x)
        g[0].push_back(x);

    answer(g);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}
