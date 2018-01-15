#ifndef sstmac_replacements_fix_intrinsics_h
#define sstmac_replacements_fix_intrinsics_h

/** functions that are static in gcc and not static in clang
    change their names temporarily to get clang to not freak out */
#define __rdtsc __redirect_rdtsc

#define _mm_getcsr __redirect_mm_getcsr

#define _mm_sfence __redirect_mm_sfence

#define _mm_setcsr __redirect__mm_setcsr

#define _mm_clflush __redirect_mm_clflush

#define _mm_lfence __redirect_mm_lfence

#define _mm_pause __redirect_mm_pause

#define _mm_mfence __redirect_mm_mfence

/** these are void return intrinsics that clang doesn't know */
#define __builtin_ia32_storeups(...)

#define __builtin_ia32_movntps(...)

#define __builtin_ia32_storeupd256(...)

#define __builtin_ia32_storeups256(...)

#define __builtin_ia32_storedqu256(...)

#define __builtin_ia32_movntdq256(...)

#define __builtin_ia32_movntpd256(...)

#define __builtin_ia32_movntps256(...)

/** these are unary operator intrinsics that return the same type thing
    just return the input argument to satisfy clang during src-2-src */
#define __builtin_ia32_cvtps2pd(x) x

#define __builtin_ia32_cvtdq2pd(x) x

#define __builtin_ia32_pmovzxbw128(x) x

#define __builtin_ia32_pmovzxbd128(x) x

#define __builtin_ia32_pmovzxbq128(x) x

#define __builtin_ia32_pmovzxwq128(x) x

#define __builtin_ia32_pmovzxdq128(x) x

#define __builtin_ia32_pmovzxwd128(x) x

#define __builtin_ia32_cvtdq2pd256(x) get256()

#define __builtin_ia32_cvtps2pd256(x) get256d()

#define __builtin_ia32_pmovsxbw256(x) get256i()

#define __builtin_ia32_pmovsxbd256(x) get256i()

#define __builtin_ia32_pmovsxbq256(x) get256i()

#define __builtin_ia32_pmovsxwq256(x) get256i()

#define __builtin_ia32_pmovsxwd256(x) get256i()

#define __builtin_ia32_pmovsxdq256(x) get256i()

#define __builtin_ia32_pmovzxbw256(x) get256i()

#define __builtin_ia32_pmovzxbd256(x) get256i()

#define __builtin_ia32_pmovzxbq256(x) get256i()

#define __builtin_ia32_pmovzxwd256(x) get256i()

#define __builtin_ia32_pmovzxwq256(x) get256i()

#define __builtin_ia32_pmovzxdq256(x) get256i()

#define __builtin_ia32_pandd512_mask(...) get512i()

#define __builtin_ia32_pandq512_mask(...) get512i()

#define __builtin_ia32_pandnd512_mask(...) get512i()

#define __builtin_ia32_pandnq512_mask(...) get512i()

#define __builtin_ia32_pord512_mask(...) get512i()

#define __builtin_ia32_porq512_mask(...) get512i()

#define __builtin_ia32_pxord512_mask(...) get512i()

#define __builtin_ia32_pxorq512_mask(...) get512i()

#define __builtin_ia32_paddq512_mask(...) get512i()

#define __builtin_ia32_psubq512_mask(...) get512i()

#define __builtin_ia32_paddd512_mask(...) get512i()

#define __builtin_ia32_psubd512_mask(...) get512i()

#define __builtin_ia32_loaddqudi512_mask(...) get512i()

#define __builtin_ia32_maxss_round(x,...) x

#define __builtin_ia32_maxsd_round(x,...) x

#define __builtin_ia32_minss_round(x,...) x

#define __builtin_ia32_minsd_round(x,...) x

#define __builtin_ia32_pmuldq512_mask(x,...) x

#define __builtin_ia32_pmuludq512_mask(x,...) x

#define __builtin_ia32_rsqrt14ss(x,...) x

#define __builtin_ia32_pmulld512_mask(x,...) x

#define __builtin_ia32_rsqrt14sd(x,...) x

#define __builtin_ia32_rcp14ss(x,...) x

#define __builtin_ia32_addss_round(x,...) x

#define __builtin_ia32_subss_round(x,...) x

#define __builtin_ia32_mulss_round(x,...) x

#define __builtin_ia32_rcp14sd(x,...) x

#define __builtin_ia32_addsd_round_mask(x,...) x

#define __builtin_ia32_subsd_round(x,...) x

#define __builtin_ia32_divsd_round(x,...) x

#define __builtin_ia32_blendmpd_512_mask(x,...) x

#define __builtin_ia32_blendmps_512_mask(x,...) x

#define __builtin_ia32_blendmq_512_mask(x,...) x

#define __builtin_ia32_cvtdq2pd512_mask(...) get512d()

#define __builtin_ia32_addsd_round(x,...) x

#define __builtin_ia32_divss_round(x,...) x

#define __builtin_ia32_mulsd_round(x,...) x

#define __builtin_ia32_blendmd_512_mask(x,...) x

#define __builtin_ia32_cvtudq2pd512_mask(...) get512d()

#define __builtin_ia32_loaddqusi512_mask(...) get512i()

#define __builtin_ia32_loadups512_mask(...) get512i()

#define __builtin_ia32_loadupd512_mask(...) get512d()

#define __builtin_ia32_storeupd512_mask(...)

#define __builtin_ia32_storedqudi512_mask(...) 

#define __builtin_ia32_storedqusi512_mask(...)

#define __builtin_ia32_storeups512_mask(...)

#define __builtin_ia32_paddd256_mask(x,...) x

#define __builtin_ia32_paddq256_mask(x,...) x

#define __builtin_ia32_psubd256_mask(x,...) x

#define __builtin_ia32_psubq256_mask(x,...) x

#define __builtin_ia32_paddd128_mask(x,...) x

#define __builtin_ia32_paddq128_mask(x,...) x

#define __builtin_ia32_psubd128_mask(x,...) x

#define __builtin_ia32_psubq128_mask(x,...) x

#define __builtin_ia32_pmuldq128_mask(x,...) x

#define __builtin_ia32_pmuludq128_mask(x,...) x

#define __builtin_ia32_pmuldq256_mask(x,...) x

#define __builtin_ia32_pmuludq256_mask(x,...) x

#define __builtin_ia32_pmulld256_mask(x,...) x

#define __builtin_ia32_pmulld128_mask(x,...) x

#define __builtin_ia32_pandd256_mask(x,...) x

#define __builtin_ia32_pandnd256_mask(x,...) x

#define __builtin_ia32_pandnd128_mask(x,...) x

#define __builtin_ia32_pord256_mask(x,...) x

#define __builtin_ia32_pord128_mask(x,...) x

#define __builtin_ia32_pandd128_mask(x,...) x

#define __builtin_ia32_pxord256_mask(x,...) x

#define __builtin_ia32_pxord128_mask(x,...) x

#define __builtin_ia32_pandq256_mask(x,...) x

#define __builtin_ia32_pandq128_mask(x,...) x

#define __builtin_ia32_pandnq256_mask(x,...) x

#define __builtin_ia32_pandnq128_mask(x,...) x

#define __builtin_ia32_porq256_mask(x,...) x

#define __builtin_ia32_porq128_mask(x,...) x

#define __builtin_ia32_pxorq256_mask(x,...) x

#define __builtin_ia32_addpd128_mask(x,...) x

#define __builtin_ia32_addps256_mask(x,...) x

#define __builtin_ia32_pxorq128_mask(x,...) x

#define __builtin_ia32_addps128_mask(x,...) x

#define __builtin_ia32_addpd256_mask(x,...) x

#define __builtin_ia32_blendmd_128_mask(x,...) x

#define __builtin_ia32_blendmd_256_mask(x,...) x

#define __builtin_ia32_blendmps_256_mask(x,...) x

#define __builtin_ia32_blendmq_256_mask(x,...) x

#define __builtin_ia32_cvtdq2pd128_mask(x,...) x

#define __builtin_ia32_cvtdq2pd256_mask(x,...) get256d()

#define __builtin_ia32_blendmpd_128_mask(x,...) x

#define __builtin_ia32_blendmpd_256_mask(x,...) x

#define __builtin_ia32_blendmq_128_mask(x,...) x

#define __builtin_ia32_cvtudq2pd128_mask(x,...) x

#define __builtin_ia32_divpd256_mask(x,...) x

