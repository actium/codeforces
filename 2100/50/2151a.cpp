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

void solve(size_t n, const std::vector<unsigned>& a)
{
    const size_t m = a.size();

    for (size_t i = 1; i < m; ++i) {
        if (a[i] != a[i-1] + 1)
            return answer(1);
    }

    answer(n - a.back() + 1);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(m);
    std::cin >> a;

    solve(n, a);
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
