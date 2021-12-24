#include <iostream>
#include <string>
#include <vector>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length(), k = n / 3;

    std::vector<size_t> p[2];
    const auto select = [&p](char c) {
        return &p[c == 'M'];
    };

    for (size_t i = 0; i < n; ++i)
        select(s[i])->push_back(i);

    if (select('M')->size() != k)
        return answer(false);

    for (size_t i = 0; i < k; ++i) {
        const size_t m = select('M')->at(i);
        if (m < select('T')->at(i) || select('T')->at(i+k) < m)
            return answer(false);
    }

    answer(true);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string s;
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
