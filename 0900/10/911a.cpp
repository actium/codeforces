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

    unsigned b = ~0u;
    for (const unsigned x : a)
        b = std::min(b, x);

    size_t k = n;
    for (size_t i = 0, j = n; i < n; ++i) {
        if (a[i] == b) {
            k = std::min(k, i - j);
            j = i;
        }
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

