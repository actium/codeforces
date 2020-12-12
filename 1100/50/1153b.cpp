#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<std::vector<unsigned>>& v)
{
    for (const std::vector<unsigned>& x : v) {
        const char* separator = "";
        for (const unsigned y : x) {
            std::cout << separator << y;
            separator = " ";
        }
        std::cout << '\n';
    }
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b, std::vector<std::vector<unsigned>>& t)
{
    const size_t n = b.size(), m = a.size();

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j)
            t[i][j] *= std::min(a[j], b[i]);
    }

    answer(t);
}

int main()
{
    size_t n, m, h;
    std::cin >> n >> m >> h;

    std::vector<unsigned> a(m);
    std::cin >> a;

    std::vector<unsigned> b(n);
    std::cin >> b;

    std::vector<std::vector<unsigned>> t(n, std::vector<unsigned>(m));
    std::cin >> t;

    solve(a, b, t);

    return 0;
}

