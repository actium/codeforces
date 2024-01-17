#include <iostream>
#include <numeric>
#include <vector>

constexpr unsigned oo = ~0u;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    unsigned k = 0;
    for (size_t i = 0; i < n; ++i)
        k += (a[i] == 1);

    if (k != 0)
        return answer(n - k);

    unsigned q = oo;
    for (size_t i = 0; i < n; ++i) {
        unsigned x = a[i];
        for (size_t j = i + 1; j < n; ++j) {
            x = std::gcd(x, a[j]);
            if (x == 1) {
                q = std::min<unsigned>(q, j - i + n - 1);
                break;
            }
        }
    }

    q < oo ? answer(q) : no_answer();
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
