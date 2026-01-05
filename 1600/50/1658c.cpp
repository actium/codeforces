#include <iostream>
#include <utility>
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

void solve(const std::vector<unsigned>& c)
{
    const size_t n = c.size();

    if (n == 1)
        return answer(c[0] == 1);

    size_t x = n;
    for (size_t i = 0, j = n-1; i < n; j = i++) {
        if (c[j] == 1 && std::exchange(x, j) != n)
            return answer(false);

        if (c[i] > c[j] && c[i] - c[j] > 1)
            return answer(false);
    }

    answer(x != n);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> c(n);
    std::cin >> c;

    solve(c);
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
