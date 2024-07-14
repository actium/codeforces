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

void solve(const std::vector<int>& a)
{
    const size_t n = a.size();

    std::vector<long long> p(1+n);
    for (size_t i = 0; i < n; ++i)
        p[i+1] = p[i] + a[i];

    if (p[n] % 3 != 0)
        return answer(0);

    integer k = 0;
    for (size_t i = 1, q = 0; i < n; ++i) {
        if (p[i] == p[n] / 3 * 2)
            k += q;

        if (p[i] == p[n] / 3)
            ++q;
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
