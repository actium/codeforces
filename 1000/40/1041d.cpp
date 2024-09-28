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

void solve(std::vector<std::pair<unsigned, unsigned>>& s, unsigned h)
{
    const size_t n = s.size();

    s.emplace_back(~0u, ~0u);   // sentinel

    unsigned d = 0, u = 0;
    for (size_t i = 0, j = 1; j <= n; ++j) {
        if (u + s[j].first - s[j-1].second < h) {
            u += s[j].first - s[j-1].second;
        } else {
            d = std::max(d, s[j-1].second - s[i].first + h - u);
            if (i < j) {
                u -= s[i+1].first - s[i].second;
                ++i, --j;
            }
        }
    }

    answer(d);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned h;
    std::cin >> h;

    std::vector<std::pair<unsigned, unsigned>> s(n);
    std::cin >> s;

    solve(s, h);

    return 0;
}
