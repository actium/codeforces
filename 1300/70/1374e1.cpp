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

struct Book {
    unsigned t;
    unsigned a;
    unsigned b;
};

std::istream& operator >>(std::istream& input, Book& b)
{
    return input >> b.t >> b.a >> b.b;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::vector<Book>& b, size_t k)
{
    std::vector<unsigned> t[3];
    for (const Book& q : b) {
        if (q.a == 0 && q.b == 0)
            continue;

        if (q.a == 0 || q.b == 0)
            t[q.b].push_back(q.t);
        else
            t[2].push_back(q.t);
    }

    for (size_t i = 0; i < 2; ++i)
        std::sort(t[i].begin(), t[i].end());

    for (auto it = t[0].begin(), jt = t[1].begin(); it != t[0].end() && jt != t[1].end(); ++it, ++jt)
        t[2].push_back(*it + *jt);

    if (t[2].size() < k)
        return no_answer();

    std::sort(t[2].begin(), t[2].end());

    unsigned s = 0;
    for (size_t i = 0; i < k; ++i)
        s += t[2][i];

    answer(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, k;
    std::cin >> n >> k;

    std::vector<Book> b(n);
    std::cin >> b;

    solve(b, k);

    return 0;
}
