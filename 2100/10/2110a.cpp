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

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    const size_t p[2] = {
        std::find_if(a.begin(), a.end(), [](unsigned x) { return x % 2 == 0; }) - a.begin(),
        std::find_if(a.begin(), a.end(), [](unsigned x) { return x % 2 == 1; }) - a.begin(),
    };
    const size_t q[2] = {
        std::find_if(a.rbegin(), a.rend(), [](unsigned x) { return x % 2 == 0; }) - a.rbegin(),
        std::find_if(a.rbegin(), a.rend(), [](unsigned x) { return x % 2 == 1; }) - a.rbegin(),
    };

    answer(std::min(p[0] + q[0], p[1] + q[1]));
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
