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
    const size_t n = s.size();

    unsigned f[26] = {};
    for (const std::string& x : s) {
        for (const char c : x) {
            ++f[c - 'a'];
        }
    }

    for (size_t i = 0; i < 26; ++i) {
        if (f[i] % n != 0)
            return answer(false);
    }

    answer(true);
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

