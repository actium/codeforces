#include <algorithm>
#include <iostream>
#include <vector>

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

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

void solve(const std::vector<unsigned>& a, const std::vector<std::pair<unsigned, unsigned>>& r)
{
    const size_t n = a.size();

    std::vector<unsigned> b(1 + n);
    for (size_t i = 0; i < n; ++i)
        b[i + 1] = std::max(b[i], a[i]);

    for (const std::pair<unsigned, unsigned>& q : r) {
        if (q.first > q.second + 1 || b[q.first-1] > a[q.first-1]) {
            answer(0);
            continue;
        }

        const auto it = std::upper_bound(b.begin() + q.first, b.end(), a[q.first-1]);
        if (it == b.end() || it - (b.begin() + 1) > q.second) {
            answer(q.second - q.first + 1 + (q.first != 1));
            continue;
        }

        answer(it - (b.begin() + q.first + (q.first == 1)));
    }
}

void test_case()
{
    size_t n, q;
    std::cin >> n >> q;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<std::pair<unsigned, unsigned>> r(q);
    std::cin >> r;

    solve(a, r);
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
