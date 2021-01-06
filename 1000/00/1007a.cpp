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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<size_t> x(n);
    for (size_t i = 0; i < n; ++i)
        x[i] = i;

    std::sort(x.begin(), x.end(), [&a](size_t i, size_t j) { return a[i] > a[j]; });

    unsigned k = 0;
    for (size_t j = 0; j < n; ++j) {
        if (a[x[j]] < a[x[k]])
            ++k;
    }

    answer(k);
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

