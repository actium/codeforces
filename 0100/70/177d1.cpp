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

void solve(std::vector<unsigned>& a, const std::vector<unsigned>& b, unsigned c)
{
    const size_t n = a.size(), m = b.size();

    for (size_t i = 0; i <= n - m; ++i) {
        for (size_t j = 0; j < m; ++j)
            a[i+j] = (a[i+j] + b[j]) % c;
    }

    answer(a);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    unsigned c;
    std::cin >> c;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<unsigned> b(m);
    std::cin >> b;

    solve(a, b, c);

    return 0;
}

