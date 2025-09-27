#include <iostream>
#include <numeric>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    for (size_t i = 2; i < n; ++i) {
        for (size_t j = 1; j < i; ++j) {
            const unsigned p = std::accumulate(a.begin(), a.begin() + j, 0) % 3;
            const unsigned q = std::accumulate(a.begin() + j, a.begin() + i, 0) % 3;
            const unsigned r = std::accumulate(a.begin() + i, a.end(), 0) % 3;

            if (p == q && q == r || p != q && q != r && r != p)
                return answer(j, i);
        }
    }

    answer(0, 0);
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
