// file = 0; split type = patterns; threshold = 100000; total count = 0.
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "rmapats.h"

void  hsG_0__0 (struct dummyq_struct * I1392, EBLK  * I1387, U  I619);
void  hsG_0__0 (struct dummyq_struct * I1392, EBLK  * I1387, U  I619)
{
    U  I1655;
    U  I1656;
    U  I1657;
    struct futq * I1658;
    struct dummyq_struct * pQ = I1392;
    I1655 = ((U )vcs_clocks) + I619;
    I1657 = I1655 & ((1 << fHashTableSize) - 1);
    I1387->I665 = (EBLK  *)(-1);
    I1387->I666 = I1655;
    if (0 && rmaProfEvtProp) {
        vcs_simpSetEBlkEvtID(I1387);
    }
    if (I1655 < (U )vcs_clocks) {
        I1656 = ((U  *)&vcs_clocks)[1];
        sched_millenium(pQ, I1387, I1656 + 1, I1655);
    }
    else if ((peblkFutQ1Head != ((void *)0)) && (I619 == 1)) {
        I1387->I668 = (struct eblk *)peblkFutQ1Tail;
        peblkFutQ1Tail->I665 = I1387;
        peblkFutQ1Tail = I1387;
    }
    else if ((I1658 = pQ->I1295[I1657].I688)) {
        I1387->I668 = (struct eblk *)I1658->I686;
        I1658->I686->I665 = (RP )I1387;
        I1658->I686 = (RmaEblk  *)I1387;
    }
    else {
        sched_hsopt(pQ, I1387, I1655);
    }
}
#ifdef __cplusplus
extern "C" {
#endif
void SinitHsimPats(void);
#ifdef __cplusplus
}
#endif
