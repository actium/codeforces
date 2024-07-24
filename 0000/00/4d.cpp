#include <algorithm>
#include <iostream>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (auto it = v.rbegin(); it != v.rend(); ++it) {
        std::cout << separator << *it;
        separator = " ";
    }
    std::cout << '\n';
}

struct Envelope {
    unsigned i;
    unsigned w;
    unsigned h;
};

void solve(std::vector<Envelope>& e, unsigned w, unsigned h)
{
    const size_t n = e.size();

    std::sort(e.begin(), e.end(), [](const Envelope& lhs, const Envelope& rhs) {
        return lhs.w != rhs.w ? lhs.w < rhs.w : lhs.h < rhs.h;
    });

    std::vector<unsigned> s(n), p(n);
    for (size_t i = 0; i < n; ++i) {
        if (e[i].w <= w || e[i].h <= h)
            continue;

        s[i] = 1;
        p[i] = i;

        for (size_t j = 0; j < i; ++j) {
            if (e[j].w < e[i].w && e[j].h < e[i].h && s[j] + 1 > s[i]) {
                s[i] = s[j] + 1;
                p[i] = j;
            }
        }
    }

    size_t x = 0;
    for (size_t i = 1; i < n; ++i) {
        if (s[i] > s[x])
            x = i;
    }

    std::vector<unsigned> v;
    for (size_t k = s[x]; k != 0; --k) {
        v.push_back(e[x].i);
        x = p[x];
    }

    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned w, h;
    std::cin >> w >> h;

    std::vector<Envelope> e(n);
    for (size_t i = 0; i < n; ++i) {
        e[i].i = i + 1;
        std::cin >> e[i].w >> e[i].h;
    }

    solve(e, w, h);

    return 0;
}
