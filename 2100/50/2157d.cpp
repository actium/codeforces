#include <algorithm>
#include <iostream>
#include <vector>

using integer = long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(std::vector<unsigned>& a, unsigned l, unsigned r)
{
    const auto p = std::partition(a.begin(), a.end(), [=](unsigned x) { return x >= l && x <= r; });

    integer b[2] = {};
    for (auto it = p; it != a.end(); ++it) {
        if (*it < l) {
            b[0] += l - *it;
            b[1] += r - *it;
        } else {
            b[0] += *it - l;
            b[1] += *it - r;
        }
    }

    std::sort(a.begin(), p);

    const auto check = [&](integer x) {
        integer s[2] = { b[0], b[1] };
        for (auto it = a.begin(), jt = p; it != jt && (s[0] < x || s[1] < x); ) {
            if (s[0] < s[1]) {
                s[0] += *--jt - l;
                s[1] -= r - *jt;
            } else {
                s[0] -= *it - l;
                s[1] += r - *it++;
            }
        }
        return s[0] >= x && s[1] >= x;
    };

    integer lb = 0, ub = 1e15;
    while (ub - lb > 1) {
        const integer mid = (lb + ub) / 2;
        (check(mid) ? lb : ub) = mid;
    }

    answer(lb);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned l, r;
    std::cin >> l >> r;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, l, r);
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
