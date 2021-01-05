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

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(std::vector<unsigned>& k, const std::vector<unsigned>& c)
{
    const size_t n = k.size();

    std::sort(k.begin(), k.end(), std::greater<unsigned>());

    integer s = 0;
    for (size_t i = 0, j = 0; i < n; ++i) {
        if (j < k[i] && c[j] < c[k[i]-1])
            s += c[j++];
        else
            s += c[k[i]-1];
    }

    answer(s);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> k(n);
    std::cin >> k;

    std::vector<unsigned> c(m);
    std::cin >> c;

    solve(k, c);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

