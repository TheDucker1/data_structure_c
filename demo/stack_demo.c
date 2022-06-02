#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"stack.h"

/*--------------complex_struct----------------*/
typedef struct _complex_struct {
    char name[10];
    int ID;
    float special_num;
} _complex_struct;

typedef _complex_struct* _cplx_strct;
_cplx_strct cplx_strct(const char* name, int ID, float special_num) {
    _cplx_strct c = (_cplx_strct)malloc(sizeof(_complex_struct));
    assert(strlen(name) < 10);
    strcpy(c->name, name);
    c->ID = ID;
    c->special_num = special_num;
    return c;
}
void cplx_strct_free(_cplx_strct c) {
    free(c);
}
void cplx_strct_print(_cplx_strct c) {
    fprintf(stdout, "name: %s\nID: %d\nspecial_num: %f\n", c->name, c->ID, c->special_num);
}
/*--------------------------------------------*/

int main(void) {
    int i;
    
    fprintf(stdout, "int stack\n");
    stack_t s_int = stack_new(sizeof(unsigned long long));
    unsigned long long t;
    t = 1844674407370955161;
    stack_push(s_int, &t);
    t = 1844674409551615;
    stack_push(s_int, &t);
    t = 3246744073709551615;
    stack_push(s_int, &t);
    t = 146744073709551615;
    stack_push(s_int, &t);
    t = 44073709551615;
    stack_push(s_int, &t);
    t = 8446744073709551615;
    stack_push(s_int, &t);
    
    stack_pop(s_int, &t);
    fprintf(stdout, "%llu\n", t);
    stack_pop(s_int, &t);
    fprintf(stdout, "%llu\n", t);
    stack_pop(s_int, &t);
    fprintf(stdout, "%llu\n", t);
    stack_pop(s_int, &t);
    fprintf(stdout, "%llu\n", t);
    stack_pop(s_int, &t);
    fprintf(stdout, "%llu\n", t);
    stack_pop(s_int, &t);
    fprintf(stdout, "%llu\n", t);
    fprintf(stdout, "----------------\n");
    stack_free(s_int);
    
    fprintf(stdout, "float stack\n");
    stack_t s_float = stack_new(sizeof(float));
    float f;
    f = 1.02f;
    stack_push(s_int, &f);
    f = 3.14f;
    stack_push(s_int, &f);
    f = 32.293f;
    stack_push(s_int, &f);
    f = 2123.2f;
    stack_push(s_int, &f);
    f = 0.000014f;
    stack_push(s_int, &f);
    f = 2222.2222f;
    stack_push(s_int, &f);
    stack_pop(s_int, &f);
    fprintf(stdout, "%f\n", f);
    stack_pop(s_int, &f);
    fprintf(stdout, "%f\n", f);
    stack_pop(s_int, &f);
    fprintf(stdout, "%f\n", f);
    stack_pop(s_int, &f);
    fprintf(stdout, "%f\n", f);
    stack_pop(s_int, &f);
    fprintf(stdout, "%f\n", f);
    stack_pop(s_int, &f);
    fprintf(stdout, "%f\n", f);
    fprintf(stdout, "----------------\n");
    stack_free(s_float);
    
    
    
    fprintf(stdout, "complex struct stack\n");
    stack_t s_c = stack_new(sizeof(_complex_struct));
    _cplx_strct c1 = cplx_strct("David", 1, 3.14f);
    _cplx_strct c2 = cplx_strct("Jane", 2, 6.28f);
    _cplx_strct c3 = cplx_strct("Bil Gutes", 3, 1.06f);
    _cplx_strct c4 = cplx_strct("Gaben", 4, 3.00f);
    _cplx_strct c5 = cplx_strct("NULL", -1, 4.20f);
    stack_push(s_c, c2);
    stack_push(s_c, c4);
    stack_push(s_c, c3);
    stack_push(s_c, c1);
    stack_push(s_c, c5);
    cplx_strct_free(c1);
    cplx_strct_free(c2);
    cplx_strct_free(c3);
    cplx_strct_free(c4);
    cplx_strct_free(c5);
    _cplx_strct ct = cplx_strct("", 0, 0.f);
    stack_peek(s_c, ct);
    cplx_strct_print(ct);
    stack_pop(s_c, ct);
    cplx_strct_print(ct);
    stack_pop(s_c, ct);
    cplx_strct_print(ct);
    stack_pop(s_c, ct);
    cplx_strct_print(ct);
    for (i = 0; i < 6; i++) {
        stack_peek(s_c, ct);
        cplx_strct_print(ct);
    }
    stack_pop(s_c, ct);
    cplx_strct_print(ct);
    stack_pop(s_c, ct);
    cplx_strct_print(ct);
    cplx_strct_free(ct);
    stack_free(s_c);
    
    return 0;
}