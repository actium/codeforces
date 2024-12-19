#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << "YES" << '\n';
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(const std::vector<unsigned>& a, unsigned k)
{
    const size_t n = a.size();

    const auto check = [&](size_t x) {
        for (size_t i = 0; i < n; ++i) {
            if (i != x) {
                const unsigned d = std::max(a[i], a[x]) - std::min(a[i], a[x]);
                if (d % k == 0)
                    return false;
            }
        }
        return true;
    };

    for (size_t i = 0; i < n; ++i) {
        if (check(i))
            return answer(i+1);
    }

    no_answer();
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<unsigned> a(n);
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
