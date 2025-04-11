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

    unsigned long long s = 0;
    for (const unsigned x : a)
        s += x;

    if (s % n != 0)
        return answer(false);

    s /= n;

    int balance[30] = {};
    for (size_t i = 0; i < n; ++i) {
        bool f = false;
        for (size_t j = 0; j < 30; ++j) {
            for (size_t k = 0; k < 30; ++k) {
                if (a[i] + (1 << j) == s + (1 << k)) {
                    --balance[j];
                    ++balance[k];
                    f = true;
                }
            }
        }

        if (!f)
            return answer(false);
    }

    for (size_t i = 0; i < 30; ++i) {
        if (balance[i] != 0)
            return answer(false);
    }

    answer(true);
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
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
