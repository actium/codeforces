#include <algorithm>
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

void solve(std::vector<unsigned>& a, unsigned m, unsigned k)
{
    std::sort(a.begin(), a.end());

    unsigned d = 0;
    {
        std::list<unsigned> q;
        for (const unsigned t : a) {
            while (!q.empty() && q.front() + m <= t)
                q.pop_front();

            if (q.size() + 1 < k) {
                q.push_back(t);
            } else {
                ++d;
            }
        }
    }
    answer(d);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned m, k;
    std::cin >> m >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, m, k);

    return 0;
}
