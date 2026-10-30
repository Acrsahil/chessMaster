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

      cout << (white_turn == true ? "white turn!!\n": "black turn!!\n");
      
        for(int i = 7; i >= 0; i--){
          for(int j = 7; j >= 0; j--){
            string piece = findKey(
                white_piece,
                string(1, (char)('H' - j)) + to_string(i + 1)
                );
              
              if(piece == "null")
                piece = findKey(
                    black_piece,
                    string(1, (char)('H' - j)) + to_string(i + 1)
                    );
                  
                  if(piece == "null")
                    piece = ",";
                      
                      cout << setw(4) << piece;
          }
          cout << endl;
        }



      cout << "Choose Piece? " << endl;
      string choose_piece; cin >> choose_piece; // P1
      cout << "You have choose Piece-> " << choose_piece << endl;

      cout << "Choose Location? " << endl;
      string choose_location; cin >> choose_location; // A4
      cout << "You have choose Location-> " << choose_location << endl;

      cout << ".....Before....." << endl;
      if(white_turn) {
        debug(white_piece);
        string loc = findKey(black_piece,choose_location);
        if(loc != "null"){

        }
      }
      else {
        debug(black_piece);
      }



      // rule based insertation
      if (white_turn) white_piece[choose_piece] = choose_location;
      else black_piece[choose_piece] = choose_location;

      cout << ".....After....." << endl;

      if(white_turn) {
        debug(white_piece);
      }
      else {
        debug(black_piece);
      }
      move_history.push_back({choose_piece,choose_location});
      debug(move_history);

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
