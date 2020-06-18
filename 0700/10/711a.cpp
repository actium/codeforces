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

void answer(const std::vector<std::string>& v)
{
    for (const std::string& s : v)
        std::cout << s << '\n';
}

void solve(const std::vector<std::string>& c)
{
    const size_t n = c.size();

    for (size_t i = 0; i < n; ++i) {
        const std::string& s = c[i];
        if (s[0] == 'O' && s[1] == 'O') {
            std::vector<std::string> solution = c;
            solution[i][0] = solution[i][1] = '+';
            solution.insert(solution.begin(), "YES");
            return answer(solution);
        }
        if (s[3] == 'O' && s[4] == 'O') {
            std::vector<std::string> solution = c;
            solution[i][3] = solution[i][4] = '+';
            solution.insert(solution.begin(), "YES");
            return answer(solution);
        }
    }

    answer({ "NO" });
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::string> c(n);
    std::cin >> c;

    solve(c);

    return 0;
}

