#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<std::string>& v)
{
    std::cout << "YES" << '\n';
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const std::string& x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

std::vector<unsigned> manacher(std::string_view s)
{
    std::string t = " ";
    for (const char c : s) {
        t.push_back(c);
        t.push_back(' ');
    }

    const size_t n = t.length();

    std::vector<unsigned> v(n);
    for (size_t i = 0, j = 0; i < n; ) {
        while (i >= j && i + j < n && t[i-j] == t[i+j])
            ++j;

        v[i] = j;

        size_t k = 1;
        while (i >= k && i + k < n && k + v[i-k] < j) {
            v[i+k] = v[i-k];
            ++k;
        }

        i += k;
        j -= k;
    }

    return v;
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    const std::vector<unsigned> mv = manacher(s);

    const auto is_palindrome = [&](size_t b, size_t e) {
        const size_t r = e - b, x = b + r / 2;
        return (r % 2 == 1 ? mv[2 * x + 1] : mv[2 * x]) >= r;
    };

    if (!is_palindrome(0, n))
        return answer({ s });

    for (size_t i = 1; i < n; ++i) {
        if (!is_palindrome(0, i) && !is_palindrome(i, n))
            return answer({ s.substr(0, i), s.substr(i) });
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
