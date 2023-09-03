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

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    unsigned lb = 0, ub = ~0u;
    for (size_t i = 1; i < n; ++i) {
        if (a[i-1] > a[i])
            lb = std::max(lb, (a[i-1] + a[i] + 1) / 2);

        if (a[i-1] < a[i])
            ub = std::min(ub, (a[i-1] + a[i]) / 2);
    }

    if (lb <= ub)
        return answer(lb);

    no_answer();
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