#define __builtin_ia32_blendmps_128_mask(x,...) x

#define __builtin_ia32_cvtudq2pd256_mask(...) get256d()

#define __builtin_ia32_divpd_mask(x,...) x

#define __builtin_ia32_divps_mask(x,...) x

#define __builtin_ia32_divps256_mask(x,...) x

#define __builtin_ia32_maxpd_mask(x,...) x

#define __builtin_ia32_maxps_mask(x,...) x

#define __builtin_ia32_maxps256_mask(x,...) x

#define __builtin_ia32_maxpd256_mask(x,...) x

#define __builtin_ia32_minpd256_mask(x,...) x

#define __builtin_ia32_minpd_mask(x,...) x

#define __builtin_ia32_minps_mask(x,...) x

#define __builtin_ia32_minps256_mask(x,...) x

#define __builtin_ia32_mulpd_mask(x,...) x

#define __builtin_ia32_mulpd256_mask(x,...) x

#define __builtin_ia32_mulps_mask(x,...) x

#define __builtin_ia32_mulps256_mask(x,...) x

#define __builtin_ia32_pabsd128_mask(x,...) x

#define __builtin_ia32_pabsd256_mask(x,...) x

#define __builtin_ia32_pmaxsd128_mask(x,...) x

#define __builtin_ia32_pmaxsd256_mask(x,...) x

#define __builtin_ia32_pmaxud128_mask(x,...) x

#define __builtin_ia32_pminsd128_mask(x,...) x

#define __builtin_ia32_pmaxud256_mask(x,...) x

#define __builtin_ia32_pminsd256_mask(x,...) x

#define __builtin_ia32_pminud128_mask(x,...) x

#define __builtin_ia32_pminud256_mask(x,...) x

#define __builtin_ia32_sqrtpd128_mask(x,...) x

#define __builtin_ia32_sqrtpd256_mask(x,...) x

#define __builtin_ia32_sqrtps128_mask(x,...) x

#define __builtin_ia32_subpd128_mask(x,...) x

#define __builtin_ia32_subps128_mask(x,...) x

#define __builtin_ia32_subps256_mask(x,...) x

#define __builtin_ia32_sqrtps256_mask(x,...) x

#define __builtin_ia32_subpd256_mask(x,...) x

#define __builtin_ia32_paddb512_mask(x,...) x

#define __builtin_ia32_packusdw512_mask(x,...) x

#define __builtin_ia32_psubb512_mask(x,...) x

#define __builtin_ia32_paddw512_mask(x,...) x

#define __builtin_ia32_psubw512_mask(x,...) x

#define __builtin_ia32_pmullw512_mask(x,...) x

#define __builtin_ia32_packssdw512_mask(x,...) x

#define __builtin_ia32_packsswb512_mask(x,...) x

#define __builtin_ia32_blendmw_512_mask(x,...) x

#define __builtin_ia32_packuswb512_mask(x,...) x

#define __builtin_ia32_pshufb512_mask(x,...) x

#define __builtin_ia32_punpckhbw512_mask(x,...) x

#define __builtin_ia32_punpckhwd512_mask(x,...) x

#define __builtin_ia32_blendmb_512_mask(x,...) x

#define __builtin_ia32_punpcklbw512_mask(x,...) x

#define __builtin_ia32_punpcklwd512_mask(x,...) x

#define __builtin_ia32_pmullq512_mask(x,...) x

#define __builtin_ia32_pmulhw512_mask(x,...) x

#define __builtin_ia32_xorpd512_mask(x,...) x

#define __builtin_ia32_sqrtps512_mask(x,...) x

#define __builtin_ia32_xorps512_mask(x,...) x

#define __builtin_ia32_orpd512_mask(x,...) x

#define __builtin_ia32_paddw256_mask(x,...) x

#define __builtin_ia32_paddb256_mask(x,...) x

#define __builtin_ia32_orps512_mask(x,...) x

#define __builtin_ia32_andpd512_mask(x,...) x

#define __builtin_ia32_andps512_mask(x,...) x

#define __builtin_ia32_andnpd512_mask(x,...) x

#define __builtin_ia32_andnps512_mask(x,...) x

#define __builtin_ia32_psubb256_mask(x,...) x

#define __builtin_ia32_psubw256_mask(x,...) x

#define __builtin_ia32_paddb128_mask(x,...) x

#define __builtin_ia32_paddw128_mask(x,...) x

#define __builtin_ia32_blendmb_256_mask(x,...) x

#define __builtin_ia32_blendmw_256_mask(x,...) x

#define __builtin_ia32_pmullw256_mask(x,...) x 

#define __builtin_ia32_psubb128_mask(x,...) x

#define __builtin_ia32_psubsb512_mask(x,...) x

#define __builtin_ia32_psubsw512_mask(x,...) x

#define __builtin_ia32_psubw128_mask(x,...) x

#define __builtin_ia32_pmullw128_mask(x,...) x

#define __builtin_ia32_blendmb_128_mask(x,...) x

#define __builtin_ia32_blendmw_128_mask(x,...) x

#define __builtin_ia32_pabsb128_mask(x,...) x

#define __builtin_ia32_pabsb256_mask(x,...) x

#define __builtin_ia32_pabsw128_mask(x,...) x

#define __builtin_ia32_pabsq128_mask(x,...) x

#define __builtin_ia32_pabsq256_mask(x,...) x

#define __builtin_ia32_pabsw256_mask(x,...) x

#define __builtin_ia32_packssdw128_mask(x,...) x

#define __builtin_ia32_packssdw256_mask(x,...) x

#define __builtin_ia32_packusdw256_mask(x,...) x

#define __builtin_ia32_packuswb128_mask(x,...) x

#define __builtin_ia32_packsswb128_mask(x,...) x

#define __builtin_ia32_packsswb256_mask(x,...) x

#define __builtin_ia32_packusdw128_mask(x,...) x

#define __builtin_ia32_paddsb512_mask(x,...) x

#define __builtin_ia32_paddsb128_mask(x,...) x

#define __builtin_ia32_paddsw128_mask(x,...) x

#define __builtin_ia32_paddsw512_mask(x,...) x

#define __builtin_ia32_packuswb256_mask(x,...) x

#define __builtin_ia32_paddsb256_mask(x,...) x

#define __builtin_ia32_paddsw256_mask(x,...) x

#define __builtin_ia32_paddusb512_mask(x,...) x

#define __builtin_ia32_paddusb128_mask(x,...) x

#define __builtin_ia32_paddusb256_mask(x,...) x

#define __builtin_ia32_paddusw512_mask(x,...) x

#define __builtin_ia32_paddusw128_mask(x,...) x

#define __builtin_ia32_paddusw256_mask(x,...) x

#define __builtin_ia32_pavgb128_mask(x,...) x

#define __builtin_ia32_pavgb512_mask(x,...) x

#define __builtin_ia32_pavgb256_mask(x,...) x

#define __builtin_ia32_pavgw512_mask(x,...) x

#define __builtin_ia32_pavgw128_mask(x,...) x

#define __builtin_ia32_pavgw256_mask(x,...) x

#define __builtin_ia32_pmaxsb256_mask(x,...) x

#define __builtin_ia32_pmaxsq256_mask(x,...) x

#define __builtin_ia32_pmaxsw128_mask(x,...) x

#define __builtin_ia32_pmaxsq128_mask(x,...) x

#define __builtin_ia32_pmaxub128_mask(x,...) x

#define __builtin_ia32_pmaxuq128_mask(x,...) x

#define __builtin_ia32_pmaxsb128_mask(x,...) x

#define __builtin_ia32_pmaxsw256_mask(x,...) x

#define __builtin_ia32_pmaxuq256_mask(x,...) x

#define __builtin_ia32_pmaxub256_mask(x,...) x

#define __builtin_ia32_pmaxuw128_mask(x,...) x

#define __builtin_ia32_pmaxuw256_mask(x,...) x

#define __builtin_ia32_pminsb128_mask(x,...) x

#define __builtin_ia32_pminsb256_mask(x,...) x

#define __builtin_ia32_pminsq256_mask(x,...) x

#define __builtin_ia32_pminsw128_mask(x,...) x

#define __builtin_ia32_pminsq128_mask(x,...) x

#define __builtin_ia32_pminub128_mask(x,...) x

#define __builtin_ia32_pminuq256_mask(x,...) x

#define __builtin_ia32_pminub256_mask(x,...) x

#define __builtin_ia32_pminuw128_mask(x,...) x

