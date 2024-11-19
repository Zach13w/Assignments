#include<ncurses>
#include<iostream>

using namespace std


class Game {
public:
   Game();

      // Main gameplay methods
      void start();
      void take_turn();
      bool check_win();

      // Game setup and utility methods
      void initialize_players(std::string player1_name, std::string player2_name);
      void roll_dice();

      // Optional UI-oriented methods
      void display_game_state();
      void end_game();

private:
   Dice dice; // Dice instance owned by Game, used each turn
   Grid grid; // Game-level grid instance for managing cells
   Player\* current_player;
   Player players[2]; // Array of players for a two-player game

   void switch_turn();

};

class Player {

private:
string name; // Player's name
int score; // Player's score

public:
Player(string n)
{
    name = n;
    score = 0;
}
// Player actions
void take_turn(Game& game)
{
    game.take_turn();
}  // Player's turn with access to Game methods as needed
void add_to_score(int points)
{
    score += points;
}

// Accessors
string get_name() {return name;}
int get_score() {return score;}

};
