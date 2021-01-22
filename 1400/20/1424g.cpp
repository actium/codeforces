#include <algorithm>
#include <iostream>
#include <vector>

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(std::vector<unsigned>& b, std::vector<unsigned>& d)
{
    const size_t n = b.size();

    std::sort(b.begin(), b.end());
    std::sort(d.begin(), d.end());

    unsigned k = 0, y = 0, p = 0;
    for (size_t i = 0, j = 0; j < n; ) {
        if (i < n && b[i] < d[j]) {
            if (++k > p) {
                y = b[i];
                p = k;
            }
            ++i;
        } else {
            --k;
            ++j;
        }
    }

    answer(y, p);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> b(n), d(n);
    for (size_t i = 0; i < n; ++i)
        std::cin >> b[i] >> d[i];

    solve(b, d);

    return 0;
}

