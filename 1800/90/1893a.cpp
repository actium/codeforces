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

void solve(const std::vector<unsigned>& b, size_t k)
{
    const size_t n = b.size();

    std::vector<bool> v(n);
    for (size_t i = n - 1; !v[i] && k-- > 0; i = (n + i - b[i]) % n) {
        if (b[i] > n)
            return answer(false);

        v[i] = true;
    }

    answer(true);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> b(n);
    std::cin >> b;

    solve(b, k);
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
