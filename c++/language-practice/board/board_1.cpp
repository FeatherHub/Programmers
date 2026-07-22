#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "../_util/output.h"

using namespace std;

enum class Direction {
    Right, Left, Down, Up, Unknown
};
Direction to_direction(const string& s) {
    static const unordered_map<string, Direction> direction_map {
        {"right", Direction::Right},
        {"left", Direction::Left},
        {"up", Direction::Up},
        {"down", Direction::Down},
    };

    const auto it = direction_map.find(s);
    if(it != direction_map.end()) {
        return it->second;
    } else {
        return Direction::Unknown;
    }
}

struct Point2D {
public:
    Point2D(int x, int y): x{x}, y{y} {
    }
    explicit Point2D(const vector<int>& point_vec): Point2D{point_vec[0], point_vec[1]} {
    } 

    vector<int> to_vec() const {
      return {x, y};
    }

    void move(const Direction& dir) {
        switch(dir) {
        case Direction::Right:
            ++x;
            break;
        case Direction::Left:
            --x;
            break;
        case Direction::Up:
            ++y;
            break;
        case Direction::Down:
            --y;
            break;
        default:
            //do nothing
            break;
        }        
    }
    
    int x;
    int y;
};

class Board {
public:
    explicit Board(const vector<int>& board) {
        int half_width = board[0] / 2;
        int half_height = board[1] / 2;
        right = half_width;
        left = -half_width;
        top = half_height;
        bottom = -half_height;
    }
    
    bool is_within_bound(const Point2D& p) const {
        return p.x >= left && p.x <= right
            && p.y >= bottom && p.y <= top;
    }

private:
    int right;
    int left;
    int top;
    int bottom;
};

vector<int> solution(vector<string> keyinput, vector<int> board_) {
    const Board board {board_};
    
    Point2D cur_pos {0, 0};
    for(const string& input: keyinput) {
        Direction d = to_direction(input);
        Point2D next_pos {cur_pos};
        next_pos.move(d);
        if(board.is_within_bound(next_pos)) {
            cur_pos = next_pos;
        }
    }

    return cur_pos.to_vec();;
}

int main() {
  const string r = "right";
  const string l = "left";

  cout << solution({r,r,r,r,r,l}, {4,4}) << endl;


  return 0;
}