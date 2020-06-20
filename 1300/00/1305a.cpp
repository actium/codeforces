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

template <typename T>
std::ostream& operator <<(std::ostream& output, const std::vector<T>& v)
{
    if (size_t n = v.size(); n > 0) {
        auto it = v.cbegin();
        for (output << *it++; --n > 0; output << ' ' << *it++);
    }
    return output;
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<size_t> a(n);
    std::cin >> a;

    std::vector<size_t> b(n);
    std::cin >> b;

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    std::cout << a << '\n';
    std::cout << b << '\n';
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

