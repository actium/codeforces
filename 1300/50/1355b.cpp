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

void solve(std::vector<unsigned>& e)
{
    std::sort(e.begin(), e.end());

    unsigned k = 0, g = 0;
    for (const unsigned x : e) {
        if (++g == x)
            ++k, g = 0;
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> e(n);
    std::cin >> e;

    solve(e);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

