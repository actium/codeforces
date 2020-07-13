#include <algorithm>
#include <iostream>
#include <vector>

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

void solve(std::vector<unsigned>& t)
{
    std::sort(t.begin(), t.end());
    t.erase(std::unique(t.begin(), t.end()), t.end());

    const size_t n = t.size();
    for (size_t i = 0; i+2 < n; ++i) {
        if (t[i]+1 == t[i+1] && t[i]+2 == t[i+2])
            return answer(true);
    }

    answer(false);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> t(n);
    std::cin >> t;

    solve(t);

    return 0;
}

