#include <iostream>
#include <numeric>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<size_t>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const size_t x : v) {
        std::cout << separator << x;
        separator = " ";
    }
}

void solve(const std::vector<size_t>& a)
{
    const size_t n = a.size();

    std::vector<size_t> c;
    c.push_back(1);

    size_t s = a[0];
    for (size_t i = 1; i < n; ++i) {
        if (2 * a[i] <= a[0]) {
            c.push_back(i + 1);
            s += a[i];
        }
    }

    if (s * 2 <= std::accumulate(a.cbegin(), a.cend(), 0))
        c.clear();

    answer(c);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<size_t> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

