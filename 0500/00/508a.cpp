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

void solve(size_t n, size_t m, const std::vector<std::pair<size_t, size_t>>& t)
{
    const size_t k = t.size();

    std::vector<std::vector<bool>> s(1+n+1, std::vector<bool>(1+m+1));
    for (size_t i = 0; i < k; ++i) {
        const size_t r = t[i].first;
        const size_t c = t[i].second;
        if (s[r][c])
            continue;

        s[r][c] = true;

        if (s[r-1][c-1] && s[r-1][c] && s[r][c-1])
            return answer(1 + i);

        if (s[r-1][c] && s[r-1][c+1] && s[r][c+1])
            return answer(1 + i);

        if (s[r][c-1] && s[r+1][c-1] && s[r+1][c])
            return answer(1 + i);

        if (s[r][c+1] && s[r+1][c] && s[r+1][c+1])
            return answer(1 + i);
    }

    answer(0);
}

int main()
{
    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::pair<size_t, size_t>> t(k);
    std::cin >> t;

    solve(n, m, t);

    return 0;
}

