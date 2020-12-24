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

void solve(const std::vector<int>& t)
{
    integer k = 0;

    unsigned c[10 + 1 + 10] = {};
    for (const int x : t) {
        k += c[10 - x];
        ++c[10 + x];
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<int> t(n);
    std::cin >> t;

    solve(t);

    return 0;
}

