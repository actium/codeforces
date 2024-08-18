#include <iostream>
#include <string>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    unsigned k = 0;
    {
        std::vector<size_t> p;
        for (size_t i = 0; i < n; ++i) {
            if (s[i] == '(' || p.empty()) {
                p.push_back(i);
            } else {
                k += i - p.back();
                p.pop_back();
            }
        }
    }
    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

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
