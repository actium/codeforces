#include <algorithm>
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

void answer(bool v)
{
    constexpr const char* s[2] = { "TRIANGLE", "SQUARE" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<std::string>& g)
{
    std::pair<unsigned, unsigned> p = { 0, 0 };
    for (const std::string& r : g) {
        const unsigned k = std::count(r.begin(), r.end(), '1');
        if (k != 0) {
            std::swap(p.first, p.second);
            p.second = k;
        }
    }

    answer(p.first == p.second);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::string> g(n);
    std::cin >> g;

    solve(g);
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
