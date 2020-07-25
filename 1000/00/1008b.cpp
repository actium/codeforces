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

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(std::vector<std::pair<unsigned, unsigned>>& r)
{
    const size_t n = r.size();

    if (r[0].second > r[0].first)
        std::swap(r[0].first, r[0].second);

    for (size_t i = 1; i < n; ++i) {
        if (r[i].first > r[i-1].first || (r[i].second > r[i].first && r[i].second <= r[i-1].first))
            std::swap(r[i].first, r[i].second);

        if (r[i].first > r[i-1].first)
            return answer(false);
    }

    answer(true);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> r(n);
    std::cin >> r;

    solve(r);

    return 0;
}

