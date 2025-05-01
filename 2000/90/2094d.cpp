#include <iostream>
#include <string>
#include <vector>

std::vector<unsigned> encode(const std::string& t)
{
    std::vector<unsigned> code;
    {
        char z = ' ';
        for (const char c : t) {
            if (c != z) {
                code.push_back(1);
                z = c;
            } else {
                ++code.back();
            }
        }
    }
    return code;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& p, const std::string& s)
{
    if (p[0] != s[0])
        return answer(false);

    const std::vector<unsigned> u = encode(p), v = encode(s);
    if (u.size() != v.size())
        return answer(false);

    for (auto it = u.begin(), jt = v.begin(); it != u.end(); ++it, ++jt) {
        if (*jt < *it || *it * 2 < * jt)
            return answer(false);
    }

    answer(true);
}

void test_case()
{
    std::string p, s;
    std::cin >> p >> s;

    solve(p, s);
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