#define __builtin_ia32_pminuq128_mask(x,...) x

#define __builtin_ia32_pminsw256_mask(x,...) x

#define __builtin_ia32_pminuw256_mask(x,...) x

#define __builtin_ia32_psubsb128_mask(x,...) x

#define __builtin_ia32_psubsb256_mask(x,...) x

#define __builtin_ia32_psubsw128_mask(x,...) x

#define __builtin_ia32_pshufb128_mask(x,...) x

#define __builtin_ia32_pshufb256_mask(x,...) x

#define __builtin_ia32_psubusb128_mask(x,...) x

#define __builtin_ia32_psubusb256_mask(x,...) x

#define __builtin_ia32_psubusw128_mask(x,...) x

#define __builtin_ia32_psubsw256_mask(x,...) x

#define __builtin_ia32_psubusw256_mask(x,...) x

#define __builtin_ia32_pmaddubsw128_mask(x,...) x

#define __builtin_ia32_pmaddubsw512_mask(x,...) x

#define __builtin_ia32_pmaddwd128_mask(x,...) x

#define __builtin_ia32_pmulhrsw256_mask(x,...) x

#define __builtin_ia32_pmulhuw128_mask(x,...) x

#define __builtin_ia32_pmulhuw512_mask(x,...) x

#define __builtin_ia32_pmaddubsw256_mask(x,...) x

#define __builtin_ia32_pmulhrsw128_mask(x,...) x

#define __builtin_ia32_pmaddwd256_mask(x,...) x

#define __builtin_ia32_pmulhw128_mask(x,...) x

#define __builtin_ia32_pmulhuw256_mask(x,...) x

#define __builtin_ia32_punpckhbw256_mask(x,...) x

#define __builtin_ia32_punpcklwd128_mask(x,...) x

#define __builtin_ia32_punpckhwd128_mask(x,...) x

#define __builtin_ia32_pmulhw256_mask(x,...) x

#define __builtin_ia32_punpckhbw128_mask(x,...) x

#define __builtin_ia32_punpckhwd256_mask(x,...) x

#define __builtin_ia32_punpcklbw128_mask(x,...) x

#define __builtin_ia32_punpcklwd256_mask(x,...) x

#define __builtin_ia32_punpcklbw256_mask(x,...) x

#define __builtin_ia32_andnps256_mask(x,...) x

#define __builtin_ia32_andnps128_mask(x,...) x

#define __builtin_ia32_andps128_mask(x,...) x

#define __builtin_ia32_andps256_mask(x,...) x

#define __builtin_ia32_xorps256_mask(x,...) x

#define __builtin_ia32_xorps128_mask(x,...) x

#define __builtin_ia32_orpd256_mask(x,...) x

#define __builtin_ia32_orpd128_mask(x,...) x

#define __builtin_ia32_xorpd128_mask(x,...) x

#define __builtin_ia32_pmullq128_mask(x,...) x

#define __builtin_ia32_orps256_mask(x,...) x

#define __builtin_ia32_andnpd256_mask(x,...) x

#define __builtin_ia32_xorpd256_mask(x,...) x

#define __builtin_ia32_andpd128_mask(x,...) x

#define __builtin_ia32_pmullq256_mask(x,...) x

#define __builtin_ia32_orps128_mask(x,...) x

#define __builtin_ia32_andnpd128_mask(x,...) x

#define __builtin_ia32_andpd256_mask(x,...) x

#define __builtin_ia32_vpcmov_256(x,...) x

#define __builtin_ia32_vpcmov(x,...) x


typedef float my64 __attribute__((__vector_size__(8)));
typedef long long my64i __attribute__((__vector_size__(8)));
typedef double my64d __attribute__((__vector_size__(8)));
typedef float my128 __attribute__((__vector_size__(16)));
typedef long long my128i __attribute__((__vector_size__(16)));
typedef double my128d __attribute__((__vector_size__(16)));
typedef float my256 __attribute__((__vector_size__(32)));
typedef double my256d __attribute__((__vector_size__(32)));
typedef long long my256i __attribute__((__vector_size__(32)));
typedef float my512 __attribute__((__vector_size__(64)));
typedef double my512d __attribute__((__vector_size__(64)));
typedef long long my512i __attribute__((__vector_size__(64)));

typedef int mymask8;
typedef int mymask16;
typedef int mymask32;
typedef int mymask64;

extern unsigned short getunsigned_short();
extern long long getlong_long();
extern int getint();
extern my64 get64();
extern my64i get64i();
extern my64d get64d();
extern my128 get128();
extern my128i get128i();
extern my128d get128d();
extern my256 get256();
extern my256d get256d();
extern my256i get256i();
extern my512 get512();
extern my512i get512i();
extern my512d get512d();
extern mymask8 getmask8();
extern mymask16 getmask16();
extern mymask32 getmask32();
extern mymask64 getmask64();

#define __builtin_ia32_andss(x,...) x
#define __builtin_ia32_addss(x,...) x
#define __builtin_ia32_subss(x,...) x
#define __builtin_ia32_mulss(x,...) x
#define __builtin_ia32_divss(x,...) x
#define __builtin_ia32_xorss(x,...) x
#define __builtin_ia32_andps(x,...) x
#define __builtin_ia32_addps(x,...) x
#define __builtin_ia32_subps(x,...) x
#define __builtin_ia32_mulps(x,...) x
#define __builtin_ia32_divps(x,...) x
#define __builtin_ia32_xorps(x,...) x

#define __builtin_ia32_bsrsi(x,...) x
#define __builtin_ia32_rolqi(x,...) x
#define __builtin_ia32_rolhi(x,...) x
#define __builtin_ia32_rorqi(x,...) x
#define __builtin_ia32_rorhi(x,...) x
#define __builtin_ia32_bsrdi(x,...) x
#define __builtin_ia32_andnps(x,...) x
#define __builtin_ia32_orps(x,...) x
#define __builtin_ia32_movss(x,...) x
#define __builtin_ia32_cmpgtps(x,...) x
#define __builtin_ia32_cmpltps(x,...) x
#define __builtin_ia32_cmpgeps(x,...) x
#define __builtin_ia32_cmpleps(x,...) x
#define __builtin_ia32_cmpngeps(x,...) x
#define __builtin_ia32_cvtsi2ss(x,...) x
#define __builtin_ia32_cvtsi642ss(x,...) x



#define __builtin_ia32_movlhps(x,...) x
#define __builtin_ia32_movhlps(x,...) x
#define __builtin_ia32_shufps(x,...) x
#define __builtin_ia32_unpckhps(x,...) x
#define __builtin_ia32_unpcklps(x,...) x
#define __builtin_ia32_loadhps(x,...) x
#define __builtin_ia32_loadlps(x,...) x

#define __builtin_ia32_cmpngtps(x,...) x
#define __builtin_ia32_movsd(x,...) x
#define __builtin_ia32_shufpd(x,...) x
#define __builtin_ia32_vec_ext_v2di(...) getlong_long()
#define __builtin_ia32_addpd(x,...) x
#define __builtin_ia32_addsd(x,...) x

