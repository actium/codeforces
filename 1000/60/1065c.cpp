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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::vector<unsigned>& h, unsigned k)
{
    const size_t n = h.size();

    std::sort(h.begin(), h.end());

    unsigned q = 0;
    for (unsigned i = 0, b = h[0], r = 0; b < h.back(); ++b) {
        while (h[i] <= b)
            ++i;

        const unsigned w = n - i;
        if (w > r) {
            ++q;
            r = k;
        }

        r -= w;
    }

    answer(q);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::vector<unsigned> h(n);
    std::cin >> h;

    solve(h, k);

    return 0;
}
