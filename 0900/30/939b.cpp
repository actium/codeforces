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

void answer(unsigned x, integer y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(const std::vector<integer>& a, integer n)
{
    const size_t k = a.size();

    size_t t = 0;
    for (size_t i = 1; i < k; ++i) {
        if (n % a[i] < n % a[t])
            t = i;
    }

    answer(1+t, n / a[t]);
}

int main()
{
    integer n;
    std::cin >> n;

    size_t k;
    std::cin >> k;

    std::vector<integer> a(k);
    std::cin >> a;

    solve(a, n);

    return 0;
}