#define __builtin_ia32_subpd(...) get128d()
#define __builtin_ia32_subsd(...) get128d()
#define __builtin_ia32_mulpd(...) get128d()
#define __builtin_ia32_mulsd(...) get128d()
#define __builtin_ia32_divpd(...) get128d()
#define __builtin_ia32_divsd(...) get128d()
#define __builtin_ia32_sqrtpd(...) get128d()
#define __builtin_ia32_sqrtsd(...) get128d()
#define __builtin_ia32_minpd(...) get128d()
#define __builtin_ia32_minsd(...) get128d()
#define __builtin_ia32_maxpd(...) get128d()
#define __builtin_ia32_maxsd(...) get128d()
#define __builtin_ia32_andpd(...) get128d()
#define __builtin_ia32_andnpd(...) get128d()
#define __builtin_ia32_orpd(...) get128d()
#define __builtin_ia32_xorpd(...) get128d()
#define __builtin_ia32_cmpeqpd(...) get128d()
#define __builtin_ia32_cmpltpd(...) get128d()
#define __builtin_ia32_cmplepd(...) get128d()
#define __builtin_ia32_cmpgtpd(...) get128d()
#define __builtin_ia32_cmpgepd(...) get128d()
#define __builtin_ia32_cmpneqpd(...) get128d()
#define __builtin_ia32_cmpnltpd(...) get128d()
#define __builtin_ia32_cmpnlepd(...) get128d()
#define __builtin_ia32_cmpngtpd(...) get128d()
#define __builtin_ia32_cmpngepd(...) get128d()
#define __builtin_ia32_cmpordpd(...) get128d()
#define __builtin_ia32_cmpunordpd(...) get128d()
#define __builtin_ia32_cmpeqsd(...) get128d()
#define __builtin_ia32_cmpltsd(...) get128d()
#define __builtin_ia32_cmplesd(...) get128d()
#define __builtin_ia32_cmpneqsd(...) get128d()
#define __builtin_ia32_cmpnltsd(...) get128d()
#define __builtin_ia32_cmpnlesd(...) get128d()
#define __builtin_ia32_cmpordsd(...) get128d()
#define __builtin_ia32_cmpunordsd(...) get128d()
#define __builtin_ia32_loaddqu(...) get128i()
#define __builtin_ia32_movq128(...) get128i()
#define __builtin_ia32_cvtdq2ps(...) get128()
#define __builtin_ia32_cvtpd2dq(...) get128i()
#define __builtin_ia32_cvtpd2pi(...) get64()
#define __builtin_ia32_cvtpd2ps(...) get128()
#define __builtin_ia32_cvttpd2dq(...) get128i()
#define __builtin_ia32_cvttpd2pi(...) get64()
#define __builtin_ia32_cvtpi2pd(...) get128d()
#define __builtin_ia32_cvtps2dq(...) get128i()
#define __builtin_ia32_cvttps2dq(...) get128i()
#define __builtin_ia32_cvtsd2ss(...) get128()
#define __builtin_ia32_cvtsi2sd(...) get128d()
#define __builtin_ia32_cvtsi642sd(...) get128d()
#define __builtin_ia32_cvtss2sd(...) get128d()
#define __builtin_ia32_unpckhpd(...) get128d()
#define __builtin_ia32_unpcklpd(...) get128d()
#define __builtin_ia32_loadhpd(...) get128d()
#define __builtin_ia32_loadlpd(...) get128d()
#define __builtin_ia32_packsswb128(...) get128i()
#define __builtin_ia32_packssdw128(...) get128i()
#define __builtin_ia32_packuswb128(...) get128i()
#define __builtin_ia32_punpckhbw128(...) get128i()
#define __builtin_ia32_punpckhwd128(...) get128i()
#define __builtin_ia32_punpckhdq128(...) get128i()
#define __builtin_ia32_punpckhqdq128(...) get128i()
#define __builtin_ia32_punpcklbw128(...) get128i()
#define __builtin_ia32_punpcklwd128(...) get128i()
#define __builtin_ia32_punpckldq128(...) get128i()
#define __builtin_ia32_punpcklqdq128(...) get128i()
#define __builtin_ia32_paddb128(...) get128i()
#define __builtin_ia32_paddw128(...) get128i()
#define __builtin_ia32_paddd128(...) get128i()
#define __builtin_ia32_paddq128(...) get128i()
#define __builtin_ia32_paddsb128(...) get128i()
#define __builtin_ia32_paddsw128(...) get128i()
#define __builtin_ia32_paddusb128(...) get128i()
#define __builtin_ia32_paddusw128(...) get128i()
#define __builtin_ia32_psubb128(...) get128i()
#define __builtin_ia32_psubw128(...) get128i()
#define __builtin_ia32_psubd128(...) get128i()
#define __builtin_ia32_psubq128(...) get128i()
#define __builtin_ia32_psubsb128(...) get128i()
#define __builtin_ia32_psubsw128(...) get128i()
#define __builtin_ia32_psubusb128(...) get128i()
#define __builtin_ia32_psubusw128(...) get128i()
#define __builtin_ia32_pmaddwd128(...) get128i()
#define __builtin_ia32_pmulhw128(...) get128i()
#define __builtin_ia32_pmullw128(...) get128i()
#define __builtin_ia32_pmuludq(...) get64()
#define __builtin_ia32_pmuludq128(...) get128i()
#define __builtin_ia32_psllwi128(...) get128i()
#define __builtin_ia32_pslldi128(...) get128i()
#define __builtin_ia32_psllqi128(...) get128i()
#define __builtin_ia32_psrawi128(...) get128i()
#define __builtin_ia32_psradi128(...) get128i()
#define __builtin_ia32_psrldqi128(...) get128i()
#define __builtin_ia32_pslldqi128(...) get128i()
#define __builtin_ia32_psrlwi128(...) get128i()
#define __builtin_ia32_psrlqi128(...) get128i()
#define __builtin_ia32_psllw128(...) get128i()
#define __builtin_ia32_pslld128(...) get128i()
#define __builtin_ia32_psllq128(...) get128i()
#define __builtin_ia32_psraw128(...) get128i()
#define __builtin_ia32_psrad128(...) get128i()
#define __builtin_ia32_psrlw128(...) get128i()
#define __builtin_ia32_psrld128(...) get128i()
#define __builtin_ia32_psrlq128(...) get128i()
#define __builtin_ia32_pand128(...) get128i()
#define __builtin_ia32_pandn128(...) get128i()
#define __builtin_ia32_por128(...) get128i()
#define __builtin_ia32_pxor128(...) get128i()
#define __builtin_ia32_pcmpeqb128(...) get128i()
#define __builtin_ia32_pcmpeqw128(...) get128i()
#define __builtin_ia32_pcmpeqd128(...) get128i()
#define __builtin_ia32_pcmpgtb128(...) get128i()
#define __builtin_ia32_pcmpgtw128(...) get128i()
#define __builtin_ia32_pcmpgtd128(...) get128i()
#define __builtin_ia32_vec_ext_v8hi(...) getunsigned_short()
#define __builtin_ia32_vec_set_v8hi(...) get128i()
#define __builtin_ia32_pmaxsw128(...) get128i()
#define __builtin_ia32_pmaxub128(...) get128i()
#define __builtin_ia32_pminsw128(...) get128i()
#define __builtin_ia32_pminub128(...) get128i()
#define __builtin_ia32_pmulhuw128(...) get128i()
#define __builtin_ia32_pshufhw(...) get128i()
#define __builtin_ia32_pshuflw(...) get128i()
#define __builtin_ia32_pshufd(...) get128i()
#define __builtin_ia32_pavgb128(...) get128i()
#define __builtin_ia32_pavgw128(...) get128i()
#define __builtin_ia32_psadbw128(...) get128i()
#define __builtin_ia32_storeupd(...)
#define __builtin_ia32_storedqu(...)
#define __builtin_ia32_maskmovdqu(...)
#define __builtin_ia32_movnti(...)
#define __builtin_ia32_movnti64(...)
#define __builtin_ia32_movntdq(...)
#define __builtin_ia32_movntpd(...)
#define __builtin_ia32_clflush(...)
#define __builtin_ia32_lfence(...)
#define __builtin_ia32_mfence(...)

#define __builtin_ia32_sqrtss(...) get128()
#define __builtin_ia32_rcpss(...) get128()
#define __builtin_ia32_rsqrtss(...) get128()
#define __builtin_ia32_minss(...) get128()
#define __builtin_ia32_maxss(...) get128()
#define __builtin_ia32_sqrtps(...) get128()
#define __builtin_ia32_rcpps(...) get128()
#define __builtin_ia32_rsqrtps(...) get128()
#define __builtin_ia32_minps(...) get128()
#define __builtin_ia32_maxps(...) get128()
#define __builtin_ia32_cmpeqss(...) get128()
#define __builtin_ia32_cmpltss(...) get128()
#define __builtin_ia32_cmpless(...) get128()
#define __builtin_ia32_cmpneqss(...) get128()
#define __builtin_ia32_cmpnltss(...) get128()
#define __builtin_ia32_cmpnless(...) get128()
#define __builtin_ia32_cmpordss(...) get128()
#define __builtin_ia32_cmpunordss(...) get128()
#define __builtin_ia32_cmpeqps(...) get128()
#define __builtin_ia32_cmpneqps(...) get128()
#define __builtin_ia32_cmpnltps(...) get128()
#define __builtin_ia32_cmpnleps(...) get128()
#define __builtin_ia32_cmpordps(...) get128()
#define __builtin_ia32_cmpunordps(...) get128()
#define __builtin_ia32_cvtps2pi(...) get64()
#define __builtin_ia32_cvttps2pi(...) get64()
#define __builtin_ia32_cvtpi2ps(...) get128()
#define __builtin_ia32_packssdw(...) get64()
#define __builtin_ia32_packsswb(...) get64()
#define __builtin_ia32_vec_set_v4hi(...) get64()
#define __builtin_ia32_pmaxsw(...) get64()
#define __builtin_ia32_pmaxub(...) get64()
#define __builtin_ia32_pminsw(...) get64()
#define __builtin_ia32_pminub(...) get64()
#define __builtin_ia32_pmulhuw(...) get64()
#define __builtin_ia32_pshufw(...) get64()
#define __builtin_ia32_pavgb(...) get64()
#define __builtin_ia32_pavgw(...) get64()
#define __builtin_ia32_psadbw(...) get64()
#define __builtin_ia32_storehps(...)
#define __builtin_ia32_storelps(...)
#define __builtin_ia32_ldmxcsr(...)
#define __builtin_ia32_maskmovq(...)
#define __builtin_prefetch(...)
#define __builtin_ia32_movntq(...)
#define __builtin_ia32_sfence(...)
#define __builtin_ia32_pause(...)


