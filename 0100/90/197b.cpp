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

void answer(int x, int y)
{
    std::cout << x << '/' << y << '\n';
}

void answer(const char* x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<int>& a, const std::vector<int>& b)
{
    if (a.size() < b.size())
        return answer(0, 1);

    if (a.size() > b.size()) {
        const bool s = (a[0] < 0) == (b[0] < 0);
        return answer(s ? "Infinity" : "-Infinity");
    }

    const int d = std::gcd(a[0], b[0]);
    answer((b[0] < 0 ? -1 : 1) * a[0] / d, std::abs(b[0]) / d);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<int> a(n+1), b(m+1);
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}
