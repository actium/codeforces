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

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<std::string>& s)
{
    std::vector<std::string> t;
    for (const std::string& q : s) {
        if (!t.empty() && q.length() > t.back().length())
            t.clear();

        if (t.empty() || q.length() == t.back().length())
            t.push_back(q);
    }

    answer(t.front() == std::string(t.back().rbegin(), t.back().rend()));
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::string> s(2 * n - 2);
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
