#include <iostream>
#include <set>
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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::pair<int, int>>& p)
{
    const size_t n = p.size();

    std::set<std::pair<int, int>> s(p.cbegin(), p.cend());

    unsigned k = 0;
    for (size_t i = 1; i < n; ++i) {
        for (size_t j = 0; j < i; ++j) {
            const int x = p[i].first + p[j].first, y = p[i].second + p[j].second;
            if (x % 2 == 0 && y % 2 == 0)
                k += s.count(std::make_pair(x / 2, y / 2));
        }
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<int, int>> p(n);
    std::cin >> p;

    solve(p);

    return 0;
}

