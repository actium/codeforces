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

bool test(const std::vector<std::string>& a, const std::string& s)
{
    const size_t m = s.length();

    for (const std::string& t : a) {
        size_t d = 0;
        for (size_t i = 0; i < m; ++i) {
            if (t[i] != s[i])
                ++d;
        }
        if (d > 1)
            return false;
    }
    return true;
}

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::string>& a, size_t m)
{
    for (size_t i = 0; i < m; ++i) {
        std::string s = a[0];
        for (char c = 'a'; c <= 'z'; ++c) {
            s[i] = c;
            if (test(a, s))
                return answer(s);
        }
    }

    answer(-1);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> a(n);
    std::cin >> a;

    solve(a, m);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

