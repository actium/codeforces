#include <iostream>
#include <vector>

using segment_t = std::pair<int, int>;

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

void answer(int v)
{
    std::cout << v << '\n';
}

void answer(size_t v)
{
    std::cout << 1 + v << '\n';
}

void solve(const std::vector<segment_t>& segments)
{
    const size_t n = segments.size();

    size_t best_candidate = n;

    int lb = segments.front().first, ub = segments.front().second;
    for (size_t i = 0; i < n; ++i) {
        const segment_t& segment = segments[i];

        lb = std::min(lb, segment.first);
        ub = std::max(ub, segment.second);

        if (segment.first <= lb && segment.second >= ub)
            best_candidate = i;
    }

    if (best_candidate == n || segments[best_candidate].first > lb || segments[best_candidate].second < ub)
        answer(-1);
    else
        answer(best_candidate);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<segment_t> segments(n);
    std::cin >> segments;

    solve(segments);

    return 0;
}

