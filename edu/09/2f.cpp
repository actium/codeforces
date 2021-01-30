#include <iostream>
#include <deque>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<integer>& a, integer k)
{
    const size_t n = a.size();

    std::deque<integer> lb, ub;

    const auto update = [&a](std::deque<integer>& b, size_t x, auto f) {
        while (!b.empty() && f(a[x], a[b.back()]))
            b.pop_back();

        b.push_back(x);
    };

    integer t = 0;
    for (size_t i = 0, j = 0; j < n; ++j) {
        update(lb, j, [](integer a, integer b) { return a <= b; });
        update(ub, j, [](integer a, integer b) { return a >= b; });

        for ( ; a[ub.front()] - a[lb.front()] > k; ++i) {
            if (lb.front() == i)
                lb.pop_front();

            if (ub.front() == i)
                ub.pop_front();
        }

        t += j - i + 1;
    }

    answer(t);
}

int main()
{
    size_t n;
    std::cin >> n;

    integer k;
    std::cin >> k;

    std::vector<integer> a(n);
    std::cin >> a;

    solve(a, k);

    return 0;
}

