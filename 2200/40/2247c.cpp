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

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    const size_t n = a.size();

    unsigned f[3] = {};
    for (size_t i = 0; i < n; ++i) {
        if (a[i] != b[i])
            ++f[a[i]];

        if (a[i] == 0 && b[i] == 0)
            ++f[2];
    }

    if (f[0] + f[1] == 0)
        return answer(0);

    if (f[1] % 2 == 1)
        return answer(1);

    if (f[1] != 0 || f[2] != 0 && f[0] + f[2] < n)
        return answer(2);

    no_answer();
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n), b(n);
    std::cin >> a >> b;

    solve(a, b);
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
