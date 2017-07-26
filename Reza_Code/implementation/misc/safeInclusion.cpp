#ifndef _SAFE_INCLUSION_CPP
#define _SAFE_INCLUSION_CPP

#include <algorithm>
#include <functional>
#include <string>
#include <typeinfo>
#include <vector>

template<typename _Desired, typename _Queried>
bool isInstanceOf(const _Queried &q)
{
	return typeid(_Desired).hash_code() == typeid(_Queried).hash_code();
}

class BoardCell;
class Dice;
class DecisionTranslator;
class Treasure;
class ConsoleUI;
class DecisionCell;
class InitialCell;
class OrdinaryCell;
class TransportCell;
class TreasureCell;
class Decision;
class CellDecision;
class DiceDecision;
class Player;
class RealPlayer;
class RobotPlayer;
class NetworkPlayer;
class GameStatistics;
class GameRuler;
class GameBoard;
class UI;
class Game;
class GameInitializer;
class MapLoader;

#include "../headers/Game.h"

#endif
