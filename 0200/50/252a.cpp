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

    unsigned y = 0;
    for (size_t i = 0; i < n; ++i) {
        unsigned x = 0;
        for (size_t j = i; j < n; ++j) {
            x ^= a[j];
            y = std::max(y, x);
        }
    }

    answer(y);
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

