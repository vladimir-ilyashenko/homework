const int win_patterns[8][3][2] = {
                                    {{1,1},{2,2},{3,3}},
                                    {{1,3},{2,2},{3,1}},
                                    {{1,1},{1,2},{1,3}},
                                    {{2,1},{2,2},{1,3}},
                                    {{3,1},{3,2},{3,3}},
                                    {{1,1},{2,1},{3,1}},
                                    {{1,2},{2,2},{3,2}},
                                    {{1,3},{2,3},{3,3}}
};

bool check_win_condition(int *board, int tic_or_tac) {
  for (int i=0;i<8;i++) { // for each win condition
    int win=0;
    for (int j=0;j<3;j++) { // for each field in win condition
      for (int k=0; k<9;k++) { // check each field in board
        if (board[k][1] == win_patterns[i][j][1] && // X in win_pattern match with X on field and
            board[k][2] == win_patterns[i][j][2] && // Y in win_pattern match with Y in field and
            board[k][3] == tick_or_tac // sign in field matches
            ) { 
                win++;
                break;
              }
      }
      if (win<=j) { // if one of fields in row is not populated this win condition fails
        break;
      }
      if (win==3) { // if all thre fields in row are filled condition succeeds
        return true;
      }
    }
  }
  return false;
}

int* add_new_win(int *wins,int *wins_size) {
  int *p = new int [++*wins_size];
  for (int i =0;i<*wins_size-1; i++){
     p[i] = wins[i];
  }
  p [*wins_size - 1 ] = 1;
  delete [] array;
  return p;
}

int* find_wins_amount(int *board, int tic_or_tac) {
  int wins_size = 0;
  int *wins = new int[wins_size]; // array to count win paths
  for (int i=0;i<9;i++) { // for each field on board
    if (board[i][3]==-1) { // if field is empty
      board[i][3] = tic_or_tac; // set field
      if (check_win_condition(board, tic_or_tac)) { // if this move wins
        wins = add_new_win(wins, &wins_size); // add 1 to wins array (which means there is one move to win)
      } else { // if move does not win immidiately
        int wins_temp = new int[0];
        wins_temp = find_wins_amount(board, tic_or_tac, ); // use recursion to get array of wins reachable from this move
        for (int j=0;j<sizeof(wins_temp;j++)) { // for each win received from subsequent call
          wins_temp[j]++; // increase number of moves to win
        }
        wins = merge_arrays(wins, &wins_size, wins_temp); // add wins reacheble from this move to total wins array
      }
    }
    board[i][3] = -1; // clean field
  }
  return wins;
}

bool check_for_draw(int *board) {

  int *wins_tic = new int[0];
  int wins_tic_size = 0;
  wins_tic = find_wins_amount(board, 1, wins_tic, &wins_tic_size);

  int *wins_tac = new int[0];
  int wins_tac_size = 0;
  wins_tac = find_wins_amount(board, 1, wins_tac, &wins_tac_size);

  if ( wins_tic_size == 0 && wins_tac_size == 0) {
    return true;
  }
  return false;
}

int* merge_arrays(int *wins, int *wins_size, *wins_temp) {
  int new_wins = new int[*wins_size];

  for (int i=0;i<sizeof(wins_temp);i++){ // for each element in second array
    (*wins_size)++; // increase size of first array
    new_wins[(*wins_size)++] = wins_temp[i]; // add element from second array to first
  }

  delete [] wins;
  return new_wins;
}

void game( int user_choice, int *board[][3]) {
  for
  if (check_for_draw(board[][3])) {
    //draw();
    exit 0;
  } else if (check_win_condition(board, user_choice)) {
    user_win()//
    exit 0;
  } else if (check)
  for (int i=0; i<9; i++) {
    int *wins = new int[0];
  }



}

int main() {
  int board = new int[9][3];
  board = { // initialize board
    {1,1,-1},
    {1,2,-1},
    {1,3,-1},
    {2,1,-1},
    {2,2,-1},
    {2,3,-1},
    {3,1,-1},
    {3,2,-1},
    {3,3,-1}
  };

  //int user_choice = select_sign(); // User selects tic or tac
  //int user_choice = menu() // select tic or tac
  //game(user_chice, board)

}