#define __builtin_ia32_vec_ext_v4hi(...) 0
#define __builtin_ia32_vec_ext_v4sf(...) 0
#define __builtin_ia32_vec_ext_v4si(...) 0

#define __builtin_ia32_loadups(...) get128()
#define __builtin_ia32_loadupd(...) get128d()

#define __builtin_ia32_vec_ext_v2df(...) 0

#define __builtin_ia32_psrldi128(...) get128i()

#define __builtin_ia32_vec_init_v2si(...) get64()
#define __builtin_ia32_packuswb(...) get64()
#define __builtin_ia32_punpckhbw(...) get64()
#define __builtin_ia32_punpckhwd(...) get64()
#define __builtin_ia32_punpckhdq(...) get64()
#define __builtin_ia32_punpcklbw(...) get64()
#define __builtin_ia32_punpcklwd(...) get64()
#define __builtin_ia32_punpckldq(...) get64()
#define __builtin_ia32_paddb(...) get64()
#define __builtin_ia32_paddw(...) get64()
#define __builtin_ia32_paddd(...) get64()
#define __builtin_ia32_paddq(...) get64()
#define __builtin_ia32_paddsb(...) get64()
#define __builtin_ia32_paddsw(...) get64()
#define __builtin_ia32_paddusb(...) get64()
#define __builtin_ia32_paddusw(...) get64()
#define __builtin_ia32_psubb(...) get64()
#define __builtin_ia32_psubw(...) get64()
#define __builtin_ia32_psubd(...) get64()
#define __builtin_ia32_psubq(...) get64()
#define __builtin_ia32_psubsb(...) get64()
#define __builtin_ia32_psubsw(...) get64()
#define __builtin_ia32_psubusb(...) get64()
#define __builtin_ia32_psubusw(...) get64()
#define __builtin_ia32_pmaddwd(...) get64()
#define __builtin_ia32_pmulhw(...) get64()
#define __builtin_ia32_pmullw(...) get64()
#define __builtin_ia32_psllw(...) get64()
#define __builtin_ia32_psllwi(...) get64()
#define __builtin_ia32_pslld(...) get64()
#define __builtin_ia32_pslldi(...) get64()
#define __builtin_ia32_psllq(...) get64()
#define __builtin_ia32_psllqi(...) get64()
#define __builtin_ia32_psraw(...) get64()
#define __builtin_ia32_psrawi(...) get64()
#define __builtin_ia32_psrad(...) get64()
#define __builtin_ia32_psradi(...) get64()
#define __builtin_ia32_psrlw(...) get64()
#define __builtin_ia32_psrlwi(...) get64()
#define __builtin_ia32_psrld(...) get64()
#define __builtin_ia32_psrldi(...) get64()
#define __builtin_ia32_psrlq(...) get64()
#define __builtin_ia32_psrlqi(...) get64()
#define __builtin_ia32_pcmpeqb(...) get64()
#define __builtin_ia32_pcmpgtb(...) get64()
#define __builtin_ia32_pcmpeqw(...) get64()
#define __builtin_ia32_pcmpgtw(...) get64()
#define __builtin_ia32_pcmpeqd(...) get64()
#define __builtin_ia32_pcmpgtd(...) get64()
#define __builtin_ia32_vec_init_v4hi(...) get64()
#define __builtin_ia32_vec_init_v8qi(...) get64()
#define __builtin_ia32_emms(...)

#define __builtin_ia32_movshdup(x) x
#define __builtin_ia32_movsldup(x) x
#define __builtin_ia32_monitor(...)

#define __builtin_ia32_vfmaddpd(...) get128d()
#define __builtin_ia32_vfmaddsd(...) get128d()
#define __builtin_ia32_vfmsubpd(...) get128d()
#define __builtin_ia32_vfmsubsd(...) get128d()
#define __builtin_ia32_vfnmaddpd(...) get128d()
#define __builtin_ia32_vfnmaddsd(...) get128d()
#define __builtin_ia32_vfnmsubpd(...) get128d()
#define __builtin_ia32_vfnmsubsd(...) get128d()
#define __builtin_ia32_vfmaddsubpd(...) get128d()
#define __builtin_ia32_vfmsubaddpd(...) get128d()
#define __builtin_ia32_vfmaddpd256(...) get256d()
#define __builtin_ia32_vfmsubpd256(...) get256d()
#define __builtin_ia32_vfnmaddpd256(...) get256d()
#define __builtin_ia32_vfnmsubpd256(...) get256d()
#define __builtin_ia32_vfmaddsubpd256(...) get256d()
#define __builtin_ia32_vfmsubaddpd256(...) get256d()

