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

void answer(uint64_t x, uint64_t y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(std::vector<unsigned>& b)
{
    const size_t n = b.size();

    std::sort(b.begin(), b.end());

    size_t min_count = 0;
    for (size_t i = 0; i < n && b[i] == b.front(); ++i)
        ++min_count;

    size_t max_count = 0;
    for (size_t i = n; i-- > 0 && b[i] == b.back(); )
        ++max_count;

    if (b.back() == b.front()) {
        answer(0, uint64_t(min_count - 1) * min_count / 2);
    } else {
        answer(b.back() - b.front(), uint64_t(min_count) * max_count);
    }
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> b(n);
    std::cin >> b;

    solve(b);

    return 0;
}

