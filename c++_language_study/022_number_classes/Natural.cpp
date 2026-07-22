#include "Natural.h"

Natural::Natural()
{
    n = 0;
}

Natural::Natural(int number)
{
    setNumber(number < 0 ? 0 : number);
}

Natural::Natural(const Natural& natural)
{
    Natural(natural.getNumber());
}

int Natural::getNumber() const
{
    return n;
}

void Natural::setNumber(unsigned number)
{
    n = number;
}

Compare Natural::compare(Natural n)
{
    if (getNumber() > n.getNumber())
        return Compare::GT;
    else if (getNumber() < n.getNumber())
        return Compare::LT;
    else
        return Compare::EQ;
}

Natural Natural::add(Natural n)
{
    return Natural(getNumber() + n.getNumber());
}

Natural Natural::sub(Natural n)
{
    return Natural(getNumber() - n.getNumber());
}

Natural Natural::mul(Natural n)
{
    return Natural(getNumber() * n.getNumber());
}


Compare::Compare(const COMPARE& result)
{
    res = result;
}

Compare::Compare()
{
    res = COMPARE::EQ;
}

Compare Compare::invertResult()
{
    switch (res)
    {
    case COMPARE::EQ:   return COMPARE::NEQ;
    case COMPARE::NEQ:  return COMPARE::EQ;
    case COMPARE::GT:   return COMPARE::LEQ;
    case COMPARE::LEQ:  return COMPARE::GT;
    case COMPARE::LT:   return COMPARE::GEQ;
    case COMPARE::GEQ:  return COMPARE::LT;
    }
}

Compare::COMPARE Compare::getResult()
{
    return res;
}

bool Compare::equal(Compare result)
{
    if (result.res == Compare::NEQ) {
        switch (res)
        {
        case Compare::LT:   case Compare::LEQ:
        case Compare::GEQ:  case Compare::GT:
        case Compare::NEQ:
            return true;
        case Compare::EQ:
            return false;
        }
    }

    return res == result.res;
}
