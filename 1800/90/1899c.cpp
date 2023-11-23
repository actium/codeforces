#include <iostream>
#include <vector>

#include <climits>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(int x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<int>& a)
{
    const size_t n = a.size();

    int gm = INT_MIN, lm = 0;
    for (size_t i = 0; i < n; ++i) {
        if (i != 0 && (a[i] + 1000) % 2 == (a[i-1] + 1000) % 2)
            lm = 0;

        lm = lm + a[i];
        gm = std::max(gm, lm);
        lm = std::max(lm, 0);
    }

    answer(gm);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
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
