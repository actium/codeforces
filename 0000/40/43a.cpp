#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

int main()
{
    size_t n;
    std::cin >> n;

    std::string team_names[2];
    unsigned first_team_score = 0;
    for (size_t i = 0; i < n; ++i) {
        std::string team_name;
        std::cin >> team_name;

        if (team_names[0].empty())
            team_names[0] = team_name;

        if (team_name == team_names[0])
            ++first_team_score;
        else if (team_names[1].empty())
            team_names[1] = team_name;
    }

    answer(first_team_score > n - first_team_score ? team_names[0] : team_names[1]);

    return 0;
}

