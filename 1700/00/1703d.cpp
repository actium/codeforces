#include <iostream>
#include <set>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<std::string>& s)
{
    const std::set<std::string> v(s.cbegin(), s.cend());

    const auto check = [&v](const std::string& s) {
        const size_t m = s.length();

        for (size_t k = 1; k < m; ++k) {
            if (v.count(s.substr(0, k)) == 1 && v.count(s.substr(k)) == 1)
                return '1';
        }
        return '0';
    };

    std::string t;
    for (const std::string& w : s)
        t.push_back(check(w));

    answer(t);
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
