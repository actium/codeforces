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

void solve(std::vector<unsigned>& a)
{
    std::sort(a.begin(), a.end());

    unsigned k = 0;
    for (auto l = a.cbegin(), r = a.cbegin(); r != a.cend(); ++r) {
        while (*r - *l > 5)
            ++l;

        k = std::max<unsigned>(k, r - l + 1);
    }

    answer(k);
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

