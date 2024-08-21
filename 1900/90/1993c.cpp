#include <algorithm>
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

void solve(std::vector<unsigned>& a, unsigned k)
{
    const unsigned m = 2 * k;

    const unsigned s = *std::max_element(a.begin(), a.end());
    for (unsigned& x : a)
        x += (s - x + k - 1) / m * m;

    const unsigned t = *std::max_element(a.begin(), a.end());
    for (const unsigned x : a) {
        if (x + k <= t)
            return no_answer();
    }

    answer(t);
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
