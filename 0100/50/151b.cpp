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

void solve(const std::vector<std::pair<std::string, std::vector<std::string>>>& f)
{
    std::pair<unsigned, std::vector<std::string>> b[3];
    b[0].first = b[1].first = b[2].first = 0;

    for (const auto& [name, phones] : f) {
        unsigned c[3] = {};
        for (const auto& p : phones) {
            if (p[0] == p[1] && p[1] == p[3] && p[3] == p[4] && p[4] == p[6] && p[6] == p[7]) {
                ++c[0];
                continue;
            }
            if (p[0] > p[1] && p[1] > p[3] && p[3] > p[4] && p[4] > p[6] && p[6] > p[7]) {
                ++c[1];
                continue;
            }
            ++c[2];
        }
        for (size_t i = 0; i < 3; ++i) {
            if (c[i] > b[i].first) {
                b[i].second.clear();
                b[i].first = c[i];
            }
            if (b[i].first == c[i])
                b[i].second.push_back(name);
        }
    }

    std::cout << "If you want to call a taxi, you should call: ";
    for (size_t i = 0, k = b[0].second.size(); i < k; ++i)
        std::cout << b[0].second[i] << (i+1 < k ? ", " : ".\n");

    std::cout << "If you want to order a pizza, you should call: ";
    for (size_t i = 0, k = b[1].second.size(); i < k; ++i)
        std::cout << b[1].second[i] << (i+1 < k ? ", " : ".\n");

    std::cout << "If you want to go to a cafe with a wonderful girl, you should call: ";
    for (size_t i = 0, k = b[2].second.size(); i < k; ++i)
        std::cout << b[2].second[i] << (i+1 < k ? ", " : ".\n");
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<std::string, std::vector<std::string>>> f(n);
    for (size_t i = 0; i < n; ++i) {
        size_t s;
        std::cin >> s >> f[i].first;

        f[i].second.resize(s);
        std::cin >> f[i].second;
    }

    solve(f);

    return 0;
}

