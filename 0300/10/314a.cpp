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
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& a, int k)
{
    const size_t n = a.size();

    long long p = 0, x = 1;
    for (size_t i = 2; i < n; ++i) {
        const long long d = p - (i - x) * (n - i) * a[i-1];
        if (d < k) {
            answer(i);
            ++x;
        } else {
            p += a[i-1] * (i - x);
        }
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    int k;
    std::cin >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);

    return 0;
}
