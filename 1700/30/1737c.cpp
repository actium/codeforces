#include <array>
#include <iostream>

using position_t = std::pair<unsigned, unsigned>;

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

template <typename T, size_t N>
std::istream& operator >>(std::istream& input, std::array<T, N>& v)
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

void solve(unsigned n, const std::array<position_t, 3>& s, const position_t& t)
{
    const auto check = [&](unsigned r, unsigned c) {
        for (size_t i = 0; i < 3; ++i) {
            if (s[i].first == r && s[i].second == c)
                return true;
        }
        return false;
    };

    const unsigned r = s[0].first ^ s[1].first ^ s[2].first;
    const unsigned c = s[0].second ^ s[1].second ^ s[2].second;

    if (r == 2 && c == 2 && check(1, 1))
        return answer(t.first == 1 || t.second == 1);

    if (r == 2 && c == n - 1 && check(1, n))
        return answer(t.first == 1 || t.second == n);

    if (r == n - 1 && c == n - 1 && check(n, n))
        return answer(t.first == n || t.second == n);

    if (r == n - 1 && c == 2 && check(n, 1))
        return answer(t.first == n || t.second == 1);

    answer(t.first % 2 != r % 2 || t.second % 2 != c % 2);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    std::array<position_t, 3> s;
    std::cin >> s;

    position_t t;
    std::cin >> t;

    solve(n, s, t);
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
