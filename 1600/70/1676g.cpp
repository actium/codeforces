#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

std::pair<int, unsigned> count(const std::vector<std::vector<size_t>>& tree, size_t i, const std::string& s)
{
    std::pair<int, unsigned> r = {};
    for (const size_t j : tree[i]) {
        const std::pair<int, unsigned> t = count(tree, j, s);
        r.first += t.first;
        r.second += t.second;
    }

    r.first += (s[i] == 'W' ? 1 : -1);
    r.second += (r.first == 0);
    return r;
}

void solve(const std::vector<unsigned>& p, const std::string& s)
{
    const size_t n = p.size();

    std::vector<std::vector<size_t>> tree(1 + n);
    for (size_t i = 0; i < n; ++i)
        tree[p[i]-1].push_back(1 + i);

    const std::pair<int, unsigned> q = count(tree, 0, s);
    answer(q.second);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n-1);
    std::cin >> p;

    std::string s;
    std::cin >> s;

    solve(p, s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
