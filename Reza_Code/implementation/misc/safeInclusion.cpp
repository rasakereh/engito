#ifndef _SAFE_INCLUSION_CPP
#define _SAFE_INCLUSION_CPP

#include <algorithm>
#include <functional>
#include <string>
#include <thread>
#include <typeinfo>
#include <utility>
#include <vector>

#include <QDebug>

template<typename _Desired, typename _Queried>
bool isInstanceOf(const _Queried &q)
{
	return typeid(_Desired).hash_code() == typeid(_Queried).hash_code();
}

class BoardCell;
class CellContainer;
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
class GameScreen;
class GraphicalUI;
class BoardToGUI;
class PlayerContainer;

#include "../headers/Game.h"

#endif
