#include <array>
#include <iostream>
#include <vector>

template <typename T, size_t N>
std::istream& operator >>(std::istream& input, std::array<T, N>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

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

void solve(const std::vector<std::array<unsigned, 5>>& a)
{
    const size_t k = a.size() / 2;

    for (size_t i = 0; i < 5; ++i) {
        for (size_t j = 0; j < i; ++j) {
            unsigned k1 = 0, k2 = 0, k3 = 0;
            for (const auto& x : a) {
                k1 += (x[i] == 1 && x[j] == 0);
                k2 += (x[i] == 0 && x[j] == 1);
                k3 += (x[i] == 1 && x[j] == 1);
            }

            if (k1 + k3 >= k && k2 + k3 >= k && k1 + k2 + k3 == 2 * k)
                return answer(true);
        }
    }

    answer(false);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::array<unsigned, 5>> a(n);
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
