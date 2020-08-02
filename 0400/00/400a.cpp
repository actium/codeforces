#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<std::pair<unsigned, unsigned>>& v)
{
    std::cout << v.size();

    for (const auto& x : v)
        std::cout << ' ' << x.first << 'x' << x.second;

    std::cout << '\n';
}

void solve(const std::string& s)
{
    constexpr unsigned d[6] = { 1, 2, 3, 4, 6, 12 };

    const auto test = [&s](unsigned a, unsigned b, unsigned j) -> bool {
        for (unsigned i = 0; i < a; ++i) {
            if (s[i * b + j] != 'X')
                return false;
        }
        return true;
    };

    std::vector<std::pair<unsigned, unsigned>> y;
    for (const unsigned a : d) {
        const unsigned b = 12 / a;

        for (unsigned j = 0; j < b; ++j) {
            if (test(a, b, j)) {
                y.emplace_back(a, b);
                break;
            }
        }
    }

    answer(y);
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

