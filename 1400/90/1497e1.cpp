#include <iostream>
#include <set>
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

unsigned reduce(unsigned x)
{
    unsigned v = 1;
    for (unsigned i = 2; i * i <= x; ++i) {
        if (x % i != 0)
            continue;

        unsigned p = 0;
        while (x % i == 0) {
            x /= i;
            ++p;
        }

        if (p % 2 == 1)
            v *= i;
    }
    return v * x;
}

void solve(const std::vector<unsigned>& a)
{
    unsigned k = 1;
    {
        std::set<unsigned> s;
        for (const unsigned x : a) {
            const unsigned v = reduce(x);
            if (s.count(v) != 0) {
                s.clear();
                ++k;
            }

            s.insert(v);
        }
    }

    answer(k);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

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
