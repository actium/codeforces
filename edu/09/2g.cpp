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

void answer(int v)
{
    std::cout << v << '\n';
}

using integer = unsigned long long;

void solve(const std::vector<integer>& a)
{
    const size_t n = a.size();

    integer d = 0, k = ~0u;
    for (size_t i = 0, j = 0; j < n; ++j) {
        d = std::gcd(d, a[j]);

        if (d == 1) {
            integer x = 0;
            for (i = j; x != 1; --i)
                d = std::exchange(x, std::gcd(x, a[i]));

            k = std::min<unsigned>(k, j - i);
            i += 2;
        }
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<integer> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

