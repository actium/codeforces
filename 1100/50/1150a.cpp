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

void solve(const std::vector<unsigned>& s, const std::vector<unsigned>& b, size_t r)
{
    const unsigned x = *std::min_element(s.cbegin(), s.cend());
    const unsigned y = *std::max_element(b.cbegin(), b.cend());
    if (x < y) {
        const size_t k = r / x;
        return answer(r + k * (y - x));
    }

    answer(r);
}

int main()
{
    size_t n, m, r;
    std::cin >> n >> m >> r;

    std::vector<unsigned> s(n);
    std::cin >> s;

    std::vector<unsigned> b(m);
    std::cin >> b;

    solve(s, b, r);

    return 0;
}

