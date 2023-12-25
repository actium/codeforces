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

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<integer>& a)
{
    const auto check = [&](integer k) {
        std::vector<integer> rs;
        for (const integer x : a) {
            const integer r = x % k;
            if (rs.empty() || r != rs.front() && r != rs.back())
                rs.push_back(r);
        }
        return rs.size() == 2;
    };

    integer k = 2;
    while (!check(k))
        k *= 2;

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<integer> a(n);
    std::cin >> a;

    solve(a);
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
