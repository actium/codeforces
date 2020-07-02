#include <iostream>
#include <vector>

#include <climits>

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

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    unsigned long long sum = 0;
    unsigned min_odd = INT_MAX;
    for (size_t i = 0; i < n; ++i) {
        sum += a[i];

        if (a[i] % 2 == 1)
            min_odd = std::min(min_odd, a[i]);
    }

    if (sum % 2 != 0)
        sum -= min_odd;

    answer(sum);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

