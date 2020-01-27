#include "Tile.h"

// output a tile character
ostream & operator << (ostream &out, const Tile &t)
{
  out << t.tile_char;
  return out;
}

// *& is a reference to a pointer
// here t is a reference to Tile*
// read in a tile character, and return in t a Tile object
istream & operator >> (istream &in,  Tile *&t)
{
	char k;
	in>>k;
	  if(k =='W')
	  {	  
		 t = new WallTile;
	  }
	  if(k == 'S')
	  {
		  t = new StartingTile;
	  }
	  if(k =='X')
	  {
		 t = new EmptyTile;
	  }
	  if(k =='E')
	  {
		  t = new EndingTile;
	  }  
  return in;
}
