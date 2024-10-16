#include <iostream>
#include <set>
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

void infinity()
{
    std::cout << "inf" << '\n';
}

void solve(int b, int q, int l, const std::vector<int>& a)
{
    if (std::abs(b) > l)
        return answer(0);

    std::set<int> s;
    for (const int x : a) {
        if (std::abs(x) <= l)
            s.insert(x);
    }

    const auto is_skipped = [&](int x) {
        return s.count(x) != 0;
    };

    if (b == 0 || q == 0)
        return is_skipped(0) ? answer(!is_skipped(b)) : infinity();

    if (q == 1 || q == -1)
        return is_skipped(b) && is_skipped(b * q) ? answer(0) : infinity();

    unsigned k = 0;
    for (long long x = b; std::abs(x) <= l; x *= q)
        k += !is_skipped(x);

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int b, q, l;
    std::cin >> b >> q >> l;

    size_t m;
    std::cin >> m;

    std::vector<int> a(m);
    std::cin >> a;

    solve(b, q, l, a);

    return 0;
}
