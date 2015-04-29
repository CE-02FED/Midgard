#include "BitVector.h"

BitVector::BitVector (size_t pSize)  // constructor
{
  _SizeArray = pSize;
  _ByteArray = new unsigned char [_SizeArray];
  if (_ByteArray == 0)
  {
    cout << "** BitVector memory allocation failure -- terminating program.\n"<< endl;
    exit (EXIT_FAILURE);
  }

  for (size_t i = 0; i < _SizeArray; ++i){
    _ByteArray[i] = (size_t)ochoBits;

  }
}

BitVector& BitVector::operator = (const BitVector& pRightAssignment)  //assignment operator
{
  if (this != &pRightAssignment)
  {
    if (_SizeArray != pRightAssignment._SizeArray)
    {
      delete [] _ByteArray;
      _SizeArray = pRightAssignment._SizeArray;
      _ByteArray = new unsigned char [_SizeArray];
      if (_ByteArray == 0)
      {
        //std::cerr << "** BitVector memory allocation failure -- terminating program.\n";
        exit (EXIT_FAILURE);
      }
    }
    for (size_t i = 0; i < _SizeArray; ++i)
      _ByteArray[i] = pRightAssignment._ByteArray[i];
  }
  return *this;
}

void BitVector::orOperator(int pIndex, size_t pMask)
{
     _ByteArray[ByteNumber(pIndex)] |= bitMask(pIndex);
}

void BitVector::andOperator(int pIndex, size_t pMask )
{
    _ByteArray[pIndex] &= pMask;
}


/**
 * @brief BitVector::Set: Cambia el bit del array indicado, a 1
 * @param pIndex: Indice del bit de todo el arrray que se desea settear
 */
void BitVector::Set (size_t pIndex)
// set specified bit
{
  _ByteArray[ByteNumber(pIndex)] |= bitMask(pIndex);
}

void BitVector::Unset(size_t pIndex)
{
    _ByteArray[ByteNumber(pIndex)] ^= bitMask(pIndex);
}

void BitVector::Flip(size_t pIndex)
{
     _ByteArray[ByteNumber(pIndex)] = ~_ByteArray[ByteNumber(pIndex)];
}

void BitVector::Flip()
{
    for (int i =0; i< _SizeArray*cantidadBits ; i++){
     _ByteArray[ByteNumber(i)] = ~_ByteArray[ByteNumber(i)];
    }
}


void BitVector::insertByIndex(int pIndex,size_t pBinData)
{
    _ByteArray[pIndex] =pBinData;
}

size_t BitVector::getByIndex(int pIndex)
{
    cout << "dad" << endl;
    return (size_t)_ByteArray[pIndex];

}

size_t BitVector::Size()const {return this->_SizeArray;}



/**
 * @brief BitVector::ByteNumber: Devuelve los bits que se encuentran en el espacio indicado
 * @param pIndex: indice del "bit" al cual se desea acceder del bitVector
 * @return el indice del array al que se desea ingresar
 */
size_t BitVector::ByteNumber (size_t pIndex) const
{
  // retorna El indice / 8
  // mover hacia la derecha 3 espaciaos es equivalente y mas eficiente que dividir entre 8
  pIndex = pIndex >> 3;

  if (pIndex >= _SizeArray)
  {
    cout << "** BitVector error: pIndex out of range\n"<< endl;
    exit (EXIT_FAILURE);
  }
  return pIndex;
}

unsigned char BitVector::getArray(){return *this->_ByteArray;}


unsigned char const BitVector::bitMask (size_t pIndex)
{
  // return bitMask for pIndex % 8
  // the low order 3 bits is the remainder when dividing by 8
  size_t shiftamount = pIndex & 0x07;  // low order 3 bits
  return 0x01 << shiftamount;

  //return pIndex%cantidadBits;
}

