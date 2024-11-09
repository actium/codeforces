#include <iostream>
#include <string>
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

void solve(std::string& s, const std::vector<std::pair<unsigned, unsigned>>& r)
{
    const size_t n = s.length();

    unsigned k = 0;
    for (size_t i = 3; i < n; ++i)
        k += (s.substr(i-3, 4) == "1100");

    for (const std::pair<unsigned, unsigned>& q : r) {
        for (size_t i = (q.first > 3 ? q.first - 4 : 0); i < q.first; ++i)
            k -= (s.substr(i, 4) == "1100");

        s[q.first-1] = '0' + q.second;

        for (size_t i = (q.first > 3 ? q.first - 4 : 0); i < q.first; ++i)
            k += (s.substr(i, 4) == "1100");

        answer(k != 0);
    }
}

void test_case()
{
    std::string s;
    std::cin >> s;

    size_t q;
    std::cin >> q;

    std::vector<std::pair<unsigned, unsigned>> r(q);
    std::cin >> r;

    solve(s, r);
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
