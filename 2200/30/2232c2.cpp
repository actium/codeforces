#include <iostream>
#include <string>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& u, size_t x, size_t s)
{
    const auto count = [&](unsigned q) {
        unsigned ri = x, re = 0, k = 0;
        for (char c : u) {
            if (c == 'A' && q != 0) {
                c = 'I';
                --q;
            }

            if (c != 'I' && re != 0) {
                --re;
                ++k;
            }
            if (c == 'I' && ri != 0) {
                --ri;
                re += s - 1;
                ++k;
            }
        }
        return k;
    };

    unsigned lb = -1, ub = s * x + 1;
    while (ub - lb > 1) {
        const unsigned mid = (lb + ub) / 2;
        (count(mid) < count(mid+1) ? lb : ub) = mid;
    }

    answer(count(ub));
}

void test_case()
{
    size_t n, x, s;
    std::cin >> n >> x >> s;

    std::string u;
    std::cin >> u;

    solve(u, x, s);
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
