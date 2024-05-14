#include <iostream>
#include <vector>

using integer = long long;

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

void solve(const std::vector<unsigned>& d, integer s)
{
    const size_t n = d.size();

    integer t = 0;
    for (const unsigned x : d)
        t += x;

    std::vector<unsigned> c(n);
    for (size_t i = 0; i < n; ++i) {
        const unsigned lb = std::max<integer>(s - (t - d[i]), 1);
        const unsigned ub = std::min<integer>(s - (n - 1), d[i]);
        c[i] = (lb - 1) + (d[i] - ub);
    }

    answer(c);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    integer s;
    std::cin >> s;

    std::vector<unsigned> d(n);
    std::cin >> d;

    solve(d, s);

    return 0;
}
