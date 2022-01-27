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

void solve(const std::vector<unsigned>& s, size_t k)
{
    const size_t n = s.size();

    const auto f = [&](unsigned x) {
        unsigned c = 0;
        for (int i = n-1, j = 0; i >= j; --i) {
            if (s[i] + s[j] <= x)
                ++j;

            ++c;
        }
        return c <= k;
    };

    unsigned lb = s.back() - 1, ub = 2 * s.back();
    while (lb + 1 < ub) {
        const unsigned mid = (lb + ub) / 2;
        (f(mid) ? ub : lb) = mid;
    }

    answer(ub);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> s(n);
    std::cin >> s;

    solve(s, k);

    return 0;
}
