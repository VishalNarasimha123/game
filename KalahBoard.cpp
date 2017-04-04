//add code here
//#include"GameTree.cpp"
#include<iostream>
#include<iomanip>
using namespace std;

class KalahBoard
{
public:
    int A[6],B[6];
    int kalah_A,kalah_B;
    int *ptr;
    int numberOfSlots;
    KalahBoard()
    {
        for(int i = 0 ; i < 6; i++)
        {
            A[i] = 6;
            B[i] = 6;
        }
        kalah_A = 0,kalah_B = 0;
        numberOfSlots = 6;
        ptr = NULL;
    }

    void displayBoard()
    {
        cout << endl;
        cout << "\t\tA PLAYER";
        cout << endl;
        // First Line
        cout << "\t";
        for(int i = 0 ; i < 25; i++)
        {
            cout << "-";
        }
        //Second Line
        cout << endl;
        cout << "\t" << "|";
        cout << setw(2);

        for(int i = 5 ; i >= 0 ; i--)
        {
            cout << A[i] << setw(2) << "|";
            cout << " ";
        }
        cout << endl;
        cout << "------";  //Third Line
        cout << "\t\t\t\t   ------";
        cout << endl;
        cout <<"|" << setw(3) << kalah_A << " |"; // Fourth Line
        cout <<"\t\t\t\t   |" << setw(3) << kalah_B << " |"; // Fourth Line
        cout << endl;
        // Fifth Line
        cout << "\t";
        for(int i = 0 ; i < 25; i++)
        {
            cout << "-";
        }
        cout << endl;
        //Sixth Line
        cout << "\t" << "|";
        cout << setw(2);

        for(int i = 0 ; i < 6; i++)
        {
            cout << B[i] << setw(2) << "|";
            cout << " ";
        }
        cout << endl;
        cout << "\t\tB PLAYER";
        cout << endl << endl << endl << endl;
    }

    char move_A(int hole_number)
    {
        int tempPos = hole_number;
        ptr = A;
        int numberOfStones = ptr[tempPos];
        ptr[hole_number] = 0;
        int opponentPos, opponentStones;

        while(numberOfStones > 0)
        {
            if(tempPos >= 0 && tempPos < 5)
            {
                if(numberOfStones == 1)
                {
                    numberOfStones--;
                    tempPos++;
                    if(ptr[tempPos] == 0)
                    {
                        opponentPos = numberOfSlots - tempPos;
                        ptr = B;
                        opponentStones = ptr[opponentPos];
                        ptr[opponentPos] = 0;
                        kalah_A += opponentStones + 1;
                        return 'B';
                    }
                    else
                    {
                        ptr[tempPos] += 1;
                        return 'B';
                    }
                }
                else
                {
                    tempPos++;
                    numberOfStones--;
                    ptr[tempPos]+=1;
                }
            }
            else if(tempPos == 5 && numberOfStones >= 1)
            {
                tempPos++;
                numberOfStones--;
                kalah_A += 1;
                if(numberOfStones == 0)
                    return 'A';
            }
            else if(tempPos >= 6 && tempPos < 12)
            {
                ptr = B;
                tempPos++;
                numberOfStones--;
                ptr[tempPos-7] += 1;
            }
            else if(tempPos >= 12)
            {
                tempPos = tempPos % 12;
                ptr = A;
                ptr[tempPos]+=1;
                numberOfStones--;
            }
        }
    }

    char move_B(int hole_number)
    {
        int tempPos = hole_number;
        ptr = B;
        int numberOfStones = ptr[tempPos];
        ptr[hole_number] = 0;
        int opponentPos, opponentStones;

        while(numberOfStones > 0)
        {
            if(tempPos >= 0 && tempPos < 5)
            {
                if(numberOfStones == 1)
                {
                    numberOfStones--;
                    tempPos++;
                    if(ptr[tempPos] == 0)
                    {
                        opponentPos = numberOfSlots - tempPos;
                        ptr = A;
                        opponentStones = ptr[opponentPos];
                        ptr[opponentPos] = 0;
                        kalah_B += opponentStones + 1;
                        return 'A';
                    }
                    else
                    {
                        ptr[tempPos] += 1;
                        return 'A';
                    }
                }
                else
                {
                    tempPos++;
                    numberOfStones--;
                    ptr[tempPos]+=1;
                }
            }
            else if(tempPos == 5 && numberOfStones >= 1)
            {
                tempPos++;
                numberOfStones--;
                kalah_B += 1;
                if(numberOfStones == 0)
                    return 'B';
            }
            else if(tempPos >= 6 && tempPos < 12)
            {
                ptr = A;
                tempPos++;
                numberOfStones--;
                ptr[tempPos-7] += 1;
            }
            else if(tempPos >= 12)
            {
                tempPos = tempPos % 12;
                ptr = B;
                ptr[tempPos]+=1;
                numberOfStones--;
            }
        }
    }

    void move(int hole_number,char player)
    {
        if(player == 'A')
            move_A(hole_number);
        else
            move_B(hole_number);
    }

    int evaluation()
    {

    }

    bool deep_enough(GameTree *node)
    {
        if(1)//check if the current node is quiscent
        {
            return true;
        }
        else
        {
            node.add_all_childern();
            return false;
        }
    }

    bool checkWin()
    {

    }

    void operator=(KalahBoard kb)
    {
        for(int i=0;i<6;i++)
        {
            A[i]=kb.A[i];
            B[i]=kb.B[i];
            kalah_A=kb.kalah_A;
            kalah.B=kbp.kalah_B;
        }
    }
};
