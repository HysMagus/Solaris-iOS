//
//  xevan.c
//  kizunawallet
//
//  Created by Bin on 2018/7/6.
//  Copyright © 2018 Aaron Voisine. All rights reserved.
//

#include "xevan.h"



#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "sph/sph_blake.h"
#include "sph/sph_bmw.h"
#include "sph/sph_groestl.h"
#include "sph/sph_jh.h"
#include "sph/sph_keccak.h"
#include "sph/sph_skein.h"
#include "sph/sph_luffa.h"
#include "sph/sph_cubehash.h"
#include "sph/sph_shavite.h"
#include "sph/sph_simd.h"
#include "sph/sph_echo.h"
#include "sph/sph_hamsi.h"
#include "sph/sph_fugue.h"
#include "sph/sph_shabal.h"
#include "sph/sph_whirlpool.h"
#include "sph/sph_sha2.h"
#include "sph/sph_haval.h"

typedef struct {
    sph_blake512_context    blake1;
    sph_bmw512_context      bmw1;
    sph_groestl512_context  groestl1;
    sph_skein512_context    skein1;
    sph_jh512_context       jh1;
    sph_keccak512_context   keccak1;
    sph_luffa512_context    luffa1;
    sph_cubehash512_context cubehash1;
    sph_shavite512_context  shavite1;
    sph_simd512_context     simd1;
    sph_echo512_context     echo1;
    sph_hamsi512_context    hamsi1;
    sph_fugue512_context    fugue1;
    sph_shabal512_context   shabal1;
    sph_whirlpool_context   whirlpool1;
    sph_sha512_context      sha512;
    sph_haval256_5_context  haval1;
} Xhash_context_holder;

