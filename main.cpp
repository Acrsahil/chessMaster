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
  map<string,string>black_piece;
  map<string,string>white_piece;

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
void print_board(bool white_turn){
  for(int i = 7; i >= 0; i--){
    for(int j = 7; j >= 0; j--){
      int is_white_piece = 1;
      string piece = findKey( white_piece, string(1, (char)('H' - j)) + to_string(i + 1)); // first search in white_piece
      if(piece == "null"){
        is_white_piece = 0;
        piece = findKey( black_piece, string(1, (char)('H' - j)) + to_string(i + 1)); // search in black_piece
      } 
      if(piece == "null"){
        is_white_piece = -1;
        piece = ",";
      }
      cout << "| " << emojiOfPiece(piece,is_white_piece) << "  " ;
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
string emojiOfPiece(string piece_notation,int white_turn){

  // Adding White Emoji for game
  if(white_turn == 1){
    if(piece_notation[0]=='P') return "♙";
    else if(piece_notation[0]=='N') return "♘";
    else if(piece_notation[0]=='B') return "♗";
    else if(piece_notation[0]=='R') return "♖";
    else if(piece_notation[0]=='Q') return "♕";
    else if(piece_notation[0]=='K') return "♔";


  }else if(white_turn == 0){
    // Adding Black Emoji for game


    if(piece_notation[0]=='P') return "♟";


    else if(piece_notation[0]=='N') return "♞";
    else if(piece_notation[0]=='B') return "♝";
    else if(piece_notation[0]=='R') return "♜";
    else if(piece_notation[0]=='Q') return "♛";
    else if(piece_notation[0]=='K') return "♚";
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
  vector<string> ans = rook_valid_move(curr_loc,white_turn);
  vector<string> ans2 = bisap_valid_move(curr_loc,white_turn);
  ans.insert(ans.end(),ans2.begin(),ans2.end());
  return ans;
}

private: 
bool is_eligiable_loc(int rank,char files,bool white_turn){
    string next_loc = files+to_string(rank);
    if(white_turn){
      if(findKey(white_piece,next_loc) == "null") return true;
      if(findKey(black_piece,next_loc) != "null") return true;
    }else{
      if(findKey(black_piece,next_loc) == "null") return true;
      if(findKey(white_piece,next_loc) != "null") return true;
    }
return false;
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
    if(is_eligiable_loc(rank,files,white_turn)) ans.push_back(files+to_string(rank));


    // down move
    rank = row;
    files = col;
    rank--;
    if(is_eligiable_loc(rank,files,white_turn)) ans.push_back(files+to_string(rank));


    // left move
    rank = row;
    files = col;
    files--;
    if(is_eligiable_loc(rank,files,white_turn)) ans.push_back(files+to_string(rank));

    // right move
    rank = row;
    files = col;
    files++;
    if(is_eligiable_loc(rank,files,white_turn)) ans.push_back(files+to_string(rank));


    // up left diagonal
    rank = row;
    files = col;
    files--;
    rank++;
    if(is_eligiable_loc(rank,files,white_turn)) ans.push_back(files+to_string(rank));



    // up right diagonal
    rank = row;
    files = col;
    files++;
    rank++;
    if(is_eligiable_loc(rank,files,white_turn)) ans.push_back(files+to_string(rank));

    // down left diagonal
    rank = row;
    files = col;
    files--;
    rank--;
    if(is_eligiable_loc(rank,files,white_turn)) ans.push_back(files+to_string(rank));

    // down right diagonal
    rank = row;
    files = col;
    files++;
    rank--;
    if(is_eligiable_loc(rank,files,white_turn)) ans.push_back(files+to_string(rank));
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
    {"R2","C1"},
    {"N1","B1"},
    {"N2","G1"},
    {"B1","F1"},
    {"Q","E1"}, // previous E1
    {"K","D5"},
    {"B2","D5"},
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

  vector<pair<string,string>>move_history;
  int cnt  = 10;
  bool white_turn = true;
  while(cnt--){

    print_board(white_turn);

    cout << (white_turn ? "white turn!!\n": "black turn!!\n");

    string choose_piece;
    cout << "Choose Piece? " << endl;
    cin >> choose_piece; // P1

    cout << "You have choose Piece-> " << choose_piece << endl;

    if(choose_piece[0] == 'N'){
      string loc = white_turn ? white_piece[choose_piece] : black_piece[choose_piece];
      vector<string>ans = knight_valid_move(loc,white_turn);
      debug(ans);
    }else if(choose_piece[0] == 'R'){
      string loc = white_turn ? white_piece[choose_piece] : black_piece[choose_piece];
      vector<string>ans = rook_valid_move(loc,white_turn);
      debug(ans);
    }else if(choose_piece[0] == 'B'){
      string loc = white_turn ? white_piece[choose_piece] : black_piece[choose_piece];
      vector<string>ans = bisap_valid_move(loc,white_turn);
      debug(ans);
    }
    else if(choose_piece[0] == 'Q'){
      string loc = white_turn ? white_piece[choose_piece] : black_piece[choose_piece];
      vector<string>ans = queen_valid_move(loc,white_turn);
      debug(ans);
    } else if(choose_piece[0] == 'K'){
      string loc = white_turn ? white_piece[choose_piece] : black_piece[choose_piece];
      vector<string>ans = king_valid_move(loc,white_turn);
      debug(ans);
    }

    string choose_location;
    cout << "Choose Location? " << endl;
    cin >> choose_location; // A4

    cout << "You have choose Location-> " << choose_location << endl;

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
    if (white_turn) white_piece[choose_piece] = choose_location;
    else black_piece[choose_piece] = choose_location;

    // storing all moves in location
    move_history.push_back({choose_piece,choose_location});
    debug(move_history);

    // turun alternating
    white_turn = !white_turn;
    debug(move_history);
  }
}

};




int main() {
  chess c;
  c.play();
  return 0;
}
