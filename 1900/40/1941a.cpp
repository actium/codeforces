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

void solve(const std::vector<unsigned>& b, const std::vector<unsigned>& c, unsigned k)
{
    unsigned q = 0;
    for (const unsigned u : b) {
        for (const unsigned v : c) {
            if (u + v <= k)
                ++q;
        }
    }

    answer(q);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    unsigned k;
    std::cin >> k;

    std::vector<unsigned> b(n), c(m);
    std::cin >> b >> c;

    solve(b, c, k);
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
