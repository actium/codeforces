#include <iostream>
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

void solve(const std::vector<std::vector<int>>& t, size_t m)
{
    if (m % 2 != 0)
        return answer(false);

    for (const std::vector<int>& x : t) {
        if (x[1] == x[2])
            return answer(true);
    }

    answer(false);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> t(n, std::vector<int>(4));
    std::cin >> t;

    solve(t, m);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

