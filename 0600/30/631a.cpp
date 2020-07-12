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

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    const size_t n = a.size();

    unsigned x = 0, y = 0;
    for (size_t i = 0; i < n; ++i) {
        x |= a[i];
        y |= b[i];
    }

    answer(x + y);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<unsigned> b(n);
    std::cin >> b;

    solve(a, b);

    return 0;
}

