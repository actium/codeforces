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

void answer(const char* x)
{
    std::cout << x << '\n';
}

void solve(std::vector<unsigned>& a, unsigned f, unsigned k)
{
    const unsigned x = a[f-1];

    std::sort(a.begin(), a.end(), std::greater<unsigned>());

    if (a[k-1] > x)
        return answer("NO");

    if (k == a.size() || a[k] < x)
        return answer("YES");

    answer("MAYBE");
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned f, k;
    std::cin >> f >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, f, k);
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
