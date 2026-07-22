#include "Bool.h"

Bool::Bool() : Bool(BoolValue::TRUE)
{
}

Bool::Bool(bool v) : Bool(v ? BoolValue::TRUE : BoolValue::FALSE)
{
}

Bool::Bool(BoolValue v) : _v(v)
{
}

BoolValue Bool::getValue()
{
    return _v;
}

Bool Bool::makeTrue()
{
    return Bool(BoolValue::TRUE);
}

Bool Bool::makeFalse()
{
    return Bool(BoolValue::FALSE);
}

/*
// Should not use existing boolean operators such as &&, || or !
// Operators that return a boolean object
//   &&, ||, !, ==, !=, <, >, <=, >=
// Represent boolean operators &&, || with ==, !=, !
*/

//  X   Y   X.And(Y)
//  T   T      T
//  T   F      F
//  F   T      F
//  F   F      F
Bool Bool::And(Bool b)
{
    //return isTrue() && b.isTrue() ? makeTrue() : makeFalse();
    //
    //return isTrue() ? 
    //           b.isTrue() ? makeTrue() : makeFalse() :
    //            b.isTrue() ? makeFalse() : makeFalse();

    //if (isTrue()) 
    //    return b.isTrue() ? makeTrue() : makeFalse();
    //else
    //    return b.isTrue() ? makeFalse() : makeFalse();

    if (isFalse())
        return makeFalse();
    if (b.isFalse())
        return makeFalse();

    return makeTrue();

    //if (isTrue())
    //{
    //    if (b.isTrue())
    //        return makeTrue();
    //    else
    //        return makeFalse();
    //}
    //else
    //{
    //    if (b.isTrue())
    //        return makeFalse();
    //    else
    //        return makeFalse();
    //}

    ////Write in minterms
    // (T, T) -> if-1, 4 
    // (T, F) -> if-2, 3
    // (F, T) -> if-2, 3
    // (F, F) -> if-1
    //
    //if (isTrue().eq(b.isTrue()))
    //    return makeTrue();
    //if (isTrue().eq(b.Not().isTrue()))
    //    return makeFalse();
    //if (Not().isTrue().eq(b.isTrue()))
    //    return makeFalse();
    //if (Not().isTrue().eq(b.Not().isTrue()))
    //    return makeFalse();

    // 
    //if (isTrue().eq(b.isTrue()))
    //    return makeTrue();
    //if (isTrue().neq(b.isFalse()))
    //    return makeFalse();
    //if (isFalse().neq(b.isTrue()))
    //    return makeFalse();
    //if (isFalse().eq(b.isFalse()))
    //    return makeFalse();
}

//  X   Y   X.Or(Y)
//  T   T     T
//  T   F     T
//  F   T     T
//  F   F     F
Bool Bool::Or(Bool b)
{
    if (isTrue())
        return makeTrue();
    if (b.isTrue())
        return makeTrue();

    return makeFalse();

    //Write in minterms
    //if (isTrue().eq(b.isTrue()))
    //    return makeTrue();
    //if (isTrue().eq(b.Not().isTrue()))
    //    return makeTrue();
    //if (Not().isTrue().eq(b.isTrue()))
    //    return makeTrue();
    //if (Not().isTrue().eq(b.Not().isTrue()))
    //    return makeFalse();

    //if (isTrue().eq(b.isTrue()))
    //    return makeTrue();
    //if (isTrue().neq(b.isFalse()))
    //    return makeTrue();
    //if (isFalse().neq(b.isTrue()))
    //    return makeTrue();
    //if (isFalse().eq(b.isFalse()))
    //    return makeFalse();
}

//  X   Y   X.Xor(Y)
//  T   T     F
//  T   F     T
//  F   T     T
//  F   F     F
Bool Bool::Xor(Bool b)
{
    return eq(b) ? makeFalse() : makeTrue();
}

Bool Bool::Nand(Bool b)
{
    return And(b).Not();
}

Bool Bool::Nor(Bool b)
{
    return Or(b).Not();
}

Bool Bool::Not()
{
    return isTrue() ? makeFalse() : makeTrue();
}

Bool Bool::eq(Bool b)
{
    return getValue() == b.getValue() ? makeTrue() : makeFalse();
}

Bool Bool::neq(Bool b)
{
    return eq(b).Not();
}

Bool Bool::isTrue()
{
    return eq(makeTrue());
}

Bool Bool::isFalse()
{
    return isTrue().Not();
}

Bool::operator bool()
{
    return getValue() == BoolValue::TRUE ? true : false;
}
