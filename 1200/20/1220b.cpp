#include <iostream>
#include <vector>

#include <cmath>

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

void solve(const std::vector<std::vector<unsigned>>& t)
{
    const size_t n = t.size();

    std::vector<unsigned> a(n);
    for (size_t i = 0; i < n; ++i) {
        const size_t j = (i + 1) % n, k = (i + 2) % n;

        a[i] = sqrt(1ull * t[i][j] * t[i][k] / t[j][k]) + 0.5;
    }

    answer(a);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::vector<unsigned>> t(n, std::vector<unsigned>(n));
    std::cin >> t;

    solve(t);

    return 0;
}

