#include <stdio.h>

int abs(int n)
{
	return n < 0 ? -n : n;
}

typedef struct complex_number {
	int r;
	int i;
} cn;

static const cn CNZERO = { 0, 0 };

void setr(cn* n, int r)
{
	n->r = r;
}

void seti(cn* n, int i)
{
	n->i = i;
}

int getr(cn n)
{
	return n.r;
}

int geti(cn n)
{
	return n.i;
}

void put(cn n)
{
	printf("%c%d%c%di\n", 
		getr(n) < 0 ? '\0' : '+', getr(n), 
		geti(n) < 0 ? '\0' : '+', geti(n)
	);
}

void init(cn* n, int r, int i)
{
	setr(n, r);
	seti(n, i);
}

cn make(int r, int i)
{
	cn n = CNZERO;
	init(&n, r, i);
	return n;
}

cn makeinvert(cn n)
{
	return make(-getr(n), -geti(n));
}

cn makeinvertr(cn n)
{
	return make(-getr(n), geti(n));
}

cn makeinverti(cn n)
{
	return make(getr(n), -geti(n));
}

cn makecompl(cn n)
{
	return makeinverti(n);
}

cn abscn(cn n)
{
	return make(abs(n.r), abs(n.i));
}

int cmpr(cn n1, cn n2)
{
	return getr(n1) == getr(n2);
}

int cmpi(cn n1, cn n2)
{
	return geti(n1) == geti(n2);
}

int cmp(cn n1, cn n2)
{
	return cmpr(n1, n2) && cmpi(n1, n2);
}

int iscompl(cn n1, cn n2)
{
	return cmp(n1, makecompl(n2));
}

int addr(cn n1, cn n2)
{
	return getr(n1) + getr(n2);
}

int addi(cn n1, cn n2)
{
	return geti(n1) + geti(n2);
}

int mulrr(cn n1, cn n2)
{
	return getr(n1) * getr(n2);
}

int mulii(cn n1, cn n2)
{
	return geti(n1) * geti(n2);
}

int mulri(cn n1, cn n2)
{
	return getr(n1) * geti(n2);
}

int mulir(cn n1, cn n2)
{
	return geti(n1) * getr(n2);
}

cn add(cn n1, cn n2)
{
	return make(addr(n1, n2), addi(n1, n2));
}

cn sub(cn n1, cn n2)
{
	return add(n1, makeinvert(n2));
}

cn mul(cn n1, cn n2)
{
	return make(
		mulrr(n1, n2) - mulii(n1, n2),
		mulri(n1, n2) + mulir(n1, n2)
	);
}

cn mulcr(cn n, int m)
{
	return mul(n, make(m, 0));
}

cn mulrlp(cn n, int m)
{
	cn sum;
	int sg;

	for (sg = m, m = abs(m), sum = CNZERO; m > 0; m--)
		sum = add(sum, n);

	return sg > 0 ? sum : makeinvert(sum);
}

cn __mulrrc(cn n, int m)
{
	if (m <= 1)
		return n;

	return add(n, __mulrrc(n, m - 1));
}

cn mulrrc(cn n, int m)
{
	int sign = m;

	cn sum = __mulrrc(n, abs(m));

	return sign > 0 ? sum : makeinvert(sum);
}

void test1()
{
	cn n1 = make(2, 7);
	cn n2 = make(1, -4);

	put(n1);
	put(n2);
	put(add(n1, n2));
	put(mul(n1, n2));

	for (int i = 0; i < 10; i++)
	{
		cn n3 = mul(n1, n2);
		cn n4 = add(n1, n2);
		put(mul(n3, n4));
		n1 = n3;
		n2 = n4;
	}

	cn n5 = make(3, 3);
	cn n6 = n5;
	put(n6);

	cn n7 = makecompl(n6);
	put(n7);

	printf("%d\n", iscompl(n6, n7));
	printf("%d\n", iscompl(n6, n1));
	printf("%d\n", cmp(n1, n2));
	printf("%d\n", cmp(n1, n1));
}

void test2()
{
	cn n1 = make(5, 5);
	int neg = -5;

	put(n1);
	put(mulcr(n1, 5));
	put(mulrlp(n1, 5));
	put(mulrrc(n1, 5));

	printf("%d %d \n", neg, abs(neg));

	put(mulcr(n1, -5));
	put(mulrlp(n1, -5));
	put(mulrrc(n1, -5));
}

void test3()
{
	cn n1 = make(5, 3);
	cn n2 = make(2, 5);

	put(abscn(sub(mul(n1, n1), mul(n2, n2))));

	cn n3 = make(-4, -6);
	cn n4 = make(-10, -1);

	put(abscn(sub(n3, n4)));
}

int main()
{
	//test1();
	//test2();
	test3();

	return 0;
}