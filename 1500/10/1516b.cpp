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

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> px(1+n);
    for (size_t i = 0; i < n; ++i)
        px[i+1] = px[i] ^ a[i];

    for (size_t i = 1; i <= n; ++i) {
        for (size_t j = 0; j < i; ++j) {
            if (px[j] == (px[j] ^ px[i]) && px[j] == (px[n] ^ px[i]))
                return answer(true);
        }
    }

    answer(false);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
