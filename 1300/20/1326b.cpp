#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<int>& v)
{
    const char* separator = "";
    for (const int x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<int>& b)
{
    const size_t n = b.size();

    std::vector<int> a(n);
    int x = 0;
    for (size_t i = 0; i < n; ++i) {
        a[i] = x + b[i];
        x = std::max(x, a[i]);
    }

    answer(a);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<int> b(n);
    std::cin >> b;

    solve(b);

    return 0;
}

