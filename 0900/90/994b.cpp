#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<integer>& v)
{
    const char* separator = "";
    for (const integer x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<unsigned>& p, const std::vector<unsigned>& c, size_t k)
{
    const size_t n = p.size();

    std::vector<size_t> o(n);
    for (size_t i = 0; i < n; ++i)
        o[i] = i;

    std::sort(o.begin(), o.end(), [&p](size_t x, size_t y) { return p[x] < p[y]; });

    std::vector<integer> q(n);
    {
        integer s = 0;

        std::multiset<unsigned> v;
        for (const size_t i : o) {
            q[i] = s + c[i];

            if (k == 0)
                continue;

            if (v.size() == k && c[i] > *v.begin()) {
                s -= *v.begin();
                v.erase(v.begin());
            }
            if (v.size() < k) {
                v.insert(c[i]);
                s += c[i];
            }
        }
    }

    answer(q);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> p(n), c(n);
    std::cin >> p >> c;

    solve(p, c, k);

    return 0;
}
