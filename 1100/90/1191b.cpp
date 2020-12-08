#include <algorithm>
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

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(std::vector<std::string>& t)
{
    std::sort(t.begin(), t.end(),
        [](const std::string& a, const std::string& b) {
            return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
        }
    );

    if (t[0][1] == t[1][1] || t[1][1] == t[2][1]) {
        const auto d1 = (t[0][1] == t[1][1] ? t[1][0] - t[0][0] : 10);
        const auto d2 = (t[1][1] == t[2][1] ? t[2][0] - t[1][0] : 10);

        if (d1 < 2 && d2 == d1)
            return answer(0);

        if (d1 < 3 || d2 < 3)
            return answer(1);
    }

    answer(2);
}

int main()
{
    std::vector<std::string> t(3);
    std::cin >> t;

    solve(t);

    return 0;
}

