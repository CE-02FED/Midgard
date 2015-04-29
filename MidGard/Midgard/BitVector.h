#ifndef BITVECTOR_H
#define BITVECTOR_H

#include "ios"
#include "iostream"


#define BitMask 00000001
#define ochoBits 00000000
#define cantidadBits 8

using namespace std ;

class BitVector
{
public:
    BitVector  (size_t pSize);            // Construye el bitVector con un tamaño en especifico
    BitVector  (const BitVector&);  // copia el constructor
                  // destructor

    BitVector& operator = (const BitVector& pRightAssignment);  // assignment operator with bitVector


    size_t Size () const;             // Devuelve el tamaño del bitVector

    void Set   (size_t pIndex);        // Hace el bit indicado en el indice = 1
    void Set   ();                    // Hace todos los bits = 1
    void Unset (size_t pIndex);        //  Hace el bit indicado en el indice = 0
    void Unset ();                    // Hace todos los bits = 0
    void Flip  (size_t pIndex);        // cambia el bit del indice (Cambia el valor del bit )
    void Flip  ();                    // cambia todos los bits (les da vuelta)
    void andOperator(int pIndex, size_t pMask);


    size_t getByIndex(int pIndex);

    void insertByIndex(int pIndex,size_t pBinData);
    void orOperator(int pIndex,size_t pMask);

    // methods
    size_t               ByteNumber (size_t pIndex) const; // se encargan de localizar un bit en particular

    // la mascara necesaria para localizar el bit en particular
    static const unsigned char bitMask       (size_t pIndex) ;// retorna el valor del bit indicado por el indice

    unsigned char getArray();

    BitVector& operator = (int[]);  // assignment operator

  private:

    unsigned char * _ByteArray; // dato
    size_t          _SizeArray=0; // Indica el tamaño del array de bits




};

#endif // BITVECTOR_H
