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

void answer(unsigned k, const std::vector<unsigned>& v)
{
    std::cout << k << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    std::vector<unsigned> b(n);
    for (size_t i = 0; i < n; ++i) {
        if (i % 2 == 0)
            b[i] = a[(n+i)/2];
        else
            b[i] = a[i/2];
    }

    unsigned k = 0;
    for (size_t i = 1; i < n-1; ++i) {
        if (b[i] < b[i-1] && b[i] < b[i+1])
            ++k;
    }

    answer(k, b);
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

