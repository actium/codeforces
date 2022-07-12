#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<integer>& v)
{
    const char* separator = "";
    for (const integer x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<unsigned>& a, size_t m)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    std::vector<integer> s(m), x(n);
    x[0] = s[0] = a[0];
    for (size_t i = 1; i < n; ++i) {
        s[i % m] += a[i];
        x[i] = x[i-1] + s[i % m];
    }

    answer(x);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, m);

    return 0;
}
