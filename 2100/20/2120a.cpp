#include <array>
#include <iostream>

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::array<std::pair<unsigned, unsigned>, 3>& s)
{
    if (s[0].first == s[2].first && s[0].second + s[1].second + s[2].second == s[1].first)
        return answer(true);

    if (s[0].first == s[1].first + s[2].first && s[1].second == s[2].second && s[0].first == s[0].second + s[1].second)
        return answer(true);

    if (s[0].second == s[2].second && s[0].first + s[1].first + s[2].first == s[1].second)
        return answer(true);

    if (s[0].second == s[1].second + s[2].second && s[1].first == s[2].first && s[0].second == s[0].first + s[1].first)
        return answer(true);

    answer(false);
}

void test_case()
{
    std::array<std::pair<unsigned, unsigned>, 3> s;
    std::cin >> s[0] >> s[1] >> s[2];

    solve(s);
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
