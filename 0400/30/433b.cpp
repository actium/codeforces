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

void answer(uint64_t v)
{
    std::cout << v << '\n';
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> v(n);
    std::cin >> v;

    std::vector<uint64_t> s(n + 1);
    for (size_t i = 0; i < n; ++i)
        s[i + 1] = s[i] + v[i];

    std::sort(v.begin(), v.end());

    std::vector<uint64_t> u(n + 1);
    for (size_t i = 0; i < n; ++i)
        u[i + 1] = u[i] + v[i];

    size_t m;
    std::cin >> m;

    while (m-- > 0) {
        unsigned type, l, r;
        std::cin >> type >> l >> r;

        if (type == 1) {
            answer(s[r] - s[l-1]);
        } else {
            answer(u[r] - u[l-1]);
        }
    }

    return 0;
}

