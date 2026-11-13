#include <bits/stdc++.h>
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
  // ANSI colors (256-color mode)
  const string RESET    = "\033[0m";
  // Board theme: blue. Alternatives you can try:
  //   green: light 107, dark 65     gray: light 250, dark 244
  const string LIGHT_BG = "\033[48;5;67m";  // lighter blue square
  const string DARK_BG  = "\033[48;5;24m";  // darker blue square
  const string WHITE_FG = "\033[1;38;5;231m"; // bold pure white piece
  const string BLACK_FG = "\033[1;38;5;16m";  // bold pure black piece

  cout << endl;
  for(int i = 7; i >= 0; i--){
    cout << (i + 1) << " "; // rank label
    for(int j = 7; j >= 0; j--){
      int file_idx = 7 - j; // A = 0 ... H = 7
      string square = string(1, (char)('H' - j)) + to_string(i + 1);

      int is_white_piece = 1;
      string piece = findKey( white_piece, square); // first search in white_piece
      if(piece == "null"){
        is_white_piece = 0;
        piece = findKey( black_piece, square); // search in black_piece
      }
      if(piece == "null"){
        is_white_piece = -1;
        piece = ",";
      }

      // A1 is a dark square, then alternate
      bool dark = ((file_idx + i) % 2 == 0);
      string bg = dark ? DARK_BG : LIGHT_BG;
      string fg = (is_white_piece == 1) ? WHITE_FG : BLACK_FG;

      cout << bg << fg << " " << emojiOfPiece(piece, is_white_piece) << " " << RESET;
    }
    cout << endl;
  }

  // file labels
  cout << "  ";
  for(char c = 'A'; c <= 'H'; c++) cout << " " << c << " ";
  cout << endl << endl;
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
  return " ";
}


private:
vector<string> rook_valid_move(string &curr_loc, bool white_turn){

  map<string,string>search_mp = white_turn ? white_piece : black_piece;
  char col  =  curr_loc[0];
  int row = curr_loc[1]-'0'; // converting to integer

  int rank = row;
  char files = col;

  // up direction 

while(rank <= 8){
  if(findKey(search_mp,files + to_string(rank+1)) == "null") break;

  if(white_turn){
    if(findKey(black_piece,files + to_string(rank)) == "null") break;
  }else{
    if(findKey(black_piece,files + to_string(rank)) == "null") break;
  }
  rank++;
}

cout << rank << endl;


vector<string> ans;
return {"sahil"};

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
      {"Q","E1"},
      {"K","D1"},
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
