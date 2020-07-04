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

unsigned f(const std::vector<unsigned>& a, size_t i)
{
    const size_t n = a.size();

    unsigned s = 0;
    for (size_t j = 1; j < n; ++j) {
        if (j == i)
            continue;

        if (j == i + 1)
            s = std::max(s, a[j] - a[i-1]);
        else
            s = std::max(s, a[j] - a[j-1]);
    }
    return s;
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    unsigned x = ~0u;
    for (size_t i = 1; i < n-1; ++i)
        x = std::min(x, f(a, i));

    answer(x);
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

