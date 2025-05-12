#include <iostream>
#include <string>
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

void solve(const std::string& s, const std::vector<unsigned>& a, unsigned k)
{
    const size_t n = s.size();

    const auto check = [&](unsigned b) {
        unsigned q = 0;
        {
            char z = 'R';
            for (size_t i = 0; i < n; ++i) {
                if (a[i] <= b)
                    continue;

                if (s[i] == 'B' && z == 'R')
                    ++q;

                z = s[i];
            }
        }
        return q <= k;
    };

    int lb = -1, ub = 1000000000;
    while (ub - lb > 1) {
        const unsigned mid = (lb + ub) / 2;
        (check(mid) ? ub : lb) = mid;
    }

    answer(ub);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::string s;
    std::cin >> s;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(s, a, k);
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
