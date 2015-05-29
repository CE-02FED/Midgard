#include "BitVector.h"

/**
 * @brief BitVector::BitVector
 * Se crea el BitVector con tamaño pSize vacio
 * @param pSize: Tamaño del BitVector
 */
BitVector::BitVector (int pSize)  // constructor
{
  _BitVectorSize = pSize;
  _BitVectorData = (u_int8_t*) calloc(pSize,cantidadBits);

  if (_BitVectorData == 0)
  {
    std::cout << "** BitVector memory allocation failure -- terminating program.\n"<< std::endl;
    exit (EXIT_FAILURE);
  }

  for (int i = 0; i < _BitVectorSize; ++i){
    _BitVectorData[i] = 0x00;

  }
}

/**
  * @brief BitVector::BitVector
  * Se crea el bitVector con el array de pData y el tamaño de pSize
  * @param pSize: Tamaño del BitVector
  * @param pData: Datos de los cuales se formara el BitVector
  */
 BitVector::BitVector (int pSize, u_int8_t *pData)
 {
       _BitVectorSize = pSize;
       _BitVectorData = new u_int8_t [_BitVectorSize];
       if (_BitVectorData == 0)
       {
         std::cout << "** BitVector memory allocation failure -- terminating program.\n"<< std::endl;
         exit (EXIT_FAILURE);
       }

       for (size_t i = 0; i < _BitVectorSize; ++i){
         _BitVectorData[i] = pData[i];

       }

 }


 /**
  * @brief BitVector::operator =
  * Se pasan todos los datos contenidos en el BitVector de la derecha
  * y se asignan al array del BitVector de la izquierda
  * @param pRightAssignment: BitVector
  * @return Nuevo BitVector con los datos de pRightAssignment
  */
BitVector& BitVector::operator = (const BitVector& pRightAssignment)  //assignment operator
{
  if (this != &pRightAssignment)
  {
    if (_BitVectorSize != pRightAssignment._BitVectorSize)
    {
      delete [] _BitVectorData;
      _BitVectorSize = pRightAssignment._BitVectorSize;
      _BitVectorData = new u_int8_t [_BitVectorSize];
      if (_BitVectorData == 0)
      {
        //std::cerr << "** BitVector memory allocation failure -- terminating program.\n";
        exit (EXIT_FAILURE);
      }
    }
    for (size_t i = 0; i < _BitVectorSize; ++i)
      _BitVectorData[i] = pRightAssignment._BitVectorData[i];
  }
  return *this;
}

/**
 * @brief BitVector::andOperator
 * Aplica un operador & con la posicion del array y la mascara
 * @param pIndex indice del array al que se le aplicara el operator
 * @param pMask La mascara con la que se aplicara el & operator
 */
void BitVector::orOperator(int pIndex, u_int8_t pMask)
{
     _BitVectorData[pIndex] ^= pMask;
}

/**
 * @brief BitVector::andOperator
 * Aplica un operador or con la posicion del array y la mascara
 * @param pIndex indice del array al que se le aplicara el operator
 * @param pMask La mascara con la que se aplicara el or operator
 */
void BitVector::andOperator(int pIndex, u_int8_t pMask )
{
    _BitVectorData[pIndex] &= pMask;
}


/**
 * @brief BitVector::Set: Cambia el bit del array indicado, a 1
 * @param pIndex: Indice del bit de todo el arrray que se desea settear
 */
void BitVector::Set (size_t pIndex)
// set specified bit
{
  _BitVectorData[getBitVectorPosicion(pIndex)] |= bitMask(pIndex);
}

/**
 * @brief BitVector::Unset
 * Cambia un bit de 1 a 0
 * @param pIndex: Numero del  bit EJ: Si el array es de 10 100 es el ultimo bit
 */
void BitVector::Unset(size_t pIndex)
{
    _BitVectorData[getBitVectorPosicion(pIndex)] ^= bitMask(pIndex);
}

/**
 * @brief BitVector::Flip
 * Cambia toda la posicion del array que se indica la invierte
 * @param pIndex: Indice de la posicion del array
 */
void BitVector::Flip(int pIndex)
{

     _BitVectorData[getBitVectorPosicion(pIndex)] = ~_BitVectorData[getBitVectorPosicion(pIndex)];

}

/**
 * @brief BitVector::Flip
 * Invierte todo el bitVector
 */
void BitVector::Flip()
{

    for (int i =0; i< _BitVectorSize*cantidadBits ; i++){
     _BitVectorData[getBitVectorPosicion(i)] = ~_BitVectorData[getBitVectorPosicion(i)];

    }
}

/**
 * @brief BitVector::insertByIndex
 * Inserta pBinData a la posicion del array que se indica en pIndez
 * @param pIndex
 * @param pBinData
 */
void BitVector::insertByIndex(int pIndex, u_int8_t pBinData)
{
    _BitVectorData[pIndex] = pBinData;
}

/**
 * @brief BitVector::getByIndex
 * Obtener los datos del pIndex del array
 * @param pIndex
 * @return se devuelve todos los datos de la posicion del array que se indica
 */
u_int8_t BitVector::getByIndex(int pIndex)
{
    return  _BitVectorData[pIndex];
}

/**
 * @brief BitVector::Size
 * @return El tamaño del array
 */
size_t BitVector::Size()
{
    return this->_BitVectorSize;
}



/**
 * @brief BitVector::ByteNumber: Devuelve los bits que se encuentran en el espacio indicado
 * @param pIndex: indice del "bit" al cual se desea acceder del bitVector
 * @return el indice del array al que se desea ingresar
 */
int BitVector::getBitVectorPosicion(int pIndex) const
{
  // retorna El indice / 8
  // mover hacia la derecha 3 espaciaos es equivalente y mas eficiente que dividir entre 8

  pIndex = pIndex >> 3;

  if (pIndex >= _BitVectorSize*cantidadBits)
  {
    std::cout << "** BitVector error: pIndex out of range\n"<< std::endl;
    exit (EXIT_FAILURE);
  }
  return pIndex;
}

/**
 * @brief BitVector::getArray
 * Devuelve todo el array del bitVector
 * @return Todo el array del bitVector
 */
unsigned char* BitVector::getArray()
{

    return this->_BitVectorData;
}


/**
 * @brief BitVector::bitMask
 * devuelve una mascara para poder ubicar al bit indicado en pIndex.
 * @param pIndex
 * @return devuelve una mascara para poder ubicar al bit indicado
 */
size_t BitVector::bitMask (int pIndex)
{
  // return bitMask for pIndex % 8
  // the low order 3 bits is the remainder when dividing by 8
  size_t tmpMask = (char) 1;
  tmpMask = tmpMask << (pIndex%cantidadBits);  // low order 3 bits

  return tmpMask;

}

