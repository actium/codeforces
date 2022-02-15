#include <iostream>
#include <map>
#include <vector>

using record_t = std::pair<unsigned, unsigned>;

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

void solve(const std::vector<record_t>& r)
{
    std::map<unsigned, unsigned> b;
    for (const record_t& x : r) {
        unsigned& c = b[x.second];
        if (x.first > c)
            return answer(false);

        c = std::max(c, x.first + 1);
    }

    answer(true);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<record_t> r(n);
    std::cin >> r;

    solve(r);

    return 0;
}
