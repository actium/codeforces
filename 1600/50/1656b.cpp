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

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(std::vector<int>& a, int k)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    for (size_t i = 0, j = 0; j < n; ++j) {
        while (i < j && a[i] + k < a[j])
            ++i;

        if (i != j && a[i] + k == a[j])
            return answer(true);
    }

    answer(false);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    int k;
    std::cin >> k;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
