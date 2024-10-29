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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::vector<unsigned>& a, unsigned k)
{
    std::sort(a.begin(), a.end(), std::greater<unsigned>());

    unsigned t = 0, q = 0;
    for (unsigned d = 0; q < k; ) {
        const unsigned x = a.back() - d;
        if (k - q > 1ull * x * a.size()) {
            t += (x + 1) * a.size();
            q += (x + 1) * a.size();
            for (d = a.back() + 1; a.back() < d; a.pop_back())
                --q;
        } else {
            t += k - q;
            q += k - q;
        }
    }

    answer(t - (q - k));
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
