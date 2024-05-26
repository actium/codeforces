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

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

struct Query {
    unsigned t;
    unsigned i;
};

std::istream& operator >>(std::istream& input, Query& q)
{
    input >> q.t;
    return q.t == 3 ? input : input >> q.i;
}

void solve(const std::vector<std::vector<unsigned>>& a, const std::vector<Query>& r)
{
    const size_t n = a.size();

    unsigned v = 0;
    for (size_t i = 0; i < n; ++i)
        v ^= a[i][i];

    std::string s;
    for (const Query& q : r) {
        if (q.t == 1 || q.t == 2)
            v ^= 1;
        else
            s.push_back('0' + v);
    }

    answer(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<std::vector<unsigned>> a(n, std::vector<unsigned>(n));
    std::cin >> a;

    size_t q;
    std::cin >> q;

    std::vector<Query> r(q);
    std::cin >> r;

    solve(a, r);

    return 0;
}
