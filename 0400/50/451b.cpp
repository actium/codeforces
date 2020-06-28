#include <algorithm>
#include <iostream>
#include <vector>

void answer(bool v)
{
    constexpr const char* s[2] = { "no", "yes" };
    std::cout << s[v] << '\n';
}

void answer(unsigned x, unsigned y)
{
    std::cout << 1 + x << ' ' << 1 + y << '\n';
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::vector<std::pair<size_t, size_t>> b;
    size_t s = n;
    for (size_t i = 0; i < n; ++i) {
        std::cin >> a[i];

        if (i == 0)
            continue;

        if (a[i] < a[i-1] && s == n) {
            s = i - 1;
            b.emplace_back(s, n - 1);
        }
        if (a[i] > a[i-1] && s != n) {
            b.back().second = i - 1;
            s = n;
        }
    }

    if (b.empty()) {
        answer(true);
        answer(0, 0);
    } else if (b.size() == 1) {
        std::reverse(a.begin() + b.front().first, a.begin() + b.front().second + 1);
        std::vector<unsigned> c = a;
        std::sort(c.begin(), c.end());
        if (c == a) {
            answer(true);
            answer(b.front().first, b.front().second);
        } else {
            answer(false);
        }
    } else {
        answer(false);
    }

    return 0;
}

