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
    std::sort(a.begin(), a.end());

    while (!a.empty() && a.back() > a.size()) {
        a.pop_back();
    }

    answer(a.size() + 1);
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

