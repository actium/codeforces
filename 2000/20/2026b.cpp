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

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<integer>& a)
{
    const size_t n = a.size();

    const auto check = [&](integer d) {
        unsigned skip_count = 0;
        for (size_t i = 0; i < n; ++i) {
            if (i + 1 < n && a[i+1] - a[i] <= d)
                ++i;
            else
                ++skip_count;
        }
        return skip_count <= 1;
    };

    integer lb = 0, ub = a.back();
    while (ub - lb > 1) {
        const integer mid = (lb + ub) / 2;
        (check(mid) ? ub : lb) = mid;
    }

    answer(ub);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<integer> a(n);
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
