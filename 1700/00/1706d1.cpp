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

void solve(std::vector<unsigned>& a, unsigned k)
{
    const auto check = [&](unsigned x) {
        unsigned lb = ~0u, ub = 0;
        for (const unsigned q : a) {
            const unsigned p = (x == 0 ? k : std::min(q / x, k));
            lb = std::min(lb, q / p);
            ub = std::max(ub, q / p);
        }
        return ub - lb;
    };

    unsigned v = a.back() - a.front();
    for (unsigned i = a.front() / k; i <= a.front(); ++i)
        v = std::min(v, check(i));

    answer(v);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);
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
