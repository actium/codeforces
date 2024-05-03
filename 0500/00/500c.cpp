#include <iostream>
#include <list>
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

void solve(const std::vector<unsigned>& w, const std::vector<unsigned>& b)
{
    unsigned s = 0;

    std::list<unsigned> q;
    for (const unsigned x : b) {
        auto it = q.begin();
        while (it != q.end() && *it != x) {
            s += w[*it-1];
            ++it;
        }

        if (it != q.end())
            q.erase(it);

        q.push_front(x);
    }

    answer(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> w(n), b(m);
    std::cin >> w >> b;

    solve(w, b);

    return 0;
}
