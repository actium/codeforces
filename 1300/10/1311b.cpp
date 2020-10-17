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

void solve(std::vector<unsigned>& a, const std::vector<unsigned>& p)
{
    const size_t n = a.size();

    std::vector<bool> z(n);
    for (const unsigned x : p)
        z[x] = true;

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = i; j > 0 && a[j] < a[j-1]; --j) {
            if (!z[j])
                return answer(false);

            std::swap(a[j], a[j-1]);
        }
    }

    answer(true);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<unsigned> p(m);
    std::cin >> p;

    solve(a, p);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

