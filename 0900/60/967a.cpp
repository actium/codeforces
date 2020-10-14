#include <iostream>
#include <vector>

void answer(unsigned v)
{
    std::cout << v / 60 << ' ' << v % 60 << '\n';
}

void solve(const std::vector<unsigned>& t, unsigned s)
{
    const size_t n = t.size();

    if (t.front() >= 1 + s)
        return answer(0);

    for (size_t i = 1; i < n; ++i) {
        if (t[i] - t[i-1] >= 1 + s + 1 + s)
            return answer(t[i-1] + 1 + s);
    }

    answer(t.back() + 1 + s);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned s;
    std::cin >> s;

    std::vector<unsigned> t(n);
    for (size_t i = 0; i < n; ++i) {
        unsigned h, m;
        std::cin >> h >> m;

        t[i] = h * 60 + m;
    }

    solve(t, s);

    return 0;
}

