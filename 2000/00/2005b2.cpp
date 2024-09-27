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
void solve(size_t n, std::vector<unsigned>& b, const std::vector<unsigned>& r)
{
    std::sort(b.begin(), b.end());

    for (const unsigned q : r) {
        if (q < b.front()) {
            answer(b.front() - 1);
            continue;
        }
        if (q > b.back()) {
            answer(n - b.back());
            continue;
        }
        const auto it = std::upper_bound(b.begin(), b.end(), q);
        answer((*it - *std::prev(it)) / 2);
    }
}

void test_case()
{
    size_t n, m, q;
    std::cin >> n >> m >> q;

    std::vector<unsigned> b(m), r(q);
    std::cin >> b >> r;

    solve(n, b, r);
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
