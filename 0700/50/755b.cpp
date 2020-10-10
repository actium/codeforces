#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<std::string>& a, const std::vector<std::string>& b)
{
    const size_t n = a.size();
    const size_t m = b.size();

    unsigned k = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (a[i] == b[j])
                ++k;
        }
    }

    answer(n + k % 2 > m);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> a(n);
    std::cin >> a;

    std::vector<std::string> b(m);
    std::cin >> b;

    solve(a, b);

    return 0;
}

