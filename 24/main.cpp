#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main(){
  int iterations = 1000000;
  const int limit = 10;
  vector<int> board;
  set<int> hand;

  board.reserve(limit);
  // Fill our board
  for (int i=0; i<limit; ++i){
    hand.insert(i);
  }

  // One iteration has been completed
  --iterations;

  // While we still have a bord and iterations to complete
  while (!board.empty() && iterations){
    // draw
    auto draw = hand.insert(board.back());
    auto drawn = draw.first;
    board.pop_back();

    // if we have a larger value then draw
    if (++drawn != hand.end()){
      // place larger value on board
      board.push_back(*drawn);
      hand.erase(drawn);
      
      //empty our hand
      for (auto i=hand.begin(); i!=hand.end(); ++i){
        board.push_back(*i);
      }
      hand.clear();

      // one iteration done
      --iterations;
    }
  }

  // print out result
  for (auto i=board.begin(); i!=board.end(); ++i){
    cout << *i;
  }

  return 0;
}