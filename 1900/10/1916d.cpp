#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<std::string>& v)
{
    for (const std::string& x : v)
        std::cout << x << '\n';
}

void solve(unsigned n)
{
    if (n == 1)
        return answer({ "1" });

    std::vector<std::string> s;
    for (size_t i = 0, k = (n - 3) / 2; i <= k; ++i) {
        for (const std::string_view p : { "169", "961" }) {
            std::string v;
            for (const char c : p) {
                v.push_back(c);
                v.append(i, '0');
            }
            v.resize(n, '0');
            s.push_back(v);
        }
    }
    s.push_back("196" + std::string(n - 3, '0'));

    answer(s);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    solve(n);
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
