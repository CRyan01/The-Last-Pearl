//by John Hannon K00281825
#include <vector>
#include <SFML/Audio.hpp>
using namespace sf;
using namespace std;
class Paths {
public :
	

	void SetLevel(int level);
	Vector2f nextPos(int CurrentNumber);
	Paths();
	~Paths();
private:
	vector<Vector2f> CurrentPath;
	vector<sf::Vector2f> Level1Pos;
	vector<sf::Vector2f> Level2Pos;
	vector<sf::Vector2f> Level3Pos;
	vector<sf::Vector2f> Level4Pos;
	vector<sf::Vector2f> Level5Pos;
};