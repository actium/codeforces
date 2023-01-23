#include <iostream>
#include <string>

void answer(const std::string& x, const std::string& y, const std::string& z)
{
    std::cout << x << ' ' << y << ' ' << z << '\n';
}

void no_answer()
{
    std::cout << ":(" << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();
    for (size_t m = 1; m + 1 < n; ++m) {    
        for (size_t k = 1; m + k < n; ++k) {
            const std::string a = s.substr(0, m);
            const std::string b = s.substr(m, k);
            const std::string c = s.substr(m + k);
            if (a <= b && c <= b || b <= a && b <= c)
                return answer(a, b, c);
        }
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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
