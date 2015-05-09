#include "pathfinding.h"
using namespace std;

static int _direccionX[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
static int _direccionY[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

Pathfinding::Pathfinding(Matriz<short>* pMap) {
	_map = pMap;
	_height = pMap->getHeight();
	_width = pMap->getWidth();
}

string Pathfinding::find(int pXInicio, int pYInicio,
		int pXFinal, int pYFinal) {

	PriorityQueue<NodoMatriz> cola[2];
	short indiceCola = 0;
	NodoMatriz* nodoPadre;
	NodoMatriz* nodoHijo;
	int i, j, x, y, xdx, ydy;
	int dir = 8;
	char c;
	Matriz<short> closed_nodes_map(_height, _width);
	Matriz<short> open_nodes_map(_height, _width);
	Matriz<short> dir_map(_height, _width);

	for (y = 0; y < _height; y++)
			{
		for (x = 0; x < _width; x++)
				{
			closed_nodes_map[x][y] = 0;
			open_nodes_map[x][y] = 0;
		}
	}
	x--;
	y--;

	nodoPadre = new NodoMatriz(pXInicio, pYInicio, 0, 0);
	nodoPadre->updatePrioridad(pXFinal, pYFinal);
	cola[indiceCola].push(*nodoPadre);
	open_nodes_map[x][y] = nodoPadre->getPrioridad();

	while (!cola[indiceCola].empty()) {
		nodoPadre = new NodoMatriz(cola[indiceCola].top().getPosX(),
				cola[indiceCola].top().getPosY(),
				cola[indiceCola].top().getNivel(),
				cola[indiceCola].top().getPrioridad());

		x = nodoPadre->getPosX();
		y = nodoPadre->getPosY();

		cola[indiceCola].pop();
		open_nodes_map[x][y] = 0;
		closed_nodes_map[x][y] = 1;

		if ((*nodoPadre).calcularDistancia(pXFinal, pYFinal) == 0) {
			string path = "";

			while (!(x == pXInicio && y == pYInicio)) {
				j = dir_map[x][y];
				c = '0' + (j + dir / 2) % dir;
				path = c + path;
				x += _direccionX[j];
				y += _direccionY[j];
			}

			delete nodoPadre;
			while (!cola[indiceCola].empty()) {
				cola[indiceCola].pop();
			}
			return path;
		}

		for (i = 0; i < dir; i++) {
			xdx = x + _direccionX[i];
			ydy = y + _direccionY[i];

			if (!(xdx < 0 || xdx > _height - 1 || ydy < 0
					|| ydy > _width - 1 || (*_map)[xdx][ydy] == 1
					|| closed_nodes_map[xdx][ydy] == 1)) {

				nodoHijo = new NodoMatriz(xdx, ydy, nodoPadre->getNivel(),
						nodoPadre->getPrioridad());
				nodoHijo->elegirDiagonal(i);
				nodoHijo->updatePrioridad(pXFinal, pYFinal);

				if (open_nodes_map[xdx][ydy] == 0) {
					open_nodes_map[xdx][ydy] = nodoHijo->getPrioridad();
					cola[indiceCola].push(*nodoHijo);
					dir_map[xdx][ydy] = (i + dir / 2) % dir;
				}
				else if (open_nodes_map[xdx][ydy] > nodoHijo->getPrioridad()) {
					open_nodes_map[xdx][ydy] = nodoHijo->getPrioridad();

					dir_map[xdx][ydy] = (i + dir / 2) % dir;

					while (!(cola[indiceCola].top().getPosX() == xdx &&
							cola[indiceCola].top().getPosY() == ydy)) {
						cola[1 - indiceCola].push(cola[indiceCola].top());
						cola[indiceCola].pop();
					}
					cola[indiceCola].pop();

					if (cola[indiceCola].size() > cola[1 - indiceCola].size())
						indiceCola = 1 - indiceCola;
					while (!cola[indiceCola].empty()) {
						cola[1 - indiceCola].push(cola[indiceCola].top());
						cola[indiceCola].pop();
					}
					indiceCola = 1 - indiceCola;
					cola[indiceCola].push(*nodoHijo);
				}
				else
					delete nodoHijo;
			}
		}
		delete nodoPadre;
	}
	return "";
}

Pathfinding::~Pathfinding()
{
}

