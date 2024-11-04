#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

unsigned count(std::vector<std::vector<size_t>> q, size_t x, size_t m)
{
    const size_t n = q.size();

    unsigned k = 0;
    {
        std::set<size_t> p;
        while (true) {
            if (!q[x%n].empty()) {
                for (size_t& t : q[x%n]) {
                    while (t < x)
                        t += n;
                }

                const auto it = std::max_element(q[x%n].begin(), q[x%n].end());
                p.insert(*it);

                *it = q[x%n].back();
                q[x%n].pop_back();

                --m;
            }

            p.erase(x);

            if (p.empty() && m == 0)
                break;

            ++x;
            ++k;
        }
    }
    return k;
}

void solve(size_t n, const std::vector<std::pair<unsigned, unsigned>>& c)
{
    std::vector<std::vector<size_t>> q(n);
    for (const auto& [a, b] : c)
        q[a-1].push_back(b-1);

    std::vector<unsigned> d(n);
    for (size_t i = 0; i < n; ++i)
        d[i] = count(q, i, c.size());

    answer(d);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::pair<unsigned, unsigned>> c(m);
    std::cin >> c;

    solve(n, c);

    return 0;
}
