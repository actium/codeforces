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

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t k = a.size();

    std::sort(a.begin(), a.end());

    for (size_t i = 0; i < k; ++i) {
        if ((k - 2) % a[i] != 0)
            continue;

        if (std::binary_search(a.begin() + i + 1, a.end(), (k - 2) / a[i]))
            return answer(a[i], (k - 2) / a[i]);
    }

    abort();
}

void test_case()
{
    size_t k;
    std::cin >> k;

    std::vector<unsigned> a(k);
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
