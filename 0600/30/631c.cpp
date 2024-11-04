#include <algorithm>
#include <deque>
#include <iostream>
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

void answer(const std::vector<int>& v)
{
    const char* separator = "";
    for (const int x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(std::vector<int>& a, const std::vector<std::pair<unsigned, unsigned>>& s)
{
    std::vector<std::pair<unsigned, unsigned>> q;
    for (const auto& e : s) {
        while (!q.empty() && e.second > q.back().second)
            q.pop_back();

        q.push_back(e);
    }

    q.emplace_back(0, 0);   // sentinel

    std::deque<int> t(a.begin(), a.begin() + q[0].second);
    std::sort(t.begin(), t.end());

    for (size_t i = 0; i + 1 < q.size(); ++i) {
        const size_t r = q[i].second, k = r - q[i+1].second;

        if (q[i].first == 1) {
            for (size_t j = 0; j < k; ++j) {
                a[r-1-j] = t.back();
                t.pop_back();
            }
        } else {
            for (size_t j = 0; j < k; ++j) {
                a[r-1-j] = t.front();
                t.pop_front();
            }
        }
    }

    answer(a);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    std::cin >> a;

    std::vector<std::pair<unsigned, unsigned>> s(m);
    std::cin >> s;

    solve(a, s);

    return 0;
}
