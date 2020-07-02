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

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    size_t max_d = 0;
    for (size_t i = 0, d = 0; i < 2 * n; ++i) {
        if (a[i % n] == 1)
            ++d;
        else
            d = 0;

        max_d = std::max(max_d, d);
    }

    answer(max_d);
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

