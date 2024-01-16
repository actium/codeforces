#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, const std::string& f)
{
    const size_t n = s.length();

    unsigned q[2] = {};
    for (size_t i = 0; i < n; ++i) {
        if (s[i] != f[i]) {
            q[0] += (s[i] == '1');
            q[1] += (f[i] == '1');
        }
    }

    answer(std::max(q[0], q[1]));
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string s, f;
    std::cin >> s >> f;

    solve(s, f);
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