#define __builtin_ia32_undef512(...) get512()
#define __builtin_ia32_pbroadcastd512_gpr_mask(...) get512i()
#define __builtin_ia32_pbroadcastq512_gpr_mask(...) get512i()
#define __builtin_ia32_pbroadcastq512_mem_mask(...) get512i()
#define __builtin_ia32_maxpd512_mask(...) get512d()
#define __builtin_ia32_maxps512_mask(...) get512()
#define __builtin_ia32_pmaxsd512_mask(...) get512i()
#define __builtin_ia32_pmaxud512_mask(...) get512i()
#define __builtin_ia32_pmaxsq512_mask(...) get512i()
#define __builtin_ia32_pmaxuq512_mask(...) get512i()
#define __builtin_ia32_minpd512_mask(...) get512d()
#define __builtin_ia32_minps512_mask(...) get512()
#define __builtin_ia32_pminsd512_mask(...) get512i()
#define __builtin_ia32_pminud512_mask(...) get512i()
#define __builtin_ia32_pminsq512_mask(...) get512i()
#define __builtin_ia32_pminuq512_mask(...) get512i()
#define __builtin_ia32_sqrtpd512_mask(...) get512d()
#define __builtin_ia32_rsqrt14pd512_mask(...) get512d()
#define __builtin_ia32_rsqrt14ps512_mask(...) get512()
#define __builtin_ia32_rcp14pd512_mask(...) get512d()
#define __builtin_ia32_rcp14ps512_mask(...) get512()
#define __builtin_ia32_rndscaleps_mask(...) get512()
#define __builtin_ia32_rndscalepd_mask(...) get512d()
#define __builtin_ia32_pabsq512_mask(...) get512i()
#define __builtin_ia32_pabsd512_mask(...) get512i()
#define __builtin_ia32_addpd512_mask(...) get512d()
#define __builtin_ia32_addps512_mask(...) get512()
#define __builtin_ia32_subpd512_mask(...) get512d()
#define __builtin_ia32_subps512_mask(...) get512()
#define __builtin_ia32_mulpd512_mask(...) get512d()
#define __builtin_ia32_mulps512_mask(...) get512()
#define __builtin_ia32_divpd512_mask(...) get512d()
#define __builtin_ia32_divps512_mask(...) get512()
#define __builtin_ia32_vfmaddpd512_mask(...) get512d()
#define __builtin_ia32_vfmaddpd512_mask3(...) get512d()
#define __builtin_ia32_vfmaddpd512_maskz(...) get512d()
#define __builtin_ia32_vfmaddps512_mask(...) get512()
#define __builtin_ia32_vfmaddps512_mask3(...) get512()
#define __builtin_ia32_vfmaddps512_maskz(...) get512()
#define __builtin_ia32_vfmaddsubpd512_mask(...) get512d()
#define __builtin_ia32_vfmaddsubpd512_mask3(...) get512d()
#define __builtin_ia32_vfmaddsubpd512_maskz(...) get512d()
#define __builtin_ia32_vfmaddsubps512_mask(...) get512()
#define __builtin_ia32_vfmaddsubps512_mask3(...) get512()
#define __builtin_ia32_vfmaddsubps512_maskz(...) get512()
#define __builtin_ia32_vfmsubpd512_mask3(...) get512d()
#define __builtin_ia32_vfmsubps512_mask3(...) get512()
#define __builtin_ia32_vfmsubaddpd512_mask3(...) get512d()
#define __builtin_ia32_vfmsubaddps512_mask3(...) get512()
#define __builtin_ia32_vfnmaddpd512_mask(...) get512d()
#define __builtin_ia32_vfnmaddps512_mask(...) get512()
#define __builtin_ia32_vfnmsubpd512_mask(...) get512d()
#define __builtin_ia32_vfnmsubpd512_mask3(...) get512d()
#define __builtin_ia32_vfnmsubps512_mask(...) get512()
#define __builtin_ia32_vfnmsubps512_mask3(...) get512()
#define __builtin_ia32_vpermt2vard512_mask(...) get512i()
#define __builtin_ia32_vpermt2varq512_mask(...) get512i()
#define __builtin_ia32_vpermt2varpd512_mask(...) get512d()
#define __builtin_ia32_vpermt2varps512_mask(...) get512()
#define __builtin_ia32_alignq512_mask(...) get512i()
#define __builtin_ia32_alignd512_mask(...) get512i()
#define __builtin_ia32_cmpps512_mask(...) getmask16()
#define __builtin_ia32_cmppd512_mask(...) getmask8()
#define __builtin_ia32_cvttps2udq512_mask(...) get512i()
#define __builtin_ia32_cvtdq2ps512_mask(...) get512()
#define __builtin_ia32_cvtudq2ps512_mask(...) get512()
#define __builtin_ia32_cvtpd2ps512_mask(...) get256()
#define __builtin_ia32_vcvtps2ph512_mask(...) get256i()
#define __builtin_ia32_vcvtph2ps512_mask(...) get512()
#define __builtin_ia32_cvttps2dq512_mask(...) get512i()
#define __builtin_ia32_cvttpd2dq512_mask(...) get256i()
#define __builtin_ia32_cvtps2dq512_mask(...) get512i()
#define __builtin_ia32_cvtpd2dq512_mask(...) get256i()
#define __builtin_ia32_cvtps2udq512_mask(...) get512i()
#define __builtin_ia32_cvtpd2udq512_mask(...) get256i()
#define __builtin_ia32_ptestmd512(...) getmask16()
#define __builtin_ia32_ptestmq512(...) getmask8()
#define __builtin_ia32_loadaps512_mask(...) get512()
#define __builtin_ia32_loadapd512_mask(...) get512d()
#define __builtin_ia32_pcmpeqd512_mask(...) getmask16()
#define __builtin_ia32_ucmpd512_mask(...) getmask16()
#define __builtin_ia32_pcmpeqq512_mask(...) getmask8()
#define __builtin_ia32_ucmpq512_mask(...) getmask8()
#define __builtin_ia32_cmpd512_mask(...) getmask16()
#define __builtin_ia32_cmpq512_mask(...) getmask8()
#define __builtin_ia32_pcmpgtd512_mask(...) getmask16()
#define __builtin_ia32_pcmpgtq512_mask(...) getmask8()

