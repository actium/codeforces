#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<unsigned>& a)
{
    unsigned f[2] = {};
    for (const unsigned x : a)
        ++f[x-1];

    size_t i = 0;
    if (f[1] > 0) {
        a[i++] = 2;
        --f[1];
    }
    if (f[0] > 0) {
        a[i++] = 1;
        --f[0];
    }
    for ( ; f[1]-- > 0; a[i++] = 2);
    for ( ; f[0]-- > 0; a[i++] = 1);

    answer(a);
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

