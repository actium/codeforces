#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a, unsigned m)
{
    const auto check = [&](unsigned k) {
        unsigned b = m-1;
        for (auto it = a.rbegin(); it != a.rend(); ++it) {
            if (*it > b && *it + k < m)
                return false;

            if (*it <= b)
                b = std::min(b, *it + k);
            else
                b = std::min(b, *it + k - m);
        }
        return true;
    };

    if (check(0))
        return answer(0);

    unsigned lb = 0, ub = m;
    while (ub - lb > 1) {
        const unsigned mid = lb + (ub - lb) / 2;
        (check(mid) ? ub : lb) = mid;
    }

    answer(ub);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned m;
    std::cin >> m;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, m);

    return 0;
}
