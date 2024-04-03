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

void solve(const std::vector<int>& a)
{
    const size_t n = a.size();

    integer p = 0, lb = 0, ub = 0, x = 0;
    for(size_t i = 1; i < n; ++i) {
        const int d = std::abs(a[i] - a[i-1]);
        p += (i % 2 == 1 ? d : -d);

        lb = std::min(lb, p);
        ub = std::max(ub, p);

        x = std::max(x, p - lb);
        x = std::max(x, ub - p);
    }

    answer(x);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
