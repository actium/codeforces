#include <algorithm>
#include <iostream>
#include <vector>

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

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

void solve(std::vector<std::pair<unsigned, unsigned>>& e)
{
    std::sort(e.begin(), e.end(), [](const auto& lhs, const auto& rhs) {
        return lhs.first != rhs.first ? lhs.first < rhs.first : lhs.second > rhs.second;
    });

    unsigned x = 0, k = 0;
    for (const std::pair<unsigned, unsigned>& q : e) {
        if (q.second <= x)
            ++k;
        else
            x = q.second;
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> e(n);
    std::cin >> e;

    solve(e);

    return 0;
}
