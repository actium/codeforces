#include <iostream>
#include <numeric>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x, const std::vector<unsigned>& y)
{
    std::cout << x << '\n';

    const char* separator = "";
    for (const unsigned x : y) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}


void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> b = { a[0] };
    for (size_t i = 1; i < n; ++i) {
        if (std::gcd(a[i], b.back()) != 1)
            b.push_back(1);

        b.push_back(a[i]);
    }

    answer(b.size() - n, b);
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