#define __builtin_ia32_pcmpeqd128_mask(...) getmask8()
#define __builtin_ia32_ucmpd128_mask(...) getmask8()
#define __builtin_ia32_pcmpeqd256_mask(...) getmask8()
#define __builtin_ia32_ucmpd256_mask(...) getmask8()
#define __builtin_ia32_pcmpeqq128_mask(...) getmask8()
#define __builtin_ia32_ucmpq128_mask(...) getmask8()
#define __builtin_ia32_pcmpeqq256_mask(...) getmask8()
#define __builtin_ia32_ucmpq256_mask(...) getmask8()
#define __builtin_ia32_cmpd128_mask(...) getmask8()
#define __builtin_ia32_cmpd256_mask(...) getmask8()
#define __builtin_ia32_cmpq128_mask(...) getmask8()
#define __builtin_ia32_cmpq256_mask(...) getmask8()
#define __builtin_ia32_pcmpgtd128_mask(...) getmask8()
#define __builtin_ia32_pcmpgtd256_mask(...) getmask8()
#define __builtin_ia32_pcmpgtq128_mask(...) getmask8()
#define __builtin_ia32_pcmpgtq256_mask(...) getmask8()
#define __builtin_ia32_cmpps256_mask(...) getmask8()
#define __builtin_ia32_cmppd256_mask(...) getmask8()
#define __builtin_ia32_cmpps128_mask(...) getmask8()
#define __builtin_ia32_cmppd128_mask(...) getmask8()
#define __builtin_ia32_vfmaddpd128_mask(...) get128d()
#define __builtin_ia32_vfmaddpd128_mask3(...) get128d()
#define __builtin_ia32_vfmaddpd128_maskz(...) get128d()
#define __builtin_ia32_vfmaddpd256_mask(...) get256d()
#define __builtin_ia32_vfmaddpd256_mask3(...) get256d()
#define __builtin_ia32_vfmaddpd256_maskz(...) get256d()
#define __builtin_ia32_vfmaddps128_mask(...) get128()
#define __builtin_ia32_vfmaddps128_mask3(...) get128()
#define __builtin_ia32_vfmaddps128_maskz(...) get128()
#define __builtin_ia32_vfmaddps256_mask(...) get256()
#define __builtin_ia32_vfmaddps256_mask3(...) get256()
#define __builtin_ia32_vfmaddps256_maskz(...) get256()
#define __builtin_ia32_vfmaddsubpd128_mask(...) get128d()
#define __builtin_ia32_vfmaddsubpd128_mask3(...) get128d()
#define __builtin_ia32_vfmaddsubpd128_maskz(...) get128d()
#define __builtin_ia32_vfmaddsubpd256_mask(...) get256d()
#define __builtin_ia32_vfmaddsubpd256_mask3(...) get256d()
#define __builtin_ia32_vfmaddsubpd256_maskz(...) get256d()
#define __builtin_ia32_vfmaddsubps128_mask(...) get128()
#define __builtin_ia32_vfmaddsubps128_mask3(...) get128()
#define __builtin_ia32_vfmaddsubps128_maskz(...) get128()
#define __builtin_ia32_vfmaddsubps256_mask(...) get256()
#define __builtin_ia32_vfmaddsubps256_mask3(...) get256()
#define __builtin_ia32_vfmaddsubps256_maskz(...) get256()
#define __builtin_ia32_vfmsubpd128_mask3(...) get128d()
#define __builtin_ia32_vfmsubpd256_mask3(...) get256d()
#define __builtin_ia32_vfmsubps128_mask3(...) get128()
#define __builtin_ia32_vfmsubps256_mask3(...) get256()
#define __builtin_ia32_vfmsubaddpd128_mask3(...) get128d()
#define __builtin_ia32_vfmsubaddpd256_mask3(...) get256d()
#define __builtin_ia32_vfmsubaddps128_mask3(...) get128()
#define __builtin_ia32_vfmsubaddps256_mask3(...) get256()
#define __builtin_ia32_vfnmaddpd128_mask(...) get128d()
#define __builtin_ia32_vfnmaddpd256_mask(...) get256d()
#define __builtin_ia32_vfnmaddps128_mask(...) get128()
#define __builtin_ia32_vfnmaddps256_mask(...) get256()
#define __builtin_ia32_vfnmsubpd128_mask(...) get128d()
#define __builtin_ia32_vfnmsubpd128_mask3(...) get128d()
#define __builtin_ia32_vfnmsubpd256_mask(...) get256d()
#define __builtin_ia32_vfnmsubpd256_mask3(...) get256d()
#define __builtin_ia32_vfnmsubps128_mask(...) get128()
#define __builtin_ia32_vfnmsubps128_mask3(...) get128()
#define __builtin_ia32_vfnmsubps256_mask(...) get256()
#define __builtin_ia32_vfnmsubps256_mask3(...) get256()
#define __builtin_ia32_compressdf128_mask(...) get128d()
#define __builtin_ia32_compressdf256_mask(...) get256d()
#define __builtin_ia32_compressdi128_mask(...) get128i()
#define __builtin_ia32_compressdi256_mask(...) get256i()
#define __builtin_ia32_compresssf128_mask(...) get128()
#define __builtin_ia32_compresssf256_mask(...) get256()
#define __builtin_ia32_compresssi128_mask(...) get128i()
#define __builtin_ia32_compresssi256_mask(...) get256i()
#define __builtin_ia32_cvtdq2ps128_mask(...) get128()
#define __builtin_ia32_cvtdq2ps256_mask(...) get256()
#define __builtin_ia32_cvtpd2dq128_mask(...) get128i()
#define __builtin_ia32_cvtpd2dq256_mask(...) get128i()
#define __builtin_ia32_cvtpd2ps_mask(...) get128()
#define __builtin_ia32_cvtpd2ps256_mask(...) get128()
#define __builtin_ia32_cvtpd2udq128_mask(...) get128i()
#define __builtin_ia32_cvtpd2udq256_mask(...) get128i()
#define __builtin_ia32_cvtps2dq128_mask(...) get128i()
#define __builtin_ia32_cvtps2dq256_mask(...) get256i()
#define __builtin_ia32_cvtps2pd128_mask(...) get128d()
#define __builtin_ia32_cvtps2pd256_mask(...) get256d()
#define __builtin_ia32_cvtps2udq128_mask(...) get128i()
#define __builtin_ia32_cvtps2udq256_mask(...) get256i()
#define __builtin_ia32_cvttpd2dq128_mask(...) get128i()
#define __builtin_ia32_cvttpd2dq256_mask(...) get128i()
#define __builtin_ia32_cvttpd2udq128_mask(...) get128i()
#define __builtin_ia32_cvttpd2udq256_mask(...) get128i()
#define __builtin_ia32_cvttps2dq128_mask(...) get128i()
#define __builtin_ia32_cvttps2dq256_mask(...) get256i()
#define __builtin_ia32_cvttps2udq128_mask(...) get128i()
#define __builtin_ia32_cvttps2udq256_mask(...) get256i()
#define __builtin_ia32_cvtudq2ps128_mask(...) get128()
#define __builtin_ia32_cvtudq2ps256_mask(...) get256()
#define __builtin_ia32_expanddf128_mask(...) get128d()
#define __builtin_ia32_expanddf256_mask(...) get256d()
#define __builtin_ia32_expanddi128_mask(...) get128i()
#define __builtin_ia32_expanddi256_mask(...) get256i()
#define __builtin_ia32_expandloaddf128_mask(...) get128d()
#define __builtin_ia32_expandloaddf256_mask(...) get256d()
#define __builtin_ia32_expandloaddi128_mask(...) get128i()
#define __builtin_ia32_expandloaddi256_mask(...) get256i()
#define __builtin_ia32_expandloadsf128_mask(...) get128()
#define __builtin_ia32_expandloadsf256_mask(...) get256()
#define __builtin_ia32_expandloadsi128_mask(...) get128i()
#define __builtin_ia32_expandloadsi256_mask(...) get256i()
#define __builtin_ia32_expandsf128_mask(...) get128()
#define __builtin_ia32_expandsf256_mask(...) get256()
#define __builtin_ia32_expandsi128_mask(...) get128i()
#define __builtin_ia32_expandsi256_mask(...) get256i()
#define __builtin_ia32_getexppd128_mask(...) get128d()
#define __builtin_ia32_getexppd256_mask(...) get256d()
#define __builtin_ia32_getexpps128_mask(...) get128()
#define __builtin_ia32_getexpps256_mask(...) get256()
#define __builtin_ia32_rndscalepd_128_mask(...) get128d()
#define __builtin_ia32_rndscalepd_256_mask(...) get256d()
#define __builtin_ia32_rndscaleps_128_mask(...) get128()
#define __builtin_ia32_rndscaleps_256_mask(...) get256()
#define __builtin_ia32_scalefpd128_mask(...) get128d()
#define __builtin_ia32_scalefpd256_mask(...) get256d()
#define __builtin_ia32_scalefps128_mask(...) get128()
#define __builtin_ia32_scalefps256_mask(...) get256()
#define __builtin_ia32_vpermi2vard128_mask(...) get128i()
#define __builtin_ia32_vpermi2vard256_mask(...) get256i()
#define __builtin_ia32_vpermi2varpd128_mask(...) get128d()
#define __builtin_ia32_vpermi2varpd256_mask(...) get256d()
#define __builtin_ia32_vpermi2varps128_mask(...) get128()
#define __builtin_ia32_vpermi2varps256_mask(...) get256()
#define __builtin_ia32_vpermi2varq128_mask(...) get128i()
#define __builtin_ia32_vpermi2varq256_mask(...) get256i()
#define __builtin_ia32_vpermt2vard128_mask(...) get128i()
#define __builtin_ia32_vpermt2vard128_maskz(...) get128i()
#define __builtin_ia32_vpermt2vard256_mask(...) get256i()
#define __builtin_ia32_vpermt2vard256_maskz(...) get256i()
#define __builtin_ia32_vpermt2varpd128_mask(...) get128d()
#define __builtin_ia32_vpermt2varpd128_maskz(...) get128d()
#define __builtin_ia32_vpermt2varpd256_mask(...) get256d()
#define __builtin_ia32_vpermt2varpd256_maskz(...) get256d()
#define __builtin_ia32_vpermt2varps128_mask(...) get128()
#define __builtin_ia32_vpermt2varps128_maskz(...) get128()
#define __builtin_ia32_vpermt2varps256_mask(...) get256()
#define __builtin_ia32_vpermt2varps256_maskz(...) get256()
#define __builtin_ia32_vpermt2varq128_mask(...) get128i()
#define __builtin_ia32_vpermt2varq128_maskz(...) get128i()
#define __builtin_ia32_vpermt2varq256_mask(...) get256i()
#define __builtin_ia32_vpermt2varq256_maskz(...) get256i()

#define __builtin_ia32_pcmpeqb512_mask(...) getmask64()
#define __builtin_ia32_ucmpb512_mask(...) getmask64()
#define __builtin_ia32_pcmpeqw512_mask(...) getmask32()
#define __builtin_ia32_ucmpw512_mask(...) getmask32()
#define __builtin_ia32_cmpb512_mask(...) getmask64()
#define __builtin_ia32_cmpw512_mask(...) getmask32()
#define __builtin_ia32_pcmpgtb512_mask(...) getmask64()
#define __builtin_ia32_pcmpgtw512_mask(...) getmask32()
#define __builtin_ia32_pabsb512_mask(...) get512i()
#define __builtin_ia32_pabsw512_mask(...) get512i()
#define __builtin_ia32_pmaxsb512_mask(...) get512i()
#define __builtin_ia32_pmaxsw512_mask(...) get512i()
#define __builtin_ia32_pmaxub512_mask(...) get512i()
#define __builtin_ia32_pmaxuw512_mask(...) get512i()
#define __builtin_ia32_pminsb512_mask(...) get512i()
#define __builtin_ia32_pminsw512_mask(...) get512i()
#define __builtin_ia32_pminub512_mask(...) get512i()
#define __builtin_ia32_pminuw512_mask(...) get512i()
#define __builtin_ia32_psubusb512_mask(...) get512i()
#define __builtin_ia32_psubusw512_mask(...) get512i()
#define __builtin_ia32_vpermi2varhi512_mask(...) get512i()
#define __builtin_ia32_vpermt2varhi512_mask(...) get512i()
#define __builtin_ia32_vpermt2varhi512_maskz(...) get512i()
#define __builtin_ia32_pmulhrsw512_mask(...) get512i()
#define __builtin_ia32_pmaddwd512_mask(...) get512i()
#define __builtin_ia32_pmovswb512_mask(...) get256i()
#define __builtin_ia32_pmovuswb512_mask(...) get256i()
#define __builtin_ia32_pmovwb512_mask(...) get256i()

