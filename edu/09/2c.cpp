#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& a, integer b)
{
    const size_t n = a.size();

    integer s = 0, t = 0;
    for (size_t i = 0, j = 0; j < n; ++j) {
        for (s += a[j]; s > b; s -= a[i++]);

        t += j - i + 1;
    }

    answer(t);
}

int main()
{
    size_t n;
    std::cin >> n;

    integer b;
    std::cin >> b;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, b);

    return 0;
}

