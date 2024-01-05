#include <Lane.hpp>
#include <Game.hpp>

Lane::Lane(LaneType laneType, int id, Game* game)
    : m_laneType(laneType)
    , m_index(id)
    , m_game(game)
{

}

LaneType Lane::getLaneType() const
{
    return m_laneType;
}

int Lane::getIndex() const
{
    return m_index;
}

Game* Lane::getGame() const
{
    return m_game;
}

std::vector<bool> Lane::getSafeIndexes() const
{
    return m_safeIndexes;
}

std::vector<bool> Lane::calculateSafeIndexes(std::vector<bool> allowedIndexes, std::vector<bool> lastSafeIndexes)
{
    std::vector<bool> safeIndexes(allowedIndexes.size(), false);
    if(lastSafeIndexes.size() == 0)
    {
        return safeIndexes;
    }

    std::function<void(int, std::vector<bool>&)> DFS = [&](int index, std::vector<bool>& safeIndexes)
    {
        if (index < 0 || index >= safeIndexes.size())
            return;
        if (safeIndexes[index] == true)
            return;
        if (allowedIndexes[index] == false)
            return;
        safeIndexes[index] = true;
        DFS(index - 1, safeIndexes);
        DFS(index + 1, safeIndexes);
    };

    for (int i = 0; i < lastSafeIndexes.size(); ++i)
    {
        if (lastSafeIndexes[i] == true)
        {
            DFS(i, safeIndexes);
        }
    }

    return safeIndexes;
}

bool Lane::isLegitIndexes(std::vector<bool> indexes) const
{
    for (int i = 0; i < indexes.size(); ++i)
    {
        if (indexes[i] == true)
            return true;
    }
    return false;
}

void Lane::loadFromFile(std::istream& in)
{
    int size;
    in >> size;
    m_safeIndexes.resize(size);
    for(int i=0; i<size; ++i)
    {
        int safe;
        in >> safe;
        m_safeIndexes[i] = safe;
    }
}

std::ostream& Lane::saveToFile(std::ostream& out) const
{
    out << m_safeIndexes.size() << "\n";
    for(auto safe : m_safeIndexes)
    {
        out << safe << " ";
    }
    out << "\n";
    return out;
}