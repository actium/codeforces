#include <iostream>
#include <vector>

void answer(int v)
{
    constexpr const char* s[3] = { "unrated", "maybe", "rated" };
    std::cout << s[v+1] << '\n';
}

void solve(const std::vector<std::pair<unsigned, unsigned>>& ab)
{
    const size_t n = ab.size();

    bool c = (ab[0].first != ab[0].second), d = false;
    for (size_t i = 1; i < n; ++i) {
        if (ab[i].first != ab[i].second)
            c = true;
        else if (ab[i].first > ab[i-1].first)
            d = true;
    }

    if (c)
        answer(1);
    else
        answer(d ? -1 : 0);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> ab(n);
    for (size_t i = 0; i < n; ++i)
        std::cin >> ab[i].first >> ab[i].second;

    solve(ab);

    return 0;
}

