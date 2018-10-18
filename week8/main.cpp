#include <iostream>
#define MAX(a, b) a > b ? a : b
#define MAX_DEGREE 50

typedef struct Term {
    float coef;
    int expo;
    struct Term * next;
} Term;

typedef struct Polynomial{
    Term * head;
    Term * cur;
    Term * tail;
    int degree; // 최고차항
    int length; // 길이
} Polynomial;


Polynomial * createPoly() {
    Polynomial * poly = new Polynomial;
    poly->head = nullptr;
    poly->cur = nullptr;
    poly->tail = nullptr;
    poly->degree = 0;
    poly->length = 0;
    return poly;
}

void addTerm(Polynomial * poly, float coef, int expo) {
    Term * term = new Term;
    term->coef = coef;
    term->expo = expo;
    term->next = nullptr;

    if(!poly->head) { // 공백일경우
        poly->head = term;
        poly->tail = term;
        poly->degree = term->expo;
    } else { // 공백이 아닐경우
        Term * cur = poly->head;
        while(cur != poly->tail) { // 맨끝으로 이동
            cur = cur->next;
        }
        // 연결
        cur->next = term;
        poly->tail = term;
    }
    (poly->length)++;
}

void printPoly(Polynomial * poly) {
    Term * cur = poly->head;
    while(cur != poly->tail) {
        std::cout << cur->coef << "x^" << cur->expo << " + ";
        cur = cur->next;
    }
    std::cout << cur->coef << "x^" << cur->expo << std::endl;
    std::cout << std::endl;
}


void addPoly(Polynomial * poly, Polynomial * a, Polynomial * b) {
    // a의 현재위치와 b의 현재위치

    Term * aCur = a->head;
    Term * bCur = b->head;
    if(!b->head) {
        printf("1");
        while(aCur != a->tail) {
            addTerm(poly, aCur->coef, aCur->expo);
            printf("2");
            aCur = aCur->next;
        }
        printf("3");
        addTerm(poly, aCur->coef, aCur->expo);
        return;
    } else {
        while(aCur != a->tail || bCur != b->tail) {
            if(aCur->expo > bCur->expo) {
                addTerm(poly, aCur->coef, aCur->expo);
                aCur = aCur->next;
            } else if(aCur->expo == bCur->expo) {
                int expo = aCur->expo;
                float coef = aCur->coef + bCur->coef;
                addTerm(poly, coef, expo);
                aCur = aCur->next;
                bCur = bCur->next;
            } else {
                addTerm(poly, bCur->coef, bCur->expo);
                bCur = bCur->next;
            }
        }
        int constant = aCur->coef + bCur->coef;
        addTerm(poly, constant, 0);
    }
}

void multiPoly(Polynomial * poly, Polynomial * a, Polynomial * b) {
    Term * aCur = a->head;
    Term * bCur = b->head;

    // a 반복
    while(aCur != a->tail) {
        int coef = 0;
        int expo = 0;
        Polynomial * temp = new Polynomial;
        temp->head = nullptr;
        temp->tail = nullptr;
        temp->length = 0;
        temp->degree = 0;
        // b 반복
        while(bCur != b->tail) {
            coef = aCur->coef * bCur->coef;
            expo = aCur->expo + bCur->expo;
            addTerm(temp, coef, expo);
            bCur = bCur->next;
        }
        coef = aCur->coef * bCur->coef;
        expo = aCur->expo + bCur->expo;
        addTerm(temp, coef, expo);
        // poly 가 null임
        addPoly(poly, temp, poly);
        aCur = aCur->next;
        printf("fuck");
    }

//    return multiedPoly;
}

int main(void) {
    Polynomial * a = createPoly();
    Polynomial * b = createPoly();
    Polynomial * c = createPoly();
    Polynomial * d = createPoly();

    addTerm(a, 4, 5);
    addTerm(a, 7, 4);
    addTerm(a, 1, 3);
    addTerm(a, 2, 1);
    addTerm(a, 5, 0);

    addTerm(b, 8, 4);
    addTerm(b, 3, 3);
    addTerm(b, 5, 2);
    addTerm(b, 2, 1);
    addTerm(b, 1, 0);

    printPoly(a);
    printPoly(b);

    addPoly(c, a, b);
    printPoly(c);

    multiPoly(d, a, b);
    printPoly(d);


}
