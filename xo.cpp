#include <iostream>
#include <array>
using namespace std;
array<array<char,3>,3> game_input(array<array<char,3>,3>&game,char player){
    int i,j;
    cout<<"Please give the address of "<<player<<endl;
    cout<<"Give the address i: ";
    cin>>i;
    cout<<"Give the address j: ";
    cin>>j;

    //Check validity of input
    if (i < 0 || i > 2 || j < 0 || j > 2) {
        cout << "Invalid input! Please enter values between 0 and 2." << endl;
        return game_input(game, player);
    }

    //Check where to put and if cell is empty 
    if (game[i][j]==' '){
        game[i][j] = player;        //X or O depending on whose turn it is!
    }
    else{
        //Recursion prevents using same cell over writing. 
        cout<<"Cell is occupied pls try different one!"<<endl;
        return game_input(game,player);
    }   
    return game;
}
void print(array<array<char,3>,3>&game_board){
    //GAME BOARD
    for (int i = 0; i < 3;i++ ){
        cout << "  " << game_board[i][0] << " | " << game_board[i][1] << " | " << game_board[i][2] << endl;
        if (i < 2) cout << " ---+---+---" << endl;
    }

}
char game_status(array<array<char,3>,3>&game_board){
    //Row check!
    for (int i = 0; i < 3; i++)
    {   
        if (game_board[i][0]==game_board[i][1]&&game_board[i][1]==game_board[i][2]&&game_board[i][0]!=' ')
        {   
            return game_board[i][0];
        }
        
    }
    //Column 
    for (int i=0;i < 3;i++){
            if (game_board[0][i]==game_board[1][i]&&game_board[1][i]==game_board[2][i]&&game_board[0][i]!=' ')
            {   
                return game_board[0][i];   
            }
        }
    //Diagonal check
    if (game_board[0][0]==game_board[1][1]&&game_board[1][1]==game_board[2][2]&&game_board[0][0]!=' ')
    {       
            return game_board[1][1];
    }
    //Anti diagonal check
    if (game_board[0][2]==game_board[1][1]&&game_board[1][1]==game_board[2][0]&&game_board[0][2]!=' ')
    {
        return game_board[1][1];
    }
    //no winner yet!!!
    return '-';
}
bool winner(char answer){
    if (answer == 'X')
        {
            cout<<"====================="<<endl;
            cout<<"Congratulations!!! X wins"<<endl;
            cout<<"====================="<<endl;
            return false;
        }
    else if (answer == 'O')
        {
            cout<<"====================="<<endl;
            cout<<"Congratulations!!! O wins"<<endl;
            cout<<"====================="<<endl;
            return false;
        }
        //TODO: Think once more how u can deal with this one to find draw
    else{
            cout<<"Game is still going on!"<<endl;
            cout<<endl<<endl;
            return true;
        }

}
bool is_board_full(array<array<char,3>,3>&game_board){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (game_board[i][j] != 'X' && game_board[i][j] != 'O')
            {
                //That means there is an empty space!
                return false;
            }
            
        }
        
    }
    cout<<"====================="<<endl;
    cout<<"No one wins, It is draw!!!"<<endl;
    cout<<"====================="<<endl;
    return true;
}
int main(){
    cout<<"======Welcome to Tic Tac Toe Game!!!=========="<<endl;
    bool game = true;
    array<array<char,3>,3> game_board = {{
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}}
    };
    char answer; 
    print(game_board);    
    while (game)
    {
        game_input(game_board,'X');
        print(game_board);
        answer = game_status(game_board);
        game = winner(answer);
        if (game == false)
        {
            break;
        }
        bool draw = is_board_full(game_board);
        if (draw == true)
        {   
            break;
        }
        game_input(game_board,'O');
        answer = game_status(game_board);
        game = winner(answer);
        print(game_board);
        draw = is_board_full(game_board);
        if (draw == true)
        {
            break;
        }
        
    }
    return 0;
}