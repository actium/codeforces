#include <iostream>
#include <map>
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

void solve(const std::vector<int>& a, const std::vector<std::string>& s)
{
    const size_t n = a.size();

    const auto check = [&](const std::string& q) {
        if (q.length() != n)
            return false;

        std::map<char, int> u;
        std::map<int, char> v;
        for (size_t i = 0; i < n; ++i) {
            if (u.emplace(q[i], a[i]).first->second != a[i])
                return false;

            if (v.emplace(a[i], q[i]).first->second != q[i])
                return false;
        }
        return true;
    };

    for (const std::string& q : s)
        answer(check(q));
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
    std::cin >> a;

    size_t m;
    std::cin >> m;

    std::vector<std::string> s(m);
    std::cin >> s;

    solve(a, s);
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
