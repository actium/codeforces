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

void no_answer()
{
    std::cout << "NO" << '\n';
}

void answer(const std::vector<unsigned>& v)
{
    std::cout << "YES" << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const std::vector<std::pair<unsigned, unsigned>>& t, unsigned s)
{
    const size_t n = t.size();

    std::vector<unsigned> d(n);
    for (size_t i = 0; i < n; ++i) {
        if (t[i].first > s)
            return no_answer();

        d[i] = t[i].first;
        s -= d[i];
    }

    for (size_t i = 0; i < n; ++i) {
        const unsigned x = std::min(t[i].second - t[i].first, s);
        d[i] += x;
        s -= x;
    }

    s > 0 ? no_answer() : answer(d);
}

int main()
{
    size_t d;
    std::cin >> d;

    unsigned s;
    std::cin >> s;

    std::vector<std::pair<unsigned, unsigned>> t(d);
    std::cin >> t;

    solve(t, s);

    return 0;
}

