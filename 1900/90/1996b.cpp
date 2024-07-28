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

void answer(const std::vector<std::string>& v)
{
    for (const std::string& x : v)
        std::cout << x << '\n';
}

void solve(std::vector<std::string>& s, size_t k)
{
    const size_t n = s.size();

    for (size_t i = 0; i < n; i += k) {
        for (size_t j = 0; j < n; j += k)
            s[i/k][j/k] = s[i][j];

        s[i/k].resize(n / k);
    }
    s.resize(n / k);

    answer(s);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<std::string> s(n);
    std::cin >> s;

    solve(s, k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
