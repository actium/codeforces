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

void solve(const std::vector<std::string>& w, const std::vector<std::string>& a)
{
    bool s[26] = {};
    for (const std::string& e : w) {
        const auto x = e[0] - 'a';
        s[x] = true;
    }

    for (const std::string& e : a) {
        for (const char c : e) {
            if (!s[c-'A'])
                return answer(false);
        }
    }

    answer(true);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> w(n), a(m);
    std::cin >> w >> a;

    solve(w, a);
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
