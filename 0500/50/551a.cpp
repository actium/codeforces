#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    size_t rf[2002] = {};
    for (size_t i = 0; i < n; ++i)
        ++rf[a[i]];

    for (size_t i = 2001; i > 0; --i)
        rf[i-1] += rf[i];

    const char* separator = "";
    for (size_t i = 0; i < n; ++i) {
        const size_t r = a[i];
        std::cout << separator << 1 + rf[r+1];
        separator = " ";
    }
    std::cout << '\n';
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

