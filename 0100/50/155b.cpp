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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(std::vector<std::pair<unsigned, unsigned>>& v)
{
    const size_t n = v.size();

    const auto comparator = [](const std::pair<unsigned, unsigned>& a, const std::pair<unsigned, unsigned>& b) {
        return a.second == b.second ? a.first > b.first : a.second > b.second;
    };
    std::sort(v.begin(), v.end(), comparator);

    unsigned s = 0;
    for (unsigned k = 1, i = 0; k != 0 && i < n; --k, ++i) {
        s += v[i].first;
        k += v[i].second;
    }

    answer(s);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> v(n);
    std::cin >> v;

    solve(v);

    return 0;
}

