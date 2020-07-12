#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<size_t>& v)
{
    const char* separator = "";
    for (const size_t x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<size_t>& b, size_t n)
{
    const size_t m = b.size();

    std::vector<size_t> a(n);
    for (const size_t x : b) {
        for (size_t i = x-1; i < n && a[i] == 0; ++i)
            a[i] = x;
    }

    answer(a);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<size_t> b(m);
    std::cin >> b;

    solve(b, n);

    return 0;
}

