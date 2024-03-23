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

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<unsigned>& a, unsigned x)
{
    const auto search = [&](unsigned b) {
        unsigned p = 0, s = 0, k = 0;
        for (const unsigned u : a) {
            p ^= u;

            if ((s | p | b) == b) {
                s |= p;
                p = 0;
                ++k;
            }
        }
        return p == 0 ? k : 0;
    };

    unsigned k = search(x);
    for (unsigned i = 29; ~i != 0; --i) {
        if ((x & 1 << i) != 0)
            k = std::max(k, search(x & ~(1 << i) | (1 << i) - 1));
    }

    k == 0 ? no_answer() : answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned x;
    std::cin >> x;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, x);
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
