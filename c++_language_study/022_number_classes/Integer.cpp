#include "Integer.h"
#include <math.h>

Integer::Integer()
{
    Integer(0, Sign::PLUS);
}

Integer::Integer(int in)
{
    Integer(Natural(abs(in)), in < 0 ? Sign::MINUS : Sign::PLUS);
}

Integer::Integer(Natural q)
{
    Integer(q, Sign::PLUS);
}

Integer::Integer(int q, Sign s)
{
    Integer(Natural(abs(q)), s);
}

Integer::Integer(const Integer& i)
{
    Integer(i.getQuantity(), i.getSign());
}

Integer::Integer(Natural q, Sign s)
{
    init(q, s);
}

Natural Integer::getQuantity() const
{
    return quantity;
}

Sign Integer::getSign() const
{
    return sign;
}

Integer Integer::add(Integer i)
{
    if (compareSign(i) && getSign().isPlus() || getSign().isMinus())
        return Integer(getQuantity().add(i.getQuantity()), getSign());
    else
    {
        if (compareQuantity(i) == CMP::GT || compareQuantity(i) == CMP::EQ)
            return Integer(getQuantity().sub(i.getQuantity()),
                getSign().isPlus() ? getSign() : getSign().invertSign());
        else
            return Integer(i.getQuantity().sub(getQuantity()),
            i.getSign().isPlus() ? i.getSign() : i.getSign().invertSign());
    }
}

Integer Integer::sub(Integer i)
{
    return add(Integer(i.getQuantity(), i.getSign().invertSign()));
}

Integer Integer::mul(Integer i)
{
    return Integer(getQuantity().mul(i.getQuantity()), getSign().mul(i.getSign()));
}

void Integer::init(Natural q, Sign s)
{
    quantity = q;
    sign = s;
}

bool Integer::compareSign(Integer i)
{
    return getSign().equal(i.getSign());
}

Compare Integer::compareQuantity(Integer i)
{
    return getQuantity().compare(i.getQuantity());
}

Compare Integer::compare(Integer i)
{
    if (compareSign(i) && getSign().isPlus())
        return compareQuantity(i);
    else if (compareSign(i) && getSign().isMinus())
        return compareQuantity(i);
    
    if(compareQuantity(i).equal(Compare::GT) && getSign().isPlus())
        return 
 
}

Compare Integer::compare(int i)
{
    return compare(Integer(i));
}

/*                           */
// Definition for Sign Class //
/*                           */
Sign::Sign()
{
    sign = Sign::PLUS;
}

Sign::Sign(SIGN s)
{
    sign = s;
}

bool Sign::isPlus()
{
    return sign == Sign::PLUS;
}

bool Sign::isMinus()
{
    return !isPlus();
}

bool Sign::equal(Sign s)
{
    return getSign() == s.getSign();
}

Sign Sign::mul(Sign s)
{
    if (isPlus() && s.isPlus() ||
        isMinus() && s.isMinus())
        return Sign(SIGN::PLUS);
    else
        return Sign(SIGN::MINUS);
}

Sign::SIGN Sign::getSign()
{
    return sign;
}

Sign Sign::invertSign()
{
    return isPlus() ? getSign() : Sign(SIGN::MINUS);
}
