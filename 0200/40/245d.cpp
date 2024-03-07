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

void solve(const std::vector<std::vector<int>>& b)
{
    const size_t n = b.size();

    std::vector<unsigned> a(n);
    for (size_t i = 1; i < n; ++i) {
        for (size_t j = 0; j < i; ++j) {
            a[i] |= b[i][j];
            a[j] |= b[i][j];
        }
    }

    answer(a);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::vector<int>> b(n, std::vector<int>(n));
    std::cin >> b;

    solve(b);

    return 0;
}
