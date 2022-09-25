#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b, unsigned m)
{
    std::vector<std::pair<integer, integer>> v;

    const auto insert = [&](unsigned x, integer k) {
        while (x % m == 0) {
            x /= m;
            k *= m;
        }

        if (v.empty() || v.back().first != x) {
            v.emplace_back(x, k);
        } else {
            v.back().second += k;
        }
    };

    const auto extract = [&](unsigned x) {
        if (v.empty() || x % v.back().first != 0)
            return false;

        integer y = v.back().first, k = 1;
        while (y < x) {
            y *= m;
            k *= m;
        }

        if (y != x || v.back().second < k)
            return false;

        v.back().second -= k;
        if (v.back().second == 0)
            v.pop_back();

        return true;
    };

    for (const unsigned x : a)
        insert(x, 1);

    for (size_t i = b.size(); i-- > 0; ) {
        if (!extract(b[i]))
            return answer(false);
    }

    answer(v.empty());
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned m;
    std::cin >> m;

    std::vector<unsigned> a(n);
    std::cin >> a;

    size_t k;
    std::cin >> k;

    std::vector<unsigned> b(k);
    std::cin >> b;

    solve(a, b, m);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
