#include <iostream>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned a, unsigned b, unsigned k)
{
    std::vector<bool> c(1 + b);
    for (unsigned i = 2; i <= b; ++i) {
        if (c[i])
            continue;

        for (unsigned j = 2 * i; j <= b; j += i)
            c[j] = true;
    }

    std::vector<unsigned> p(1 + b);
    for (size_t i = 2; i <= b; ++i)
        p[i] = p[i-1] + !c[i];

    const auto check = [&](unsigned l) {
        for (unsigned x = a; x + l <= b + 1; ++x) {
            const unsigned q = p[x+l-1] - p[x-1];
            if (q < k)
                return false;
        }
        return true;
    };

    unsigned lb = 0, ub = b - a + 2;
    while (lb + 1 < ub) {
        const unsigned mid = (lb + ub) / 2;
        (check(mid) ? ub : lb) = mid;
    }

    ub < b - a + 2 ? answer(ub) : no_answer();
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned a, b, k;
    std::cin >> a >> b >> k;

    solve(a, b, k);

    return 0;
}
