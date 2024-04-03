#include <iostream>
#include <queue>
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

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(size_t n, const std::vector<std::pair<unsigned, unsigned>>& r)
{
    std::vector<std::pair<unsigned, bool>> q;
    std::vector<std::queue<unsigned>> p(1 + n);

    unsigned b = 0, k = 0;
    for (const std::pair<unsigned, unsigned>& e : r) {
        switch (e.first) {
            case 1:
                p[e.second].push(q.size());
                q.emplace_back(e.second, true);
                ++k;
                break;

            case 2:
                while (!p[e.second].empty()) {
                    const unsigned x = p[e.second].front();
                    p[e.second].pop();
                    q[x].second = false;
                    --k;
                }
                break;

            case 3:
                while (b < e.second) {
                    if (q[b].second) {
                        p[q[b].first].pop();
                        --k;
                    }
                    ++b;
                }
                break;
        }

        answer(k);
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, q;
    std::cin >> n >> q;

    std::vector<std::pair<unsigned, unsigned>> r(q);
    std::cin >> r;

    solve(n, r);

    return 0;
}
