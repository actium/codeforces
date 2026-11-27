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

void answer(const std::vector<int>& v)
{
    std::cout << "YES" << '\n';

    const char* separator = "";
    for (const int x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(std::vector<int>& a, size_t k)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end(), std::greater<int>());
    std::reverse(a.begin(), a.begin() + k);

    for (long long i = 0, t = 0; i < n; t += a[i++]) {
        if (a[i] * i >= t && k-- == 0)
            return no_answer();
    }

    answer(a);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
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
