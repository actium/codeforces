#include <iostream>
#include <vector>

struct Query {
    std::string r;
    int x;
    char a;
};

std::istream& operator >>(std::istream& input, Query& v)
{
    return input >> v.r >> v.x >> v.a;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(int x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << "Impossible" << '\n';
}

void solve(const std::vector<Query>& q)
{
    std::pair<int, int> r = { -2000000000, 2000000000 };
    for (const Query& x : q) {
        if (x.r == ">") {
            if (x.a == 'Y') r.first = std::max(r.first, x.x + 1);
            else r.second = std::min(r.second, x.x);
        }
        if (x.r == ">=") {
            if (x.a == 'Y') r.first = std::max(r.first, x.x);
            else r.second = std::min(r.second, x.x - 1);
        }
        if (x.r == "<") {
            if (x.a == 'Y') r.second = std::min(r.second, x.x - 1);
            else r.first = std::max(r.first, x.x);
        }
        if (x.r == "<=") {
            if (x.a == 'Y') r.second = std::min(r.second, x.x);
            else r.first = std::max(r.first, x.x + 1);
        }
    }

    if (r.first <= r.second)
        return answer(r.first);

    no_answer();
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<Query> q(n);
    std::cin >> q;

    solve(q);

    return 0;
}
