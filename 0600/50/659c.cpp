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

void answer(const std::vector<unsigned>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<unsigned>& a, unsigned m)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    std::vector<unsigned> b;
    for (unsigned i = 0, x = 1; x <= m; ++x) {
        if (i < n && x == a[i]) {
            ++i;
        } else {
            b.push_back(x);
            m -= x;
        }
    }

    answer(b);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned m;
    std::cin >> m;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, m);

    return 0;
}

