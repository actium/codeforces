#include <algorithm>
#include <iostream>
#include <vector>

void answer(size_t x)
{
    std::cout << 1+x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(std::vector<std::pair<int, size_t>>& b)
{
    const size_t n = b.size();

    std::sort(b.begin(), b.end());

    const auto check = [&](size_t x) {
        std::vector<int> s;
        for (size_t i = 0; i < n; ++i) {
            if (i != x)
                s.push_back(b[i].first);
        }

        for (size_t i = 2; i < s.size(); ++i) {
            if (s[i] - s[i-1] != s[1] - s[0])
                return false;
        }
        return true;
    };

    if (check(0))
        return answer(b[0].second);

    if (check(1))
        return answer(b[1].second);

    std::vector<size_t> x;
    for (size_t i = 2; i < n; ++i) {
        if (b[i].first - b[i-1].first == b[1].first - b[0].first)
            continue;

        if (i + 1 == n || b[i+1].first - b[i-1].first == b[1].first - b[0].first)
            x.push_back(i++);
        else
            return no_answer();
    }

    if (x.size() == 1)
        return answer(b[x.front()].second);

    no_answer();
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::pair<int, size_t>> b(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> b[i].first;
        b[i].second = i;
    }

    solve(b);

    return 0;
}
