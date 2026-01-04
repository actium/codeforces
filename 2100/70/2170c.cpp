#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;

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

void solve(std::vector<unsigned>& q, std::vector<unsigned>& r, integer k)
{
    const size_t n = q.size();

    std::sort(q.begin(), q.end());
    std::sort(r.begin(), r.end());

    unsigned c = 0;
    for (size_t i = 0; i < n; ++i) {
        while (!q.empty()) {
            const integer y = r[i] + 1, x = q.back() * y + r[i];
            q.pop_back();

            if (x <= k) {
                ++c;
                break;
            }
        }
    }

    answer(c);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    integer k;
    std::cin >> k;

    std::vector<unsigned> q(n), r(n);
    std::cin >> q >> r;

    solve(q, r, k);
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
