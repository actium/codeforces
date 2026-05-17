#include <algorithm>
#include <iostream>
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
    constexpr const char* s[2] = { "Alice", "Bob" };
    std::cout << s[v] << '\n';
}

std::vector<std::pair<unsigned, unsigned>> factorize(unsigned x)
{
    std::vector<std::pair<unsigned, unsigned>> factors;
    for (unsigned i = 2; i * i <= x; ++i) {
        if (x % i != 0)
            continue;

        factors.emplace_back(i, 0);
        while (x % i == 0) {
            ++factors.back().second;
            x /= i;
        }
    }
    if (x != 1)
        factors.emplace_back(x, 1);

    return factors;
}

void solve(std::vector<unsigned>& a)
{
    if (std::is_sorted(a.begin(), a.end()))
        return answer(true);

    for (unsigned& x : a) {
        if (x == 1)
            continue;

        const auto factors = factorize(x);
        if (factors.size() > 1)
            return answer(false);

        x = factors[0].first;
    }

    answer(std::is_sorted(a.begin(), a.end()));
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
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
