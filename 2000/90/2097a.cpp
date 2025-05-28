#include <iostream>
#include <map>
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

void solve(const std::vector<unsigned>& a)
{
    std::map<unsigned, unsigned> f;
    for (const unsigned x : a) {
        if (++f[x] == 4)
            return answer(true);
    }

    for (auto it = f.begin(); it != f.end(); ++it) {
        if (it->second < 2)
            continue;

        auto jt = std::next(it);
        while (jt != f.end() && jt->first == it->first + 1 && jt->second == 1)
            it = jt++;

        if (jt != f.end() && jt->first == it->first + 1)
            return answer(true);
    }

    answer(false);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
