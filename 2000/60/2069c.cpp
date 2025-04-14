#include <iostream>
#include <vector>

constexpr unsigned M = 998244353;

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

void solve(const std::vector<unsigned>& a)
{
    unsigned p[3] = {};
    for (const unsigned x : a) {
        switch (x) {
            case 1:
                p[0] += 1;
                break;

            case 2:
                p[1] = (p[0] + 2 * p[1]) % M;
                break;

            case 3:
                p[2] = (p[1] + p[2]) % M;
                break;
        }
    }

    answer(p[2]);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);
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
