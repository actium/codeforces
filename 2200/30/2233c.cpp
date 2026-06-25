#include <iostream>
#include <string>

unsigned evaluate(const std::string& s, const std::string& t)
{
    const size_t n = s.size();

    unsigned b = 0, v = 0;
    for (size_t i = 0; i < n; ++i) {
        if (t[i] == '1')
            continue;

        if (s[i] == '(') {
            ++b;
            continue;
        }

        if (b > 0) {
            --b;
            ++v;
        }
    }
    return v;
}

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, size_t k)
{
    const size_t n = s.size();

    std::string t(n, '0');
    for (size_t i = 0; i < n && k != 0; ++i) {
        if (s[i] == '(') {
            t[i] = '1';
            --k;
        }
    }

    auto x = std::make_pair(evaluate(s, t), t);
    for (size_t i = t.rfind('1'), j = s.rfind(')'); i < j && j != std::string::npos; ) {
        std::swap(t[i], t[j]);

        x = std::min(x, std::make_pair(evaluate(s, t), t));

        i = t.rfind('1', i-1);
        j = s.rfind(')', j-1);
    }

    answer(x.second);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    solve(s, k);
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