#ifndef BITVECTOR_H
#define BITVECTOR_H

#include "ios"
#include "iostream"


#define BitMask 00000001
#define ochoBits 00000000
#define cantidadBits 8


class BitVector
{
public:
    BitVector  (int pSize);            // Construye el bitVector con un tamaño en especifico
    BitVector  (int pSize, unsigned char *pData);
    BitVector& operator = (const BitVector& pRightAssignment);  // assignment operator with bitVector

    size_t Size ();             // Devuelve el tamaño del bitVector
    void Set   (size_t pIndex);        // Hace el bit indicado en el indice = 1
    void Unset (size_t pIndex);        //  Hace el bit indicado en el indice = 0
    void Flip  (size_t pIndex);        // cambia el bit del indice (Cambia el valor del bit )
    void Flip  ();                    // cambia todos los bits (les da vuelta)
    void andOperator(int pIndex, size_t pMask); // Aplica la operacion AND al bitVector
    void orOperator(int pIndex, unsigned char *pMask); // APlica la operacion or al bitVector

    unsigned char getByIndex(int pIndex);
    void insertByIndex(int pIndex,size_t pBinData);
    size_t getBitVectorPosicion (int pIndex) const; // se encargan de localizar en que espacio del bit vector se encuentra el bit en particular

    // la mascara necesaria para localizar el bit en particular
    unsigned char const bitMask       (int pIndex) ;// retorna el valor del bit indicado por el indice
    unsigned char *getArray();

  private:

    unsigned char*  _BitVectorData; // dato
    size_t          _BitVectorSize; // Indica el tamaño del array de bits

};

#endif // BITVECTOR_H
