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

void solve(const std::vector<std::pair<unsigned, unsigned>>& t, unsigned s, unsigned m)
{
    unsigned x = 0;
    for (const std::pair<unsigned, unsigned>& d : t) {
        if (d.first - x >= s)
            return answer(true);

        x = d.second;
    }

    answer(m - x >= s);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned s, m;
    std::cin >> s >> m;

    std::vector<std::pair<unsigned, unsigned>> t(n);
    std::cin >> t;

    solve(t, s, m);
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
