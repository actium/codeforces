#include <iostream>
#include <set>
#include <string>
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

void solve(const std::vector<std::string>& s)
{
    std::set<std::string> q[3];
    for (const std::string& t : s) {
        if (t.front() == t.back())
            return answer(true);

        const std::string r(t.rbegin(), t.rend());

        if (t.length() == 2) {
            if (q[0].count(r) != 0 || q[2].count(r) != 0)
                return answer(true);

            q[0].insert(t);
        } else {
            if (q[1].count(r) != 0 || q[0].count(r.substr(0, 2)) != 0)
                return answer(true);

            q[1].insert(t);
            q[2].insert(t.substr(0, 2));
        }
    }

    answer(false);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::string> s(n);
    std::cin >> s;

    solve(s);
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
