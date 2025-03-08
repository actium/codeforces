#include <iostream>
#include <string>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(int x, const std::string& s, integer k)
{
    const auto simulate = [&] {
        unsigned d = 0;
        for (const char c : s) {
            x += (c == 'L' ? -1 : +1);
            ++d;
            if (x == 0)
                break;
        }
        return d;
    };

    k -= simulate();

    if (x != 0)
        return answer(0);

    const unsigned p = simulate();
    if (x != 0)
        return answer(1);

    answer(1 + k / p);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    int x;
    std::cin >> x;

    integer k;
    std::cin >> k;

    std::string s;
    std::cin >> s;

    solve(x, s, k);
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
