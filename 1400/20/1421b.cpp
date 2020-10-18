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

void answer(const std::vector<std::pair<unsigned, unsigned>>& v)
{
    std::cout << v.size() << '\n';

    for (const auto& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void solve(const std::vector<std::string>& s)
{
    const size_t n = s.size();

    std::vector<std::pair<unsigned, unsigned>> p[2];

    p[s[0][1] - '0'].emplace_back(1, 2);
    p[s[1][0] - '0'].emplace_back(2, 1);

    p[s[n-1][n-2] - '0'].emplace_back(n, n-1);
    p[s[n-2][n-1] - '0'].emplace_back(n-1, n);

    if (p[0].size() == 0 || p[0].size() == 4)
        return answer({{1, 2}, {2, 1}});

    if (p[0].size() == 1)
        return answer({{ p[0][0].second, p[0][0].first }});

    if (p[0].size() == 3)
        return answer({{ p[1][0].second, p[1][0].first }});

    if (s[0][1] != s[1][0])
        return answer({{ p[0][0].second, p[0][0].first }, p[0][1] });

    answer({});
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::string> s(n);
    std::cin >> s;

    solve(s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

