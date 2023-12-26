#include <iostream>
#include <vector>

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

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

void solve(const std::vector<std::pair<int, int>>& p)
{
    const size_t n = p.size();

    unsigned f[4] = {};
    for (const std::pair<int, int>& x : p) {
        if (x.first < 0)
            ++f[0];
        if (x.first > 0)
            ++f[1];
        if (x.second < 0)
            ++f[2];
        if (x.second > 0)
            ++f[3];
    }

    answer(f[0] == 0 || f[1] == 0 || f[2] == 0 || f[3] == 0);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<int, int>> p(n);
    std::cin >> p;

    solve(p);
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
