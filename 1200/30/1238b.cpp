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

void solve(std::vector<unsigned>& x, unsigned r)
{
    std::sort(x.begin(), x.end());

    x.erase(std::unique(x.begin(), x.end()), x.end());

    unsigned k = 0;
    while (!x.empty() && x.back() > k * r) {
        x.pop_back();
        ++k;
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned r;
    std::cin >> r;

    std::vector<unsigned> x(n);
    std::cin >> x;

    solve(x, r);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

