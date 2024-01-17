#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::string& x)
{
    std::cout << "YES" << '\n';
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(const std::vector<unsigned>& s)
{
    const size_t n = s.size();

    std::vector<size_t> p[100];
    for (size_t i = 0; i < n; ++i)
        p[s[i]-1].push_back(i);

    std::vector<size_t> q[2];
    for (size_t i = 0; i < 100; ++i) {
        if (p[i].size() == 1)
            q[0].push_back(p[i][0]);

        if (p[i].size() > 2)
            q[1].push_back(p[i][0]);
    }

    if (q[0].size() % 2 == 1 && q[1].empty())
        return no_answer();

    std::string t(n, 'A');
    for (size_t i = 1; i < q[0].size(); i += 2)
        t[q[0][i]] = 'B';

    if (q[0].size() % 2 == 1)
        t[q[1][0]] = 'B';

    answer(t);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> s(n);
    std::cin >> s;

    solve(s);

    return 0;
}
