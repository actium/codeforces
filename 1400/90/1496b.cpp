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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::vector<unsigned>& a, size_t k)
{
    const size_t n = a.size();

    if (k == 0)
        return answer(n);

    std::sort(a.begin(), a.end());

    unsigned mex = 0;
    for (const unsigned x : a) {
        if (x == mex)
            ++mex;
    }

    if (mex > a.back())
        return answer(n + k);

    const unsigned x = (mex + a.back() + 1) / 2;
    answer(n + 1 - std::binary_search(a.cbegin(), a.cend(), x));
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
