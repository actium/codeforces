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

void answer(const char* v)
{
    std::cout << v << '\n';
}

void solve(std::vector<std::pair<unsigned, unsigned>>& b)
{
    const size_t n = b.size();

    std::sort(b.begin(), b.end());

    for (size_t i = 1; i < n; ++i) {
        if (b[i-1].first < b[i].first && b[i-1].second > b[i].second)
            return answer("Happy Alex");
    }

    answer("Poor Alex");
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> b(n);
    std::cin >> b;

    solve(b);

    return 0;
}

