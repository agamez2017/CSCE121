#ifndef TILE_H
#define TILE_H
#include <iostream>
using namespace std;
class Tile
{
public:
  char tile_char = '_';
public:
  virtual bool try_walk()
  {
    return false;
  }

  virtual bool is_start()
  {
    return false;
  }

  virtual bool is_end()
  {
    return false;
  }
};

class WallTile : public Tile
{
  public:
  WallTile(): Tile(){tile_char = 'W';}
};

class EmptyTile : public Tile
{
  public:
  virtual bool try_walk() {return true;}
  EmptyTile(): Tile(){tile_char = 'X';}
};

class StartingTile : public EmptyTile
{
  public:
  bool is_start() {return true;}
  StartingTile(): EmptyTile(){tile_char = 'S';}
};

class EndingTile : public EmptyTile
{
  public:
  bool is_end() {return true;}
  EndingTile(): EmptyTile(){tile_char = 'E';}
};

ostream & operator << (ostream &out, const Tile &t);
istream & operator >> (istream &in,  Tile *&t);

#endif
