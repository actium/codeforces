#include <algorithm>
#include <iostream>
#include <map>
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

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::map<unsigned, std::vector<unsigned>> p;
    for (unsigned x : a) {
        for (unsigned i = 2; i * i <= x; ++i) {
            if (x % i != 0)
                continue;

            unsigned k = 0;
            while (x % i == 0) {
                ++k;
                x /= i;
            }

            p[i].push_back(k);
        }

        p[x].push_back(1);
    }

    integer d = 1;
    for (std::pair<const unsigned, std::vector<unsigned>>& e : p) {
        if (e.second.size() == n)
            *std::min_element(e.second.begin(), e.second.end()) = ~0u;

        if (e.second.size() >= n - 1) {
            for (unsigned k = *std::min_element(e.second.begin(), e.second.end()); k != 0; --k)
                d *= e.first;
        }
    }

    answer(d);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
