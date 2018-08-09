//
//  Skein.h
//  kizunawallet
//
//  Created by Bin on 2018/7/6.
//  Copyright © 2018 Aaron Voisine. All rights reserved.
//

#ifndef Skein_h
#define Skein_h

#include <stdio.h>
#include "sph_types.h"

#define SPH_SIZE_skein512   512

typedef struct {
#ifndef DOXYGEN_IGNORE
    unsigned char buf[64];    /* first field, for alignment */
    size_t ptr;
    sph_u64 h0, h1, h2, h3, h4, h5, h6, h7;
    sph_u64 bcount;
#endif
} sph_skein_big_context;
void sph_skein512_init(void *cc);
void sph_skein512(void *cc, const void *data, size_t len);
void sph_skein512_addbits_and_close(void *cc, unsigned ub, unsigned n, void *dst);
void sph_skein512_close(void *cc, void *dst);


#endif /* Skein_h */
