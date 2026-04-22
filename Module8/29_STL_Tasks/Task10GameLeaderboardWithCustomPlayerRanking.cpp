#include <iostream>
#include <map>
#include <string>

struct PlayerStats
{
    std::string playerId;
    std::string playerName;
    int score;

    PlayerStats(const std::string &id, const std::string &name, int playerScore)
        : playerId(id), playerName(name), score(playerScore)
    {
    }
};

struct PlayerRankComparator
{
    bool operator()(const PlayerStats &p1, const PlayerStats &p2) const
    {
        // Primary sort: higher score should rank first.
        if (p1.score != p2.score)
        {
            return p1.score > p2.score;
        }

        // Secondary sort: alphabetical name order (A-Z).
        if (p1.playerName != p2.playerName)
        {
            return p1.playerName < p2.playerName;
        }

        // Tertiary sort: ID order for strict weak ordering.
        return p1.playerId < p2.playerId;
    }
};

int main()
{
    std::map<PlayerStats, bool, PlayerRankComparator> leaderboard;

    leaderboard.insert({PlayerStats("P001", "Alice", 1500), true});
    leaderboard.insert({PlayerStats("P003", "Charlie", 1200), true});
    leaderboard.insert({PlayerStats("P002", "Bob", 1500), true});
    leaderboard.insert({PlayerStats("P005", "David", 1800), true});
    leaderboard.insert({PlayerStats("P004", "Alice", 1000), true});
    leaderboard.insert({PlayerStats("P007", "Emily", 1200), true});
    leaderboard.insert({PlayerStats("P006", "Bob", 1500), true});

    std::cout << "--- Game Leaderboard (Custom Ranking) ---\n";
    int rank = 1;

    for (const auto &entry : leaderboard)
    {
        const PlayerStats &player = entry.first;
        std::cout << "Rank " << rank << ": "
                  << "ID: " << player.playerId
                  << ", Name: " << player.playerName
                  << ", Score: " << player.score << "\n";
        ++rank;
    }

    return 0;
}
