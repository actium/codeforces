#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;

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

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(std::vector<std::pair<unsigned, unsigned>>& f, unsigned d)
{
    const size_t n = f.size();

    std::sort(f.begin(), f.end());

    integer s = 0, t = 0;
    for (size_t i = 0, j = 0; j < n; ++j) {
        for (t += f[j].second; f[j].first - f[i].first >= d; ++i)
            t -= f[i].second;

        s = std::max(s, t);
    }

    answer(s);
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned d;
    std::cin >> d;

    std::vector<std::pair<unsigned, unsigned>> f(n);
    std::cin >> f;

    solve(f, d);

    return 0;
}
