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

void solve(const std::vector<int>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> d(n);
    for (size_t i = 0, x = n; i < n; ++i)
        d[i] = x = (a[i] == 0 ? 0 : x + 1);

    for (size_t i = n - d.back(); i-- > 0; )
        d[i] = std::min(d[i], d[i+1] + 1);

    answer(d);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

