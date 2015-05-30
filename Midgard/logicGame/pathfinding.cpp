#include "pathfinding.h"
using namespace std;

static int _direccionX[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
static int _direccionY[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

Pathfinding::Pathfinding() {
    _map = Map::getInstance()->getMapMatriz();
    _height = _map->getHeight();
    _width = _map->getWidth();
	_listaAbierta = new Vector<short>(_height, _width);
	_listaCerrada = new Vector<short>(_height, _width);
	_listaDireccion = new Vector<short>(_height, _width);

}

Vector<int>* Pathfinding::calcularRuta(int pXInicio, int pYInicio,
						 	 	 	 	 int pXFinal, int pYFinal) {
	string rutaString = this->find( pXInicio, pYInicio,
									pXFinal, pYFinal);
	Vector<int>* ruta = obtenerRuta(rutaString, pXInicio, pYInicio);
	return ruta;
}

string Pathfinding::find(int pXInicio, int pYInicio,
						 int pXFinal, int pYFinal) {

	PriorityQueue<NodoMatriz> _cola[2];
	short indiceCola = 0;
	NodoMatriz* nodoPadre;
	NodoMatriz* nodoHijo;
	//int posHorizontal =
	int x=59, y=59, xdx, ydy;
	int dir = 8;
	char c;

	_listaAbierta->llenarMatriz(0);
	_listaCerrada->llenarMatriz(0);

	nodoPadre = new NodoMatriz(pXInicio, pYInicio, 0, 0);
	nodoPadre->updatePrioridad(pXFinal, pYFinal);
	_cola[indiceCola].push(*nodoPadre);
	(*_listaAbierta)[x][y] = nodoPadre->getPrioridad();

	while (!_cola[indiceCola].empty()) {
		nodoPadre = new NodoMatriz(_cola[indiceCola].top().getPosX(),
								   _cola[indiceCola].top().getPosY(),
								   _cola[indiceCola].top().getNivel(),
								   _cola[indiceCola].top().getPrioridad());

		x = nodoPadre->getPosX();
		y = nodoPadre->getPosY();

		_cola[indiceCola].pop();
		(*_listaAbierta)[x][y] = 0;
		(*_listaCerrada)[x][y] = 1;

		if ((*nodoPadre).calcularDistancia(pXFinal, pYFinal) == 0) {
			string path = "";

			while (!(x == pXInicio && y == pYInicio)) {
				int j = (*_listaDireccion)[x][y];
				c = '0' + (j + dir / 2) % dir;
				path = c + path;
				x += _direccionX[j];
				y += _direccionY[j];
			}

			delete nodoPadre;
			while (!_cola[indiceCola].empty()) {
				_cola[indiceCola].pop();
			}
			return path;
		}

		for (int i = 0; i < dir; i++) {
			xdx = x + _direccionX[i];
			ydy = y + _direccionY[i];

			if (!(xdx < 0 || xdx > _height - 1 || ydy < 0
                  || ydy > _width - 1 || (*_map)[xdx][ydy] == 87
				  || (*_listaCerrada)[xdx][ydy] == 1)) {

				nodoHijo = new NodoMatriz(xdx, ydy, nodoPadre->getNivel(),
										  nodoPadre->getPrioridad());
				nodoHijo->elegirDiagonal(i);
				nodoHijo->updatePrioridad(pXFinal, pYFinal);

				if ((*_listaAbierta)[xdx][ydy] == 0) {
					(*_listaAbierta)[xdx][ydy] = nodoHijo->getPrioridad();
					_cola[indiceCola].push(*nodoHijo);
					(*_listaDireccion)[xdx][ydy] = (i + dir / 2) % dir;
				}
				else if ((*_listaAbierta)[xdx][ydy] > nodoHijo->getPrioridad()) {
					(*_listaAbierta)[xdx][ydy] = nodoHijo->getPrioridad();

					(*_listaDireccion)[xdx][ydy] = (i + dir / 2) % dir;

					while (!(_cola[indiceCola].top().getPosX() == xdx &&
							 _cola[indiceCola].top().getPosY() == ydy)) {
						_cola[1 - indiceCola].push(_cola[indiceCola].top());
						_cola[indiceCola].pop();
					}
					_cola[indiceCola].pop();

					if (_cola[indiceCola].size() > _cola[1 - indiceCola].size())
						indiceCola = 1 - indiceCola;
					while (!_cola[indiceCola].empty()) {
						_cola[1 - indiceCola].push(_cola[indiceCola].top());
						_cola[indiceCola].pop();
					}
					indiceCola = 1 - indiceCola;
					_cola[indiceCola].push(*nodoHijo);
				}
				else delete nodoHijo;
			}
		}
		delete nodoPadre;
	}
	return "";
}

Pathfinding::~Pathfinding()
{
}

int Pathfinding::calcularPosHorizontal(int pPosX, char pCambio) {
	return pPosX + _direccionX[atoi(&pCambio)];
}

int Pathfinding::calcularPosVertical(int pPosY, char pCambio) {
	return pPosY + _direccionY[atoi(&pCambio)];
}

Vector<int>* Pathfinding::obtenerRuta(string pRuta, int pPosX, int pPosY) {
	Vector<int>* ruta = new Vector<int>(pRuta.length(),2);
	int actualPosX = pPosX;
	int actualPosY = pPosY;
	for (int i = 0; i < pRuta.length(); i++) {
		int valorX = calcularPosHorizontal(actualPosX, pRuta.at(i));
		int valorY = calcularPosVertical(actualPosY, pRuta.at(i));
		(*ruta)[i][0] = actualPosX = valorX;
		(*ruta)[i][1] = actualPosY = valorY;
	}
	return ruta;
}

