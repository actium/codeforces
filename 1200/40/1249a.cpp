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

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(std::vector<size_t>& a)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    for (size_t i = 1; i < n; ++i) {
        if (a[i] - a[i-1] == 1)
            return answer(2);
    }

    answer(1);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<size_t> a(n);
    std::cin >> a;

    solve(a);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

