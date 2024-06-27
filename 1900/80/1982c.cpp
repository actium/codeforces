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

void solve(const std::vector<unsigned>& a, unsigned lb, unsigned ub)
{
    using integer = unsigned long long;

    unsigned k = 0;
    {
        integer s = 0;

        std::set<integer> q;
        for (const unsigned x : a) {
            s += x;
            q.insert(s);

            if (s < lb)
                continue;

            if (s > ub) {
                const auto it = q.lower_bound(s - ub);
                if (it != q.end() && s - *it >= lb)
                    s -= *it;
            }

            if (s <= ub) {
                ++k;
                s = 0;
                q.clear();
            }
        }
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned lb, ub;
    std::cin >> lb >> ub;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, lb, ub);
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
