#include <iostream>
#include <set>
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

void solve(const std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    const size_t n = a.size();

    int d = -1;
    for (size_t i = 0; i < n; ++i) {
        if (b[i] == 0)
            continue;

        if (a[i] < b[i])
            return answer(false);

        if (d != -1 && a[i] - b[i] != d)
            return answer(false);

        d = a[i] - b[i];
    }

    if (d != -1) {
        for (size_t i = 0; i < n; ++i) {
            if (b[i] == 0 && a[i] > d)
                return answer(false);
        }
    }

    answer(true);
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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
