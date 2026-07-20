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

void solve(std::vector<int>& a)
{
    const size_t n = a.size();

    for (size_t i = 0; i + 1 < n; ++i) {
        if ((i % 2 == 0) != (a[i] == -1)) {
            a[i] = -a[i];
            a[i+1] = -a[i+1];
        }
    }

    answer(n > 1 && a[n-2] == -1 && a[n-1] == 1);
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
