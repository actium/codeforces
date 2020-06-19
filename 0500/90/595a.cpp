#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::vector<char>>& w)
{
    size_t count = 0;
    for (const std::vector<char>& floor : w) {
        for (size_t i = 0; i < floor.size(); i += 2) {
            if (floor[i] == '1' || floor[i+1] == '1')
                ++count;
        }
    }

    answer(count);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<char>> w(n, std::vector<char>(2 * m));
    std::cin >> w;

    solve(w);

    return 0;
}

