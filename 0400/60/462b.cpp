#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void answer(uint64_t v)
{
    std::cout << v << '\n';
}

void solve(const std::string& cards, size_t k)
{
    std::vector<std::pair<uint64_t, char>> index(26);
    for (const char c : cards) {
        auto& p = index[c - 'A'];
        ++p.first;
        p.second = c;
    }

    std::sort(index.begin(), index.end());

    uint64_t sum = 0;
    while (!index.empty() && k > 0) {
        auto p = index.back();
        index.pop_back();

        if (p.first > k)
            p.first = k;

        sum += p.first * p.first;
        k -= p.first;
    }

    answer(sum);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    std::string cards;
    std::cin >> cards;

    solve(cards, k);

    return 0;
}