static Xhash_context_holder base_contexts;
void init_xevanhash_contexts()
{
    sph_blake512_init(&base_contexts.blake1);
    sph_bmw512_init(&base_contexts.bmw1);
    sph_groestl512_init(&base_contexts.groestl1);
    sph_skein512_init(&base_contexts.skein1);
    sph_jh512_init(&base_contexts.jh1);
    sph_keccak512_init(&base_contexts.keccak1);
    sph_luffa512_init(&base_contexts.luffa1);
    sph_cubehash512_init(&base_contexts.cubehash1);
    sph_shavite512_init(&base_contexts.shavite1);
    sph_simd512_init(&base_contexts.simd1);
    sph_echo512_init(&base_contexts.echo1);
    sph_hamsi512_init(&base_contexts.hamsi1);
    sph_fugue512_init(&base_contexts.fugue1);
    sph_shabal512_init(&base_contexts.shabal1);
    sph_whirlpool_init (&base_contexts.whirlpool1);
    sph_sha512_init(&base_contexts.sha512);
    sph_haval256_5_init(&base_contexts.haval1);
}
void xevan_hash(const char* input, char* state, int version)
{
    init_xevanhash_contexts();
    
    Xhash_context_holder ctx;
    
    uint32_t hash[32];
    
    memset(hash, 0, 128);
    memcpy(&ctx, &base_contexts, sizeof(base_contexts));
    if(version == 4){
        sph_blake512 (&ctx.blake1, input, 112);
    } else
        sph_blake512 (&ctx.blake1, input, 80);
    sph_blake512_close (&ctx.blake1, hash);
    
    sph_bmw512 (&ctx.bmw1, hash, 128);
    sph_bmw512_close(&ctx.bmw1, hash);
    
    sph_groestl512 (&ctx.groestl1, hash, 128);
    sph_groestl512_close(&ctx.groestl1, hash);
    
    sph_skein512 (&ctx.skein1, hash, 128);
    sph_skein512_close(&ctx.skein1, hash);
    
    sph_jh512 (&ctx.jh1, hash, 128);
    sph_jh512_close(&ctx.jh1, hash);
    
    sph_keccak512 (&ctx.keccak1, hash, 128);
    sph_keccak512_close(&ctx.keccak1, hash);
    
    sph_luffa512 (&ctx.luffa1, hash, 128);
    sph_luffa512_close (&ctx.luffa1, hash);
    
    sph_cubehash512 (&ctx.cubehash1, hash, 128);
    sph_cubehash512_close(&ctx.cubehash1, hash);
    
    sph_shavite512 (&ctx.shavite1, hash, 128);
    sph_shavite512_close(&ctx.shavite1, hash);
    
    sph_simd512 (&ctx.simd1, hash, 128);
    sph_simd512_close(&ctx.simd1, hash);
    
    sph_echo512 (&ctx.echo1, hash, 128);
    sph_echo512_close(&ctx.echo1, hash);
    
    sph_hamsi512 (&ctx.hamsi1, hash, 128);
    sph_hamsi512_close(&ctx.hamsi1, hash);
    
    sph_fugue512 (&ctx.fugue1, hash, 128);
    sph_fugue512_close(&ctx.fugue1, hash);
    
    sph_shabal512 (&ctx.shabal1, hash, 128);
    sph_shabal512_close(&ctx.shabal1, hash);
    
    sph_whirlpool (&ctx.whirlpool1, hash, 128);
    sph_whirlpool_close(&ctx.whirlpool1, hash);
    
    sph_sha512 (&ctx.sha512, hash, 128);
    sph_sha512_close(&ctx.sha512, hash);
    
    sph_haval256_5 (&ctx.haval1, hash, 128);
    sph_haval256_5_close(&ctx.haval1, hash);
    
    memset(&hash[8], 0, 128 - 32);
    sph_blake512 (&ctx.blake1, hash, 128);
    sph_blake512_close (&ctx.blake1, hash);
    
    sph_bmw512 (&ctx.bmw1, hash, 128);
    sph_bmw512_close(&ctx.bmw1, hash);
    
    sph_groestl512 (&ctx.groestl1, hash, 128);
    sph_groestl512_close(&ctx.groestl1, hash);
    
    sph_skein512 (&ctx.skein1, hash, 128);
    sph_skein512_close(&ctx.skein1, hash);
    
    sph_jh512 (&ctx.jh1, hash, 128);
    sph_jh512_close(&ctx.jh1, hash);
    
    sph_keccak512 (&ctx.keccak1, hash, 128);
    sph_keccak512_close(&ctx.keccak1, hash);
    
    sph_luffa512 (&ctx.luffa1, hash, 128);
    sph_luffa512_close (&ctx.luffa1, hash);
    
    sph_cubehash512 (&ctx.cubehash1, hash, 128);
    sph_cubehash512_close(&ctx.cubehash1, hash);
    
    sph_shavite512 (&ctx.shavite1, hash, 128);
    sph_shavite512_close(&ctx.shavite1, hash);
    
    sph_simd512 (&ctx.simd1, hash, 128);
    sph_simd512_close(&ctx.simd1, hash);
    
    sph_echo512 (&ctx.echo1, hash, 128);
    sph_echo512_close(&ctx.echo1, hash);
    
    sph_hamsi512 (&ctx.hamsi1, hash, 128);
    sph_hamsi512_close(&ctx.hamsi1, hash);
    
    sph_fugue512 (&ctx.fugue1, hash, 128);
    sph_fugue512_close(&ctx.fugue1, hash);
    
    sph_shabal512 (&ctx.shabal1, hash, 128);
    sph_shabal512_close(&ctx.shabal1, hash);
    
    sph_whirlpool (&ctx.whirlpool1, hash, 128);
    sph_whirlpool_close(&ctx.whirlpool1, hash);
    
    sph_sha512 (&ctx.sha512, hash, 128);
    sph_sha512_close(&ctx.sha512, hash);
    
    sph_haval256_5 (&ctx.haval1, hash, 128);
    sph_haval256_5_close(&ctx.haval1, hash);
    
    memcpy(state, hash, 32);
    
}

