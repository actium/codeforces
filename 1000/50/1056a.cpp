#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void solve(const std::vector<std::vector<unsigned>>& s)
{
    const size_t n = s.size();

    size_t f[100] = {};
    for (const std::vector<unsigned>& r : s) {
        for (const unsigned x : r)
            ++f[x-1];
    }

    const char* separator = "";
    for (size_t i = 0; i < 100; ++i) {
        if (f[i] != n)
            continue;

        std::cout << separator << i + 1;
        separator = " ";
    }
    std::cout << '\n';
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::vector<unsigned>> s(n);
    for (size_t i = 0; i < n; ++i) {
        size_t r;
        std::cin >> r;

        s[i].resize(r);
        std::cin >> s[i];
    }

    solve(s);

    return 0;
}

