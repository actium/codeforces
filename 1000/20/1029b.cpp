#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    unsigned k = 0;
    for (auto it = a.cbegin(); it != a.cend(); ) {
        const auto lb = it;
        for (auto ub = a.cend(); it != ub; ++it) {
            ub = std::upper_bound(it + 1, a.cend(), *it * 2);
            k = std::max<unsigned>(k, ub - lb);
        }
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

