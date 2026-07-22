#include <iostream>
#include <vector>
#include <array>

using namespace std;

/*
  NW N NE
  E  -  W
  SW S SE
*/
enum class CompassDirection {
    N, S, E, W,
    NW, NE, SW, SE
};
constexpr array<CompassDirection, 8> COMPASS_DIRECTIONS {
    CompassDirection::N, CompassDirection::S, CompassDirection::E, CompassDirection::W,
    CompassDirection::NW, CompassDirection::NE, CompassDirection::SW, CompassDirection::SE    
};

class Vec2D {
public:
    int x = 0; 
    int y = 0;
public:
    Vec2D(int x, int y): x{x}, y{y} {}
    Vec2D move(CompassDirection d) const {
        switch(d) {
            case CompassDirection::N:
                return {x, y+1};
            case CompassDirection::S:
                return {x, y-1};
            case CompassDirection::E:
                return {x+1, y};
            case CompassDirection::W:
                return {x-1, y};
            case CompassDirection::NW:
                return {x-1, y+1};
            case CompassDirection::NE:
                return {x+1, y+1};
            case CompassDirection::SW:
                return {x-1, y-1};
            case CompassDirection::SE:
                return {x+1, y-1};
        }
    }
};

bool is_within_bound(const Vec2D& p, const Vec2D& dim) {
    return p.x >= 0 && p.x < dim.x
        && p.y >= 0 && p.y < dim.y;
}

enum class Tile {
    Safe, Dangerous,
};
class GameBoard {
private:
  vector<vector<Tile>> board;

public:
  GameBoard(const Vec2D& dim): board (dim.y , vector<Tile>(dim.x, Tile::Safe)) {
  }

  void mark_tile(Tile state, const Vec2D& p) {
    board[p.y][p.x] = state;
  }

  int safe_tile_cnt() const {
    int cnt = 0;
    for(const vector<Tile>& tiles: board) {
        for(const Tile tile: tiles) {
            if(tile == Tile::Safe) {
                ++cnt;
            }        
        }
    }
    return cnt;
  }
};

int solution(vector<vector<int>> board) {
    Vec2D dimension ( board.front().size(), board.size() );
    
    GameBoard game_board {dimension};

    for(int row = 0; row < dimension.y; ++row) {
        for(int col = 0; col < dimension.x; ++col) {
            if(board[row][col] == 1) {
                Vec2D bomd_pos {col, row};
                game_board.mark_tile(Tile::Dangerous, bomd_pos);
                for(const auto d: COMPASS_DIRECTIONS) {
                    Vec2D around_pos = bomd_pos.move(d);
                    if(is_within_bound(around_pos, dimension)) {
                        game_board.mark_tile(Tile::Dangerous,around_pos);
                    }
                }
            }        
        }
    }

    return game_board.safe_tile_cnt();
}


int main() {
  vector<vector<int>> board1 {
    {0, 0, 0, 0, 0}, 
    {0, 0, 0, 0, 0}, 
    {0, 0, 0, 0, 0}, 
    {0, 0, 1, 0, 0}, 
    {0, 0, 0, 0, 0}
  };
  vector<vector<int>> board2 {
    {0, 0, 0, 0, 0}, 
    {0, 0, 0, 0, 0}, 
    {0, 0, 0, 0, 0}, 
    {0, 0, 1, 1, 0}, 
    {0, 0, 0, 0, 0}
  };

  cout << solution(board1) << endl;
  cout << solution(board2) << endl;

  return 0;
}