#define __builtin_ia32_pcmpeqb128_mask(...) getmask16()
#define __builtin_ia32_ucmpb128_mask(...) getmask16()
#define __builtin_ia32_pcmpeqb256_mask(...) getmask32()
#define __builtin_ia32_ucmpb256_mask(...) getmask32()
#define __builtin_ia32_pcmpeqw128_mask(...) getmask8()
#define __builtin_ia32_ucmpw128_mask(...) getmask8()
#define __builtin_ia32_pcmpeqw256_mask(...) getmask16()
#define __builtin_ia32_ucmpw256_mask(...) getmask16()
#define __builtin_ia32_cmpb128_mask(...) getmask16()
#define __builtin_ia32_cmpb256_mask(...) getmask32()
#define __builtin_ia32_cmpw128_mask(...) getmask8()
#define __builtin_ia32_cmpw256_mask(...) getmask16()
#define __builtin_ia32_pcmpgtb128_mask(...) getmask16()
#define __builtin_ia32_pcmpgtb256_mask(...) getmask32()
#define __builtin_ia32_pcmpgtw128_mask(...) getmask8()
#define __builtin_ia32_pcmpgtw256_mask(...) getmask16()
#define __builtin_ia32_vpermi2varhi128_mask(...) get128i()
#define __builtin_ia32_vpermi2varhi256_mask(...) get256i()
#define __builtin_ia32_vpermt2varhi128_mask(...) get128i()
#define __builtin_ia32_vpermt2varhi128_maskz(...) get128i()
#define __builtin_ia32_vpermt2varhi256_mask(...) get256i()
#define __builtin_ia32_vpermt2varhi256_maskz(...) get256i()
#define __builtin_ia32_pmovswb128_mask(...) get128i()
#define __builtin_ia32_pmovswb256_mask(...) get128i()
#define __builtin_ia32_pmovuswb128_mask(...) get128i()
#define __builtin_ia32_pmovuswb256_mask(...) get128i()
#define __builtin_ia32_pmovwb128_mask(...) get128i()
#define __builtin_ia32_pmovwb256_mask(...) get128i()

#define __builtin_ia32_vfmaddps(...) get128()
#define __builtin_ia32_vfmaddss(...) get128()
#define __builtin_ia32_vfmsubps(...) get128()
#define __builtin_ia32_vfmsubss(...) get128()
#define __builtin_ia32_vfnmaddps(...) get128()
#define __builtin_ia32_vfnmaddss(...) get128()
#define __builtin_ia32_vfnmsubps(...) get128()
#define __builtin_ia32_vfnmsubss(...) get128()
#define __builtin_ia32_vfmaddsubps(...) get128()
#define __builtin_ia32_vfmsubaddps(...) get128()
#define __builtin_ia32_vfmaddps256(...) get256()
#define __builtin_ia32_vfmsubps256(...) get256()
#define __builtin_ia32_vfnmaddps256(...) get256()
#define __builtin_ia32_vfnmsubps256(...) get256()
#define __builtin_ia32_vfmaddsubps256(...) get256()
#define __builtin_ia32_vfmsubaddps256(...) get256()

#define __builtin_ia32_pabsb256(...) get256i()
#define __builtin_ia32_pabsw256(...) get256i()
#define __builtin_ia32_pabsd256(...) get256i()
#define __builtin_ia32_packsswb256(...) get256i()
#define __builtin_ia32_packssdw256(...) get256i()
#define __builtin_ia32_packuswb256(...) get256i()
#define __builtin_ia32_packusdw256(...) get256i()
#define __builtin_ia32_paddsb256(...) get256i()
#define __builtin_ia32_paddsw256(...) get256i()
#define __builtin_ia32_paddusb256(...) get256i()
#define __builtin_ia32_paddusw256(...) get256i()
#define __builtin_ia32_palignr256(...) get256i()
#define __builtin_ia32_pavgb256(...) get256i()
#define __builtin_ia32_pavgw256(...) get256i()
#define __builtin_ia32_pblendvb256(...) get256i()
//#define __builtin_shufflevector(...) 0
#define __builtin_ia32_phaddw256(...) get256i()
#define __builtin_ia32_phaddd256(...) get256i()
#define __builtin_ia32_phaddsw256(...) get256i()
#define __builtin_ia32_phsubw256(...) get256i()
#define __builtin_ia32_phsubd256(...) get256i()
#define __builtin_ia32_phsubsw256(...) get256i()
#define __builtin_ia32_pmaddubsw256(...) get256i()
#define __builtin_ia32_pmaddwd256(...) get256i()
#define __builtin_ia32_pmaxsb256(...) get256i()
#define __builtin_ia32_pmaxsw256(...) get256i()
#define __builtin_ia32_pmaxsd256(...) get256i()
#define __builtin_ia32_pmaxub256(...) get256i()
#define __builtin_ia32_pmaxuw256(...) get256i()
#define __builtin_ia32_pmaxud256(...) get256i()
#define __builtin_ia32_pminsb256(...) get256i()
#define __builtin_ia32_pminsw256(...) get256i()
#define __builtin_ia32_pminsd256(...) get256i()
#define __builtin_ia32_pminub256(...) get256i()
#define __builtin_ia32_pminuw256(...) get256i()
#define __builtin_ia32_pminud256(...) get256i()
#define __builtin_ia32_pmuldq256(...) get256i()
#define __builtin_ia32_pmulhrsw256(...) get256i()
#define __builtin_ia32_pmulhuw256(...) get256i()
#define __builtin_ia32_pmulhw256(...) get256i()
#define __builtin_ia32_pshufb256(...) get256i()
#define __builtin_ia32_psignb256(...) get256i()
#define __builtin_ia32_psignw256(...) get256i()
#define __builtin_ia32_psignd256(...) get256i()
#define __builtin_ia32_pslldqi256(...) get256i()
#define __builtin_ia32_psllwi256(...) get256i()
#define __builtin_ia32_psllw256(...) get256i()
#define __builtin_ia32_pslldi256(...) get256i()
#define __builtin_ia32_pslld256(...) get256i()
#define __builtin_ia32_psrawi256(...) get256i()
#define __builtin_ia32_psraw256(...) get256i()
#define __builtin_ia32_psradi256(...) get256i()
#define __builtin_ia32_psrad256(...) get256i()
#define __builtin_ia32_psrldqi256(...) get256i()
#define __builtin_ia32_psrlwi256(...) get256i()
#define __builtin_ia32_psrlw256(...) get256i()
#define __builtin_ia32_psrldi256(...) get256i()
#define __builtin_ia32_psrld256(...) get256i()
#define __builtin_ia32_psubsb256(...) get256i()
#define __builtin_ia32_psubsw256(...) get256i()
#define __builtin_ia32_psubusb256(...) get256i()
#define __builtin_ia32_psubusw256(...) get256i()
#define __builtin_ia32_movntdqa256(...) get256i()
#define __builtin_ia32_permvarsi256(...) get256i()
#define __builtin_ia32_permvarsf256(...) get256()
#define __builtin_ia32_permti256(...) get256i()
#define __builtin_ia32_maskloadd256(...) get256i()
#define __builtin_ia32_maskloadq256(...) get256i()
#define __builtin_ia32_maskloadd(...) get128i()
#define __builtin_ia32_maskloadq(...) get128i()
#define __builtin_ia32_psllv8si(...) get256i()
#define __builtin_ia32_psllv4si(...) get128i()
#define __builtin_ia32_psllv4di(...) get256i()
#define __builtin_ia32_psllv2di(...) get128i()
#define __builtin_ia32_psrav8si(...) get256i()
#define __builtin_ia32_psrav4si(...) get128i()
#define __builtin_ia32_psrlv8si(...) get256i()
#define __builtin_ia32_psrlv4si(...) get128i()
#define __builtin_ia32_psrlv4di(...) get256i()
#define __builtin_ia32_psrlv2di(...) get128i()
#define __builtin_ia32_gatherd_pd(...) get128d()
#define __builtin_ia32_gatherd_pd256(...) get256d()
#define __builtin_ia32_gatherq_pd(...) get128d()
#define __builtin_ia32_gatherq_pd256(...) get256d()
#define __builtin_ia32_gatherd_ps(...) get128()
#define __builtin_ia32_gatherd_ps256(...) get256()
#define __builtin_ia32_gatherq_ps(...) get128()
#define __builtin_ia32_gatherq_ps256(...) get128()
#define __builtin_ia32_gatherd_d(...) get128i()
#define __builtin_ia32_gatherd_d256(...) get256i()
#define __builtin_ia32_gatherq_d(...) get128i()
#define __builtin_ia32_gatherq_d256(...) get128i()
#define __builtin_ia32_gatherd_q(...) get128i()
#define __builtin_ia32_gatherd_q256(...) get256i()
#define __builtin_ia32_gatherq_q(...) get128i()
#define __builtin_ia32_gatherq_q256(...) get256i()

#define __builtin_ia32_movntdqa(...) get128i()

#endif