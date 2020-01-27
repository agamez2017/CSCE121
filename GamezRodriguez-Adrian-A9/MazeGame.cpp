// implementation of MazeGame functions

#include "MazeGame.h"

MazeGame::MazeGame(string filename)
{
  save_out.open(out_name);
  ifstream in;
  in.open(filename);
  if (!in) {
    cerr << "Wrong maze tiles file: " + filename << endl;
    throw IncorrectFile();
  }
  save_out << "Maze tiles file: " << filename << endl << endl;
  in >> maze;
}

MazeGame::~MazeGame()
{
  save_out.close();
}

void MazeGame::start_game(istream & is)
{
	// implement this function
	vector<Position> posses;
  for(int r=0; r<maze.get_tiles().size();r++)
  {
	  for(int c = 0; c<maze.get_tiles()[0].size(); c++)
	  {
		  if(maze.get_tiles()[r][c]->tile_char == 'S')//traverses through the matrix and finds starting tile to save positions of starting tiles
		  {
			  Position pos(r,c);
			  posses.push_back(pos);
		  } 
	  }
  }
	for(int i=0; i<posses.size();i++)//places players their respective positions
	{
		MazePlayer* p = new MazePlayer{posses[i]};
		players.push_back(p);
	}
	print_maze();
	update_loop(is);
}

// Important: if you use cout << something
// do the same with save_out << something
// Otherwise, the file output.txt would be incorrect
void MazeGame::update_loop(istream & is)
{
  int pnum = 0; // player's number
  for(auto player : players) 
  {
    pnum++;
	cout<<"Player "<<pnum<<" position :"<<player->get_position()<<endl;
	save_out<<"Player "<<pnum<<" posiion :"<<player->get_position()<<endl;
	cout<<"Move # "<<player->move_number();
	save_out<<"Move # "<<player->move_number();
	cout<<"-------------------------\n";
	save_out<<"---------------------\n";
	cout<<endl;
	save_out<<endl;
	bool isnew = false;
	while(!isnew)
	{
	string input;
	is>>input;
	save_out<<input;
	Position new_pos = player->take_turn(input);
	bool b = maze.can_move_to_tile(new_pos);
	if(!b)
	{
		cout<<"Invalid Move, Try again\n";
		save_out<<"Invalid Move, Try again\n";	
	}
	if(player->get_position().row == new_pos.row && player->get_position().col == new_pos.col)
	{
	cout<<"Invalid Move, Try again\n";
	save_out<<"Invalid Move, Try again\n";
	}
	if(b && !(player->get_position().row == new_pos.row && player->get_position().col == new_pos.col))
	{
		player->set_position(new_pos);
		isnew= true;
	}
	}
	print_maze();
	if(maze.is_tile_end(player->get_position()))
	{
		cout<<"Player "<<pnum<<" Won!\n";
		save_out<<"Player "<<pnum<<" Won!\n";
		return;
	}
  }
	update_loop(is);
}

void MazeGame::print_maze()
{
  vector<string> grid;
  for(auto row : maze.get_tiles()) {
    string tiles = "";
    for(auto t : row) 
	{
      tiles += t->tile_char;
	}
    grid.push_back(tiles);
  }

  for(auto player : players)
    grid[player->get_position().row][player->get_position().col] = 'P';

  cout << " ";
  save_out << " ";
  
  for(int i = 0; i < grid[0].size(); i++) {
    cout << i;
    save_out << i;
  }

  cout << endl;
  save_out << endl;
  
  for(int i = 0; i < grid.size(); i++) {
    cout << i << grid[i] << endl;
    save_out << i << grid[i] << endl;
  }
}

