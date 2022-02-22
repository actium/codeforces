#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Event {
    unsigned t;
    int l;
    int h;
};

std::istream& operator >>(std::istream& input, Event& v)
{
    return input >> v.t >> v.l >> v.h;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::vector<Event>& e, int m)
{
    int t = 0, lb = m, ub = m;
    for (const Event& x : e) {
        const int d = x.t - t;
        if (x.h < lb - d || ub + d < x.l)
            return answer(false);

        t = x.t;
        lb = std::max(lb - d, x.l);
        ub = std::min(ub + d, x.h);
    }

    answer(true);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    int m;
    std::cin >> m;

    std::vector<Event> e(n);
    std::cin >> e;

    solve(e, m);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
