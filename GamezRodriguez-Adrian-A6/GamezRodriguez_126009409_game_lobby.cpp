#include <iostream>
#include "std_lib_facilities.h"
using namespace std;
enum Player_state {	Connected =1 , Disconnected, Ready, Not_ready};
class Player;
class Lobby
{
	public:
	const int getLobbyId() const {return lobby_id;};
	Lobby(int new_lobbyID, int new_min, int new_max): lobby_id{new_lobbyID},  min{new_min}, max{new_max} {};
	bool check_if_all_players_ready();
	bool check_if_ready_to_start_game();
	void start_game();
	void join_game(Player* x);
	void leave_game(int player_id);
	private:
	int max;
	int min;
	int lobby_id;
	vector<Player*> list_of_players;
};
bool Lobby::check_if_all_players_ready()
{
	int count = 0;
	for(int i =0; i<list_of_players.size();i++)
	{
		if(list_of_players.at(i)->state==Ready)
		{
			count+=1;
		}
	}
	if(count == list_of_players.size())
	{
		return true;
	}
	else
		cout<<"Not all players ready\n";
		return false;
}
bool Lobby::check_if_ready_to_start_game()
{
	if(list_of_players.size()  <= max && list_of_players.size()>= min && check_if_all_players_ready())
	{
		return true;
	}
	else
		return false;
}
void Lobby::start_game()
{
	if(check_if_all_players_ready() == true && check_if_ready_to_start_game() == true)
	{
	cout<<"Game Started!\n";
	}
	else
		cout<<"Something's wrong\n";
}
void Lobby::join_game(Player* x)
{
	if(list_of_players.size()<max)
	{
		list_of_players.push_back(x);
		cout<<"Added Player: "<<x->getPlayerId()<<" to the lobby\n";
	}
	else 
	{
		cout<<"Cannot add player, exceeds max size.\n";
}
}
void Lobby::leave_game(int player_id)
{
	for(int i=0; i<list_of_players.size();i++)
	{
		if(list_of_players.at(i)->getPlayerId() == player_id)
		{
			list_of_players.erase(getListofPlayers()[i]);
			cout<<"Erased player: "<<player_id<<endl;
		}
	}
}
class Player
{
	public:
	Player_state state;
	const int getPlayerId() const{return player_id;};
	Player::Player(int new_player_id)
	{
		lobby_id =-1;
		state = Disconnected;
		player_id= new_player_id;
	}
	void ready_player();
	void unready_player();
	void connect_to_lobby(Lobby &lob);
	void disconnect_from_lobby(Lobby lob);
	private:
	int player_id;
	int lobby_id;
};
void Player::connect_to_lobby(Lobby &Lob1)
{
	lobby_id = Lob1.getLobbyId();
	state = Connected;
	Lob1.join_game(this);
}
int Player::disconnect_from_lobby(Lobby Lob1)
{
	lobby_id = -1;
	state = Disconnected;
	Lob1.leave_game(player_id);
}
void Player::ready_player()
{
	if(lobby_id == -1)
	{
		 error("<<: Not connected to Lobby");
	}
	else
	{
		state = Ready;
	}
}
void Player::unready_player()
{
	if(lobby_id == -1)
	{
		 error("<<: Not connected to Lobby");
	}
	else
	{
		state= Not_ready; 
	}
}
int main()
{ 
	
	Lobby lob1(1, 1, 2);
	Player player1(13);
    player1.connect_to_lobby(lob1);
	player1.ready_player();
	Player player2(1);
    player2.connect_to_lobby(lob1);
	player2.ready_player();
	lobb1.start_game();




return 0;


}