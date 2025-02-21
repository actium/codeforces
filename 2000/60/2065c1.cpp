#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(std::vector<int>& a, const std::vector<int>& b)
{
    const size_t n = a.size();

    a[0] = std::min(a[0], b[0] - a[0]);
    for (size_t i = 1; i < n; ++i) {
        const int x = b[0] - a[i], min = std::min(a[i], x), max = std::max(a[i], x);
        if (max < a[i-1])
            return answer(false);

        a[i] = (a[i-1] <= min ? min : max);
    }

    answer(true);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<int> a(n), b(m);
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
