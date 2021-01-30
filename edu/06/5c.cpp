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

template <typename T, typename F>
T search(T lb, T ub, F&& f)
{
    for (auto k = ub - lb; k > 1; ) {
        const auto half = k / 2;
        if (!f(lb + half))
            lb += half;

        k -= half;
    }
    return lb;
};

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(std::vector<unsigned>& a, std::vector<unsigned>& b, integer k)
{
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    const auto f = [&](integer x) {
        integer c = 0;
        for (const unsigned q : a) {
            if (q < x)
                c += std::upper_bound(b.begin(), b.end(), x-q-1) - b.begin();
        }
        return c >= k;
    };

    answer(search<integer>(0, 2000000001, f));
}

int main()
{
    size_t n;
    std::cin >> n;

    integer k;
    std::cin >> k;

    std::vector<unsigned> a(n), b(n);
    std::cin >> a >> b;

    solve(a, b, k);

    return 0;
}

