#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned long long v)
{
    std::cout << v << '\n';
}

void solve(std::vector<unsigned>& a, unsigned s)
{
    const size_t n = a.size(), m = n / 2;

    std::sort(a.begin(), a.end());

    unsigned long long k = 0;
    for (size_t i = 0; i < n; ++i) {
        if (i <= m && a[i] > s)
            k += a[i] - s;

        if (i >= m && a[i] < s)
            k += s - a[i];
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned s;
    std::cin >> s;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, s);

    return 0;
}

