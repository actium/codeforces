#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(std::string& a, std::string& b)
{
    unsigned c[2] = {};
    for (auto it = a.begin(), jt = b.begin(); it != a.end(); ++it, ++jt) {
        if (*it == ')' && c[0] < c[1] || *jt == ')' && c[1] < c[0])
            std::swap(*it, *jt);

        if (*it == ')' && c[0] == 0 || *jt == ')' && c[1] == 0)
            return answer(false);

        c[0] += (*it == '(') - (*it == ')');
        c[1] += (*jt == '(') - (*jt == ')');
    }

    answer(c[0] == 0 && c[1] == 0);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string a, b;
    std::cin >> a >> b;

    solve(a, b);
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
