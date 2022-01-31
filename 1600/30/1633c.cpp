#include <iostream>

using integer = unsigned long long;

using actor_t = std::pair<integer, integer>;

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const actor_t& c, const actor_t& m, unsigned k, integer w, integer a)
{
    for (unsigned i = 0; i <= k; ++i) {
        const integer h = c.first + (k - i) * a, d = c.second + i * w;

        const integer t1 = (m.first + d - 1) / d, t2 = (h + m.second - 1) / m.second;
        if (t1 <= t2)
            return answer(true);
    }

    answer(false);
}

void test_case()
{
    std::pair<integer, integer> c, m;
    std::cin >> c >> m;

    unsigned k;
    std::cin >> k;

    integer w, a;
    std::cin >> w >> a;

    solve(c, m, k, w, a);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
