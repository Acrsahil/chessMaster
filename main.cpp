#include <bits/stdc++.h>
#include <string>
using namespace std;

#define F(i, n) for (int i = 0; i < n; i++)
#define vi vector<int>
#define ln long long int
#define test int t; cin >> t; while (t--)
#define ll long long

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " -> "; _print(x); cerr << endl
#else
#define debug(x)
#endif

void _print(int a) { cerr << a << " "; }
void _print(long long a) { cerr << a << " "; }
void _print(char a) { cerr << a << " "; }
void _print(string a) { cerr << a << " "; }
void _print(bool a) { cerr << a << " "; }
template <class T, class V> void _print(pair<T, V> p) { cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}"; }
template <class T> void _print(vector<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(set<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(multiset<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(map<T, V> v) { cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(pair<T, T> p) { cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}"; }
template <class T, class V> void _print(multimap<T, V> v) { cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(unordered_set<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T> void _print(unordered_multiset<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print(unordered_map<T, V> v) { cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]"; }

vector<vector<string>> board(8,vector<string>(8));


class chess{

public:
  bool white_rook1_move = false;
  bool white_rook2_move = false;

  bool black_rook1_move = false;
  bool black_rook2_move = false;

  map<string,string>black_piece;
  map<string,string>white_piece;
  vector<pair<string,string>> n_pawn_piece;

private:
  string findKey(map<string, string>& mp, string target) {
    for (auto &[key, value] : mp) {
        if (value == target) {
            return key;
        }
    }
    return "null"; // Not found
}

private:
int search_number_of_piece(bool white_turn,map<string,string>& mp,char piece){
  int cnt = 0;
  for(auto i : mp){
    if(i.first[0] == piece){
      cnt++;
    }
  }
  return cnt;
}


private:
void print_board(bool white_turn,vector<string> legal_moves = {""}){
  for(int i = 7; i >= 0; i--){
    for(int j = 7; j >= 0; j--){
      int is_white_piece = 1;
      string location = string(1, (char)('H' - j)) + to_string(i + 1);
      string piece = findKey( white_piece, location); // first search in white_piece
      if(piece == "null"){
        is_white_piece = 0;
        piece = findKey( black_piece, location); // search in black_piece
      } 
      if(piece == "null"){
        is_white_piece = -1;
        piece = ",";
      }

      cout << "| " << emojiOfPiece(piece,is_white_piece,legal_moves,location) << "  " ;
    }
    cout << "|"<< endl;
  }
}


private:
bool is_valid_move(int rank,char files){
  if(rank <1 || rank >8 || files < 'A' || files > 'H') return false;
  return true;
}


private:
string emojiOfPiece(string piece_notation,int white_turn, vector<string> &legal_moves,string location = ""){

  if(!location.empty()){
    for(auto i : legal_moves){
      if(i == location) return "X";
    }
  }
  // Adding White Emoji for game
  if(white_turn == 1){
    if(piece_notation[0]=='P' &&  white_piece[piece_notation] != "X") return "♙";
    else if(piece_notation[0]=='N' && white_piece[piece_notation] != "X") return "♘";
    else if(piece_notation[0]=='B' && white_piece[piece_notation] != "X") return "♗";
    else if(piece_notation[0]=='R' && white_piece[piece_notation] != "X") return "♖";
    else if(piece_notation[0]=='Q' && white_piece[piece_notation] != "X") return "♕";
    else if(piece_notation[0]=='K' && white_piece[piece_notation] != "X") return "♔";

  }else if(white_turn == 0){
    // Adding Black Emoji for game


    if(piece_notation[0]=='P' && black_piece[piece_notation] != "X") return "♟";
    else if(piece_notation[0]=='N' && black_piece[piece_notation] != "X") return "♞";
    else if(piece_notation[0]=='B' && black_piece[piece_notation] != "X") return "♝";
    else if(piece_notation[0]=='R' && black_piece[piece_notation] != "X") return "♜";
    else if(piece_notation[0]=='Q' && black_piece[piece_notation] != "X") return "♛";
    else if(piece_notation[0]=='K' && black_piece[piece_notation] != "X") return "♚";
  }

  return ".";
}




private:
vector<string> rook_valid_move(string &curr_loc, bool white_turn){
  
    vector<string> ans;
    map<string,string>search_mp = white_turn ? white_piece : black_piece;
    char col  =  curr_loc[0];
    int row = curr_loc[1]-'0'; // converting to integer
  
    int rank = row;
  char files = col;
  
    // up direction 
    
    while(rank <= 8){
      if(rank != row) ans.push_back(files + to_string(rank));
      if(findKey(search_mp,files + to_string(rank+1)) != "null") break;

        if(white_turn){
          if(findKey(black_piece,files + to_string(rank)) != "null") break;
        }else{
          if(findKey(black_piece,files + to_string(rank)) != "null") break;
        }
      rank++;
    }


  rank = row;
  files = col;
  
    // down direction 
    
    while(rank <= 8){
      if(rank != row) ans.push_back(files + to_string(rank));
      if(findKey(search_mp,files + to_string(rank-1)) != "null") break;

        if(white_turn){
          if(findKey(black_piece,files + to_string(rank)) != "null") break;
        }else{
          if(findKey(white_piece,files + to_string(rank)) != "null") break;
        }
      rank--;
    }

  rank = row;
  files = col;
  
    // right direction 
    
    while(files <= 'H'){
      if(files != col) ans.push_back(files + to_string(rank));
      if(findKey(search_mp,char(files+1) + to_string(rank)) != "null") break;

        if(white_turn){
          if(findKey(black_piece,files + to_string(rank)) != "null") break;
        }else{
          if(findKey(white_piece,files + to_string(rank)) != "null") break;
        }
      files++;
    }


  rank = row;
  files = col;
  
    // right direction 
    
    while(files >= 'A'){
      if(files != col) ans.push_back(files + to_string(rank));
      if(findKey(search_mp,char(files-1) + to_string(rank)) != "null") break;

        if(white_turn){
          if(findKey(black_piece,files + to_string(rank)) != "null") break;
        }else{
          if(findKey(white_piece,files + to_string(rank)) != "null") break;
        }
      files--;
    }

  return ans;
    
}

private:
vector<string> bisap_valid_move(string &curr_loc, bool white_turn){
  vector<string> ans;
    map<string,string>search_mp = white_turn ? white_piece : black_piece;
    char col  =  curr_loc[0];
    int row = curr_loc[1]-'0'; // converting to integer

  // right up diagonal
  int rank = row;
  char files = col;

  while(rank <= 8 && files <= 'H'){
    if(rank != row) ans.push_back(files + to_string(rank));
    if(findKey(search_mp,char(files+1) + to_string(rank+1)) != "null") break;

    if(white_turn){
      if(findKey(black_piece,files + to_string(rank)) != "null") break;
    }else{
      if(findKey(black_piece,files + to_string(rank)) != "null") break;
    }
    rank++;
    files++;
  }

  // right down diagonal
  rank = row;
  files = col;

  while(rank >= 1 && files >= 'A'){
    if(rank != row) ans.push_back(files + to_string(rank));
    if(findKey(search_mp,char(files-1) + to_string(rank-1)) != "null") break;

    if(white_turn){
      if(findKey(black_piece,files + to_string(rank)) != "null") break;
    }else{
      if(findKey(black_piece,files + to_string(rank)) != "null") break;
    }
    rank--;
    files--;
  }


  // left up diagonal
  rank = row;
  files = col;

  while(rank <= 8 && files >= 'A'){
    if(rank != row) ans.push_back(files + to_string(rank));
    if(findKey(search_mp,char(files-1) + to_string(rank+1)) != "null") break;

    if(white_turn){
      if(findKey(black_piece,files + to_string(rank)) != "null") break;
    }else{
      if(findKey(black_piece,files + to_string(rank)) != "null") break;
    }
    rank++;
    files--;
  }


  // right down diagonal
  rank = row;
  files = col;

  while(rank >= 1 && files <= 'H'){
    if(rank != row) ans.push_back(files + to_string(rank));
    if(findKey(search_mp,char(files+1) + to_string(rank-1)) != "null") break;

    if(white_turn){
      if(findKey(black_piece,files + to_string(rank)) != "null") break;
    }else{
      if(findKey(black_piece,files + to_string(rank)) != "null") break;
    }
    rank--;
    files++;
  }



  return ans;
}

private:
vector<string> queen_valid_move(string &curr_loc,bool white_turn){
  vector<string> ans = rook_valid_move(curr_loc,white_turn), ans2 = bisap_valid_move(curr_loc,white_turn);
  ans.insert(ans.end(),ans2.begin(),ans2.end());
  return ans;
}

private: 
bool is_eligiable_loc(int rank,char files,bool white_turn){
  string next_loc = files+to_string(rank);
  if(white_turn){
    if(findKey(white_piece,next_loc) == "null") return true;
  }else{
    if(findKey(black_piece,next_loc) == "null") return true;
  }
  return false;
}


string pawn_contains_n_pawn(string &choose_location){
  for(auto i : n_pawn_piece){
    debug(i);
    if(i.second == choose_location) return i.first;
  }
  return "null";
}

int cnt_piece_move_history(vector<pair<string,string>> &move_history,string &last_piece,bool &white_turn){
  int cnt = 0;
  for(int i = 0; i<move_history.size(); i++){
    // if white_turn -> 1 odd if
    // if white_turn -> 0 even if
    if(i+(white_turn)&1 && last_piece == move_history[i].first) cnt++; 
  }
  return cnt;
}





string n_pawn_move(vector<pair<string,string>> &move_history , bool &white_turn, string &press_piece_location){ // audesyaa -> n_pawn_ko_location
  debug(press_piece_location);

  if(!white_turn){ // white case
    if(press_piece_location[1] == '5'){ // first condition approved
      pair<string,string> m_back = move_history.back(); // {"P4",D5}
    if(m_back.first[0] == 'P'){ // milo m_back.first[0] = 'P'
      int back_piece_cnt = cnt_piece_move_history(move_history,m_back.first,white_turn); // 1
      debug(back_piece_cnt);
      if(back_piece_cnt == 1 && m_back.second[1] == '5'){ // double move condition 
                                                          // left
        if(press_piece_location[0] - 1 == m_back.second[0]){ // left contion 
          int rank = (press_piece_location[1]-'0') + 1;
          char files = press_piece_location[0] -1;
          n_pawn_piece.push_back({m_back.first,files+to_string(rank)});
          return files + to_string(rank);
        }else if(press_piece_location[0] + 1 == m_back.second[0]){ // right
          int rank = (press_piece_location[1]-'0') + 1;
          char files = press_piece_location[0] +1;
          n_pawn_piece.push_back({m_back.first,files+to_string(rank)});
          return files + to_string(rank);
        }

      }
    }
    }
  }else{ // black case

    if(press_piece_location[1] == '4'){ // first condition approved
      pair<string,string> m_back = move_history.back(); // {"P4",D5}
    if(m_back.first[0] == 'P'){ // milo m_back.first[0] = 'P'
      int back_piece_cnt = cnt_piece_move_history(move_history,m_back.first,white_turn); // 1
      debug(back_piece_cnt);
      if(back_piece_cnt == 1 && m_back.second[1] == '4'){ // double move condition 
                                                          // left
        if(press_piece_location[0] - 1 == m_back.second[0]){ // left contion 
          int rank = (press_piece_location[1]-'0') - 1;
          char files = press_piece_location[0] -1;
          n_pawn_piece.push_back({m_back.first,files+to_string(rank)});
          return files + to_string(rank);
        }else if(press_piece_location[0] + 1 == m_back.second[0]){ // right
          int rank = (press_piece_location[1]-'0') - 1;
          char files = press_piece_location[0] +1;
          n_pawn_piece.push_back({m_back.first,files+to_string(rank)});
          return files + to_string(rank);
        }

      }
    }
    }
  }
  return "null";
}

;
string pawn_new_piece_opening(bool white_turn,map<string,string> &mp){
  char choose_piece;
  cout << "Choose Piece Between Rook->'R' Queen->'Q' Bisap->'B' Knight->'N' ";
  cin >> choose_piece;
  int cnt = search_number_of_piece(white_turn,mp,choose_piece) + 1;
  string new_piece = choose_piece + to_string(cnt);
  return new_piece;
}

vector<string> pawn_valid_move(string &curr_loc,bool white_turn,vector<pair<string,string>> &move_history){
  // single move
  vector<string> ans;
    char col  =  curr_loc[0];
  int row = curr_loc[1]-'0'; // converting to integer

  if(white_turn){
    // single move check
    int rank = row+1;                    
    char files = col;
    if( is_eligiable_loc(rank,files,white_turn) && is_valid_move(rank,files)
        && findKey(white_piece,files+to_string(rank)) == "null" 
        && findKey(black_piece,files+to_string(rank)) == "null") ans.push_back(files+to_string(rank));

    // left capture move check
    rank = row+1;
    files = col-1;
    if( is_valid_move(rank,files) && is_eligiable_loc(rank,files,white_turn) && findKey(black_piece,files+to_string(rank)) != "null") ans.push_back(files+to_string(rank));

    // right capture move check
    rank = row+1;
    files = col+1;
    if( is_valid_move(rank,files) && is_eligiable_loc(rank,files,white_turn) && findKey(black_piece,files+to_string(rank)) != "null") ans.push_back(files+to_string(rank));

    // double move check
    rank = row+2;
    files = col;
    string curr_piece = findKey(white_piece,col+to_string(row));
    if( is_valid_move(rank,files) && is_eligiable_loc(rank,files,white_turn) 
        && findKey(black_piece,files+to_string(rank)) == "null" 
        && findKey(black_piece,files+to_string(rank-1)) == "null"
        && rank-2 == 2
        && findKey(white_piece,files+to_string(rank)) == "null" 
        && findKey(white_piece,files+to_string(rank-1)) == "null" 
      ){
      ans.push_back(files+to_string(rank));
    } 

  }else{
    int rank = row-1;
    char files = col;
    if( is_valid_move(rank,files) && is_eligiable_loc(rank,files,!white_turn) 
        && findKey(black_piece,files+to_string(rank)) == "null" 
        && findKey(white_piece,files+to_string(rank)) == "null") ans.push_back(files+to_string(rank));

    // left capture move check
    rank = row-1;
    files = col-1;
    if( is_valid_move(rank,files) && is_eligiable_loc(rank,files,!white_turn) && findKey(white_piece,files+to_string(rank)) != "null") ans.push_back(files+to_string(rank));

    // right capture move check
    rank = row-1;
    files = col+1;
    if( is_valid_move(rank,files) && is_eligiable_loc(rank,files,!white_turn) && findKey(white_piece,files+to_string(rank)) != "null") ans.push_back(files+to_string(rank));

    // double move check
    rank = row-2;
    files = col;
    string curr_piece = findKey(black_piece,col+to_string(row));
    if( is_valid_move(rank,files) && is_eligiable_loc(rank,files,white_turn) 
        && findKey(black_piece,files+to_string(rank)) == "null" 
        && findKey(black_piece,files+to_string(rank+1)) == "null"
        && rank+2 == 7
        && findKey(white_piece,files+to_string(rank)) == "null" 
        && findKey(white_piece,files+to_string(rank+1)) == "null" 
      ){
      ans.push_back(files+to_string(rank));
    } 
  }

  bool alter_turn = !white_turn;
  string n_pawn = n_pawn_move(move_history,alter_turn,curr_loc);
  debug(n_pawn);
  // n_pawn_move
  debug(ans);
  if( n_pawn !="null") ans.push_back(n_pawn);
  debug(ans);
  

  return ans;
}

vector<string> king_valid_move(string &curr_loc,bool white_turn){
  vector<string> ans;
    map<string,string>search_mp = white_turn ? white_piece : black_piece;
    char col  =  curr_loc[0];
    int row = curr_loc[1]-'0'; // converting to integer


  // up move
  int rank = row;
  char files = col;
  rank++;
  if( is_valid_move(rank,files) && is_eligiable_loc(rank,files,white_turn)) ans.push_back(files+to_string(rank));


  // down move
  rank = row;
  files = col;
  rank--;
  if( is_valid_move(rank,files) && is_eligiable_loc(rank,files,white_turn)) ans.push_back(files+to_string(rank));


  // left move
  rank = row;
  files = col;
  files--;
  if( is_valid_move(rank,files) && is_eligiable_loc(rank,files,white_turn)) ans.push_back(files+to_string(rank));

  // right move
  rank = row;
  files = col;
  files++;
  if( is_valid_move(rank,files) && is_eligiable_loc(rank,files,white_turn)) ans.push_back(files+to_string(rank));


  // up left diagonal
  rank = row;
  files = col;
  files--;
  rank++;
  if( is_valid_move(rank,files) && is_eligiable_loc(rank,files,white_turn)) ans.push_back(files+to_string(rank));



  // up right diagonal
  rank = row;
  files = col;
  files++;
  rank++;
  if( is_valid_move(rank,files) && is_eligiable_loc(rank,files,white_turn)) ans.push_back(files+to_string(rank));

  // down left diagonal
  rank = row;
  files = col;
  files--;
  rank--;
  if( is_valid_move(rank,files) && is_eligiable_loc(rank,files,white_turn)) ans.push_back(files+to_string(rank));

  // down right diagonal
  rank = row;
  files = col;
  files++;
  rank--;
  if( is_valid_move(rank,files) && is_eligiable_loc(rank,files,white_turn)) ans.push_back(files+to_string(rank));


  // check for castle move
  if(white_turn){
    // left castle case
    if( white_rook1_move ){
      rank = row;
      files = col-1;
      while(files != 'A'){
        if(findKey(white_piece,files + to_string(rank)) != "null") break;
        files--;
      }
      if(files == 'A'){ // left castle possible
        ans.push_back('C'+to_string(rank));
      }
    }else if(white_rook2_move){
      rank = row;
      files = col+1;
      while(files != 'H'){
        if(findKey(white_piece,files + to_string(rank)) != "null") break;
        files++;
      }

      if(files == 'H'){ // left castle possible
        ans.push_back('G'+to_string(rank));
      }
    }
  }else{
    if(black_rook1_move){

    }else if(black_rook2_move){

    }
  }
  return ans;
}



private:
vector<string> knight_valid_move(string &curr_loc,bool white_turn){
  // first move 


  // whose game is this
  map<string,string>search_mp = white_turn ? white_piece : black_piece;

  char col  =  curr_loc[0];
  int row = curr_loc[1]-'0'; // converting to integer
  vector<string> ans;



  // left up diagonal move
  int rank = int(row) + 2;
  char files = col - 1;
  if(is_valid_move(rank,files) && findKey(search_mp,files+to_string(rank)) == "null") {
    ans.push_back(files + to_string(rank));
  }



  // right up diagonal move
  rank = int(row) + 2;
  files = col + 1;
  if(is_valid_move(rank,files) && findKey(search_mp,files+to_string(rank)) == "null") {
    ans.push_back(files + to_string(rank));
  }


  // left down diagonal move
  rank = int(row) - 2;
  files = col - 1;
  if(is_valid_move(rank,files) && findKey(search_mp,files+to_string(rank)) == "null") {
    ans.push_back(files + to_string(rank));
  }



  // right down diagonal move
  rank = int(row) - 2;
  files = col + 1;
  if(is_valid_move(rank,files) && findKey(search_mp,files+to_string(rank)) == "null") {
    ans.push_back(files + to_string(rank));
  }


  // left long up diagonal move
  rank = int(row) + 1;
  files = col - 2;
  if(is_valid_move(rank,files) && findKey(search_mp,files+to_string(rank)) == "null") {
    ans.push_back(files + to_string(rank));
  }

  // right long up diagonal move
  rank = int(row) + 1;
  files = col + 2;
  if(is_valid_move(rank,files) && findKey(search_mp,files+to_string(rank)) == "null") {
    ans.push_back(files + to_string(rank));
  }



  // left long down diagonal move
  rank = int(row) - 1;
  files = col - 2;
  if(is_valid_move(rank,files) && findKey(search_mp,files+to_string(rank)) == "null") {
    ans.push_back(files + to_string(rank));
  }



  // right long down diagonal move
  rank = int(row) - 1;
  files = col + 2;
  if(is_valid_move(rank,files) && findKey(search_mp,files+to_string(rank)) == "null") {
    ans.push_back(files + to_string(rank));
  }

  return ans;
}

public:
void play(){
  black_piece = {
    {"R1","H8"},
    {"N1","G8"},
    {"B1","F8"},
    {"K","E8"},
    {"Q","D8"},
    {"B2","C8"},
    {"N2","B8"},
    {"R2","A8"},
    {"P1","H7"},
    {"P2","G7"},
    {"P3","F7"},
    {"P4","E7"},
    {"P5","D7"},
    {"P6","C7"},
    {"P7","B7"},
    {"P8","A7"}
  }; 


  white_piece = {
    {"R1","A1"},
    {"R2","H1"},
    {"N1","B1"},
    {"N2","G1"},
    {"B1","F1"},
    {"Q","D1"}, // previous D1
    {"K","E1"},
    {"B2","C1"},
    {"N2","B1"},
    {"R2","A1"},
    {"P1","A2"}, // change A2-> A4
    {"P2","B2"},
    {"P3","C2"},
    {"P4","D2"},
    {"P5","E2"},
    {"P6","F2"},
    {"P7","G2"},
    {"P8","H2"}
  };

  bool black_castle = false;
  bool white_castle = false;

  vector<pair<string,string>>move_history;
  bool white_turn = true;
  while(1){
    debug(move_history);

    cout << (white_turn ? " ############# *white turn* #############\n": " ############# *black turn* #############\n");
    print_board(white_turn);

    string choose_piece;
    vector<string> ans;
    cout << "Choose Piece? ";
    cin >> choose_piece; // P1


    if(choose_piece[0] == 'N'){
      string loc = white_turn ? white_piece[choose_piece] : black_piece[choose_piece];
      ans = knight_valid_move(loc,white_turn);
    }else if(choose_piece[0] == 'R'){
      string loc = white_turn ? white_piece[choose_piece] : black_piece[choose_piece];
      ans = rook_valid_move(loc,white_turn);
    }else if(choose_piece[0] == 'B'){
      string loc = white_turn ? white_piece[choose_piece] : black_piece[choose_piece];
      ans = bisap_valid_move(loc,white_turn);
    }
    else if(choose_piece[0] == 'Q'){
      string loc = white_turn ? white_piece[choose_piece] : black_piece[choose_piece];
      ans = queen_valid_move(loc,white_turn);
    } else if(choose_piece[0] == 'K'){
      string loc = white_turn ? white_piece[choose_piece] : black_piece[choose_piece];
      ans = king_valid_move(loc,white_turn);
    }else if(choose_piece[0] == 'P'){
      string loc = white_turn ? white_piece[choose_piece] : black_piece[choose_piece];
      ans = pawn_valid_move(loc,white_turn,move_history);
    }
    print_board(white_turn,ans);
    debug(ans);
    string choose_location;
    cout << "Choose Location? ";
    cin >> choose_location; // A4

    bool is_valid_moves = false;
    for(auto i : ans){
      if (choose_location == i){
        is_valid_moves = true;
        break;
      }
    }

    if(is_valid_moves){

      // capture rule
      if(white_turn) {
        string loc = findKey(black_piece,choose_location);
        if(loc != "null") black_piece[loc] = "X";
      }
      else {
        string loc = findKey(white_piece,choose_location);
        if(loc != "null") white_piece[loc] = "X";
      }

      // after move setting new location
      if (white_turn){
        string n_piece_pawn =  pawn_contains_n_pawn(choose_location);
        if(choose_piece[0] == 'P' && n_piece_pawn != "null") black_piece[n_piece_pawn] = "X";
        debug(white_piece);


        if(choose_piece[0] == 'P' && choose_location[1] == '8'){ // generating new piece by pawn
          white_piece[choose_piece] = "X";
          string new_piece =  pawn_new_piece_opening(white_turn,white_piece);
          white_piece[new_piece] = choose_location;
        }else{
          white_piece[choose_piece] = choose_location;
        }



        // castle move checker
        if(choose_piece[0] == 'K' ){
          // left rook castle
          white_rook1_move = false;
          white_rook2_move = false;
        }else if((choose_piece == "R1")){
          white_rook1_move = false;
        }else if(choose_piece == "R2"){
          white_rook2_move = false;
        }





      } else {
        string n_piece_pawn =  pawn_contains_n_pawn(choose_location);
        debug("before");
        debug(n_piece_pawn);
        if(choose_piece[0] == 'P' && n_piece_pawn != "null") white_piece[n_piece_pawn] = "X";

        if(choose_piece[0] == 'P' && choose_location[1] == '1'){ // generating new piece by pawn
          black_piece[choose_piece] = "X";
          string new_piece =  pawn_new_piece_opening(white_turn,black_piece);
          black_piece[new_piece] = choose_location;
        }else{
          black_piece[choose_piece] = choose_location;
        }

        // castle move checker
        if(choose_piece[0] == 'K'){
          // left rook castle
          black_rook1_move = false;
          black_rook2_move = false;
        }else if((choose_piece == "R1")){
          black_rook1_move = false;
        }else if(choose_piece == "R2"){
          black_rook2_move = false;
        }




      }


      // storing all moves in location
      move_history.push_back({choose_piece,choose_location});

      // turun alternating
      white_turn = !white_turn;

    }else{
      cout << "Sorry illigal move!" << endl;
    }


  }
}
};


int main() {
  chess c;
  c.play();
  return 0;
}
