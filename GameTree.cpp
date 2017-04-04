#include"KalahBoard.cpp"
class GameTree
{
    int heuristic_value;
    char player;
    KalahBoard board_status;
    int number_of_children;
    GameTree *children[6];
    GameTree()
    {
        heuristic_value = 0;
        number_of_children = 0;
        for(int i=0;i<6;i++)
        {
            children[i] = NULL;
        }
    }
    GameTree* create_node()
    {
        children[number_of_children++]=new GameTree();
    }
    void set_heuristic_value(int value)
    {
        heuristic_value = value;
    }
    void add_all_childern()
    {
        char p = (player == 'A') ? 'B' : 'A';
        for(int i=0;i<6;i++)
        {
            create_node();
            childern[i].player = p;
            children[i].board_status.move(i,children[i].player);
        }
    }
};