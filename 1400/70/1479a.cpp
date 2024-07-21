#include <iostream>
#include <vector>

void answer(size_t x)
{
    std::cout << '!' << ' ' << 1+x << std::endl;
}

void solve(unsigned n)
{
    std::vector<unsigned> p(n);

    const auto query = [&](size_t x) {
        if (p[x] == 0) {
            std::cout << '?' << ' ' << 1+x << std::endl;
            std::cin >> p[x];
        }
        return p[x];
    };

    size_t lb = 0, ub = n;
    while (lb + 1 < ub) {
        const size_t mid = (lb + ub) / 2;

        (query(mid-1) > query(mid) ? lb : ub) = mid;
    }

    answer(lb);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}
