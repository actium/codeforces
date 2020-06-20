#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<size_t>& d, size_t s, size_t t)
{
    if (s > t)
        std::swap(s, t);

    const size_t n = d.size();

    size_t d1 = 0, d2 = 0, d3 = 0;
    for (size_t i = 0; i < n; ++i) {
        if (i < s)
            d1 += d[i];
        else if (i < t)
            d2 += d[i];
        else
            d3 += d[i];
    }

    answer(std::min(d1 + d3, d2));
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<size_t> d(n);
    std::cin >> d;

    size_t s, t;
    std::cin >> s >> t;

    solve(d, s-1, t-1);

    return 0;
}

