#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(std::vector<std::string>& a)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end(), std::greater<std::string>());

    if (a.back() == "0")
        return answer(a.back());

    size_t k = 0;
    for (size_t i = 1; i < n; ++i)
        k += a[i].length() - 1;

    answer(a[0] + std::string(k, '0'));
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::string> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
