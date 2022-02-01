#include <algorithm>
#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(std::string& a, unsigned k)
{
    const size_t n = a.length();

    const auto search = [&](const std::string::iterator& i) {
        const unsigned d = std::distance(i, a.end());
        return std::max_element(i, i + std::min(k + 1, d));
    };

    for (auto i = a.begin(); i != a.end(); ++i) {
        for (auto j = search(i); j != i && k > 0; --j, --k)
            std::swap(*j, *std::prev(j));
    }

    answer(a);
}

int main()
{
    std::string a;
    std::cin >> a;

    unsigned k;
    std::cin >> k;

    solve(a, k);

    return 0;
}
