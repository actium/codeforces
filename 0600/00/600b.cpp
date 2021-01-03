#include <algorithm>
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


void solve(std::vector<int>& a, const std::vector<int>& b)
{
    const size_t m = b.size();

    std::sort(a.begin(), a.end());

    std::vector<unsigned> c(m);
    for (size_t i = 0; i < m; ++i) {
        const auto it = std::upper_bound(a.cbegin(), a.cend(), b[i]);
        c[i] = it - a.cbegin();
    }

    answer(c);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<int> a(n), b(m);
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}

