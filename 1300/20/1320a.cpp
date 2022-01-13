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

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& b)
{
    const size_t n = b.size();

    std::vector<int> d(n);
    for (size_t i = 0; i < n; ++i)
        d[i] = 400000 + i - b[i];

    integer x = 0;

    std::vector<integer> r(600000);
    for (size_t i = 0; i < n; ++i) {
        r[d[i]] += b[i];
        x = std::max(x, r[d[i]]);
    }

    answer(x);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> b(n);
    std::cin >> b;

    solve(b);

    return 0;
}
