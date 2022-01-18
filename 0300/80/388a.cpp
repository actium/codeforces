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

void solve(const std::vector<unsigned>& x)
{
    unsigned k = 0;
    for (std::multiset<unsigned> q(x.cbegin(), x.cend()); !q.empty(); ++k) {
        unsigned p = 0;
        for (auto it = q.lower_bound(p); it != q.end(); it = q.lower_bound(p)) {
            q.erase(it);
            ++p;
        }
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> x(n);
    std::cin >> x;

    solve(x);

    return 0;
}
