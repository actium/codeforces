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
    const char* separator = "";
    for (const int x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<int>& a)
{
    const size_t n = a.size();

    std::vector<int> b(n);
    for (size_t i = 1; i < n; i += 2) {
        b[i-1] = a[i];
        b[i] = -a[i-1];
    }

    if (n % 2 == 1) {
        size_t i = n-3, j = n-2, k = n-1;
        if (a[i] + a[j] == 0)
            std::swap(j, k);
        if (a[i] + a[j] == 0)
            std::swap(i, k);

        b[i] = -a[k];
        b[j] = -a[k];
        b[k] = a[i] + a[j];
    }

    answer(b);
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
