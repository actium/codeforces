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

void no_answer()
{
    std::cout << -1 << '\n';
}

void answer(size_t v)
{
    std::cout << 1 << '\n';
    std::cout << 1+v << '\n';
}

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();
    if (n == 1 || (n == 2 && a.front() == a.back()))
        return no_answer();

    answer(std::min_element(a.cbegin(), a.cend()) - a.cbegin());
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}

