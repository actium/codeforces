#include <algorithm>
#include <iostream>
#include <string>
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

void answer(const std::vector<std::pair<unsigned, unsigned>>& v)
{
    for (const std::pair<unsigned, unsigned>& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void solve(const std::string& s, std::vector<std::pair<unsigned, unsigned>>& r)
{
    const size_t n = s.length();

    const auto shift = [n](size_t x, size_t d) {
        x += d;
        return x >= n ? x - n : x;
    };

    const auto sort = [n](const std::vector<size_t>& positions, const std::vector<size_t>& ranks) {
        std::vector<unsigned> bucket_offsets(1 + n);
        for (const size_t r : ranks)
            ++bucket_offsets[1 + r];

        for (size_t i = 1; i < n; ++i)
            bucket_offsets[i] += bucket_offsets[i - 1];

        std::vector<size_t> sa_positions(n);
        for (const size_t i : positions)
            sa_positions[bucket_offsets[ranks[i]]++] = i;

        return sa_positions;
    };

    std::vector<size_t> sa_positions(n);
    {
        for (size_t i = 0; i < n; ++i)
            sa_positions[i] = i;

        std::sort(sa_positions.begin(), sa_positions.end(), [&s](size_t x, size_t y) {
            return s[x] < s[y];
        });
    }

    std::vector<size_t> sa_ranks(n);
    {
        size_t x = sa_positions[0];
        for (const size_t i : sa_positions) {
            sa_ranks[i] = sa_ranks[x];
            if (s[i] != s[x])
                ++sa_ranks[i];

            x = i;
        }
    }

    std::vector<size_t> ranks(n);
    for (unsigned k = 1; k < n && sa_ranks[sa_positions.back()] + 1 != n; k *= 2) {
        for (size_t i = 0; i < n; ++i)
            sa_positions[i] = shift(sa_positions[i], n - k);

        std::swap(sa_ranks, ranks);
        sa_positions = sort(sa_positions, ranks);

        size_t x = sa_positions[0];
        sa_ranks[x] = 0;
        for (const size_t i : sa_positions) {
            sa_ranks[i] = sa_ranks[x];
            if (ranks[i] != ranks[x] || ranks[shift(i, k)] != ranks[shift(x, k)])
                ++sa_ranks[i];

            x = i;
        }
    }

    std::vector<unsigned> lcps(n);
    for (size_t i = 0, k = 0; i + 1 < n; ++i, k -= (k > 0)) {
        const size_t j = sa_positions[sa_ranks[i] - 1];
        while (s[i+k] == s[j+k])
            ++k;

        lcps[sa_ranks[i]] = k;
    }

    std::vector<std::vector<unsigned>> t;
    {
        const unsigned d = 32 - __builtin_clz(n);
        t.resize(d, lcps);

        for (size_t i = 0; i < n; ++i)
            t[0][i] = lcps[i];

        for (size_t i = 1, k = 1; i < d; ++i, k *= 2) {
            for (size_t j = 0; j < n; ++j) {
                const unsigned r = std::min(j + k, n - 1);
                t[i][j] = std::min(t[i-1][j], t[i-1][r]);
            }
        }
    }

    const auto lcp = [&t](size_t x, size_t y) {
        if (x > y)
            std::swap(x, y);

        const unsigned d = 31 - __builtin_clz(y - x), k = 1 << d;
        return std::min(t[d][x + 1], t[d][y - k + 1]);
    };

    std::sort(r.begin(), r.end(), [&](const std::pair<unsigned, unsigned>& x, const std::pair<unsigned, unsigned>& y) {
        if (x.first == y.first)
            return x.second < y.second;

        const unsigned rx = sa_ranks[x.first - 1], ry = sa_ranks[y.first - 1];
        const unsigned lx = x.second - x.first + 1, ly = y.second - y.first + 1;

        const unsigned k = lcp(rx, ry);
        if (k >= std::max(lx, ly))
            return lx == ly ? x.first < y.first : lx < ly;

        if (k >= std::min(lx, ly))
            return lx < ly;

        return s[x.first - 1 + k] < s[y.first - 1 + k];
    });

    answer(r);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> r(n);
    std::cin >> r;

    s.push_back(' ');
    solve(s, r);

    return 0;
}
