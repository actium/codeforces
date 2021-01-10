#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

using integer = unsigned long long;

void answer(const std::vector<integer>& v)
{
    const char* separator = "";
    for (const integer x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<integer>& b)
{
    const size_t k = b.size(), n = 2 * k;

    std::vector<integer> a(n);
    a.back() = b.front();
    for (size_t i = 1; i < k; ++i) {
        a[i] = a[i-1] + (b[i] > b[i-1] ? b[i] - b[i-1] : 0);
        a[n-1-i] = b[i] - a[i];
    }

    answer(a);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<integer> b(n / 2);
    std::cin >> b;

    solve(b);

    return 0;
}

