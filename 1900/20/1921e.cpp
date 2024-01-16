#include <iostream>

using position_t = std::pair<unsigned, unsigned>;

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

void answer(const char* x)
{
    std::cout << x << '\n';
}

void solve(unsigned h, unsigned w, const position_t& a, const position_t& b)
{
    if (a.first >= b.first)
        return answer("Draw");

    const unsigned dy = b.first - a.first - 1;
    if (dy % 2 == 0) {
        if (a.second < b.second) {
            const unsigned dx = w - b.second;
            answer(a.second + dy / 2 + 1 >= b.second + std::min(dy / 2, dx) ? "Alice" : "Draw");
        } else {
            const unsigned dx = b.second - 1;
            answer(a.second + std::min(dy / 2, dx) <= b.second +  dy / 2 + 1 ? "Alice" : "Draw");
        }
    } else {
        if (a.second < b.second) {
            const unsigned dx = a.second - 1;
            answer(a.second + (dy + 1) / 2 < b.second + std::min((dy + 1) / 2, dx) ? "Draw" : "Bob");
        } else {
            const unsigned dx = w - a.second;
            answer(a.second + std::min((dy + 1) / 2, dx) > b.second + (dy + 1) / 2 ? "Draw" : "Bob");
        }
    }
}

void test_case()
{
    unsigned h, w;
    std::cin >> h >> w;

    position_t a, b;
    std::cin >> a >> b;

    solve(h, w, a, b);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
