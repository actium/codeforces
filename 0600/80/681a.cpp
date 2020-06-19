#include <iostream>
#include <string>
#include <vector>

struct P {
    std::string name;
    int before;
    int after;
};

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<P>& p)
{
    for (const P& x : p) {
        if (x.before >= 2400 && x.after > x.before)
            return answer(true);
    }

    answer(false);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<P> p(n);
    for (size_t i = 0; i < n; ++i)
        std::cin >> p[i].name >> p[i].before >> p[i].after;

    solve(p);

    return 0;
}

