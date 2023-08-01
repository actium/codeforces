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

void solve(std::vector<unsigned>& s, integer c)
{
    const size_t n = s.size();

    const auto f = [&](integer w) {
        integer t = 0;
        for (const unsigned x : s) {
            t += (x + 2 * w) * (x + 2 * w);
            if (t > c)
                return false;
        }
        return t <= c;
    };

    integer lb = 0, ub = 1000000000;
    while (lb + 1 < ub) {
        const integer mid = (lb + ub) / 2;
        (f(mid) ? lb : ub) = mid;
    }

    answer(lb);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    integer c;
    std::cin >> c;

    std::vector<unsigned> s(n);
    std::cin >> s;

    solve(s, c);
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
