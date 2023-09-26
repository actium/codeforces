#include <iostream>
#include <string>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    if (s == "2" || s == "3" || s == "5" || s == "7")
        return answer(s[0] - '0');

    std::vector<size_t> x[10];
    for (size_t i = 0; i < n; ++i)
        x[s[i]-'0'].push_back(i);

    for (const unsigned p : {11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97}) {
        const unsigned a = p / 10, b = p % 10;
        if (x[a].empty() || x[b].empty())
            continue;

        if (x[a].front() < x[b].back())
            return answer(p);
    }

    no_answer();
}

void test_case()
{
    std::string s;
    std::cin >> s;

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
