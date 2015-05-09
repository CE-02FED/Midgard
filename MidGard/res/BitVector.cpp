#include "BitVector.h"

BitVector::BitVector (int pSize)  // constructor
{
  _BitVectorSize = pSize;
  _BitVectorData = (unsigned char*) calloc(pSize,cantidadBits);

  if (_BitVectorData == 0)
  {
    std::cout << "** BitVector memory allocation failure -- terminating program.\n"<< std::endl;
    exit (EXIT_FAILURE);
  }

  for (int i = 0; i < _BitVectorSize; ++i){
    _BitVectorData[i] = 0x00;

  }
}

 BitVector::BitVector (int pSize, unsigned char* pData)
 {
       _BitVectorSize = pSize;
       _BitVectorData = new unsigned char [_BitVectorSize];
       if (_BitVectorData == 0)
       {
         std::cout << "** BitVector memory allocation failure -- terminating program.\n"<< std::endl;
         exit (EXIT_FAILURE);
       }

       for (size_t i = 0; i < _BitVectorSize; ++i){
         _BitVectorData[i] = pData[i];

       }

 }

BitVector& BitVector::operator = (const BitVector& pRightAssignment)  //assignment operator
{
  if (this != &pRightAssignment)
  {
    if (_BitVectorSize != pRightAssignment._BitVectorSize)
    {
      delete [] _BitVectorData;
      _BitVectorSize = pRightAssignment._BitVectorSize;
      _BitVectorData = new unsigned char [_BitVectorSize];
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

void BitVector::orOperator(int pIndex, unsigned char* pMask)
{
     _BitVectorData[getBitVectorPosicion(pIndex)] |= bitMask(pIndex);
}

void BitVector::andOperator(int pIndex, size_t pMask )
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

void BitVector::Unset(size_t pIndex)
{
    _BitVectorData[getBitVectorPosicion(pIndex)] ^= bitMask(pIndex);
}

void BitVector::Flip(int pIndex)
{

     _BitVectorData[getBitVectorPosicion(pIndex)] = ~_BitVectorData[getBitVectorPosicion(pIndex)];

}

void BitVector::Flip()
{

    for (int i =0; i< _BitVectorSize*cantidadBits ; i++){
     _BitVectorData[getBitVectorPosicion(i)] = ~_BitVectorData[getBitVectorPosicion(i)];

    }
}


void BitVector::insertByIndex(int pIndex,unsigned char pBinData)
{
    _BitVectorData[pIndex] = pBinData;
}


unsigned char BitVector::getByIndex(int pIndex)
{
    return  _BitVectorData[pIndex];
}

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

unsigned char* BitVector::getArray()
{

    return this->_BitVectorData;
}



unsigned char const BitVector::bitMask (int pIndex)
{
  // return bitMask for pIndex % 8
  // the low order 3 bits is the remainder when dividing by 8
  size_t tmpMask = (char) 1;
  tmpMask = tmpMask << (pIndex%cantidadBits);  // low order 3 bits

  return tmpMask;

}

