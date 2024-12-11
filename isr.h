/*
 * Licensed under GPLv3
 * Author    : Arka Mondal
 * Copyright (C) 2024  Arka Mondal
 */

#ifndef _TINIX_ISR_H_
#define _TINIX_ISR_H_

#include "types.h"

struct stackframe {
  uint32 ds;
  uint32 edi;
  uint32 esi;
  uint32 ebp;
  uint32 kesp;
  uint32 ebx;
  uint32 edx;
  uint32 ecx;
  uint32 eax;

  uint32 int_no;
  uint32 ec;

  uint32 eip;
  uint32 cs;
  uint32 eflags;
  uint32 esp;
  uint32 ss;
} __attribute__((packed));

void isr_initialize(void);
void isr_handler(struct stackframe *regis);

void int_handler_0(void);
void int_handler_1(void);
void int_handler_2(void);
void int_handler_3(void);
void int_handler_4(void);
void int_handler_5(void);
void int_handler_6(void);
void int_handler_7(void);
void int_handler_8(void);
void int_handler_9(void);
void int_handler_10(void);
void int_handler_11(void);
void int_handler_12(void);
void int_handler_13(void);
void int_handler_14(void);
void int_handler_15(void);
void int_handler_16(void);
void int_handler_17(void);
void int_handler_18(void);
void int_handler_19(void);
void int_handler_20(void);
void int_handler_21(void);
void int_handler_22(void);
void int_handler_23(void);
void int_handler_24(void);
void int_handler_25(void);
void int_handler_26(void);
void int_handler_27(void);
void int_handler_28(void);
void int_handler_29(void);
void int_handler_30(void);
void int_handler_31(void);
void int_handler_32(void);
void int_handler_33(void);
void int_handler_34(void);
void int_handler_35(void);
void int_handler_36(void);
void int_handler_37(void);
void int_handler_38(void);
void int_handler_39(void);
void int_handler_40(void);
void int_handler_41(void);
void int_handler_42(void);
void int_handler_43(void);
void int_handler_44(void);
void int_handler_45(void);
void int_handler_46(void);
void int_handler_47(void);
void int_handler_48(void);
void int_handler_49(void);
void int_handler_50(void);
void int_handler_51(void);
void int_handler_52(void);
void int_handler_53(void);
void int_handler_54(void);
void int_handler_55(void);
void int_handler_56(void);
void int_handler_57(void);
void int_handler_58(void);
void int_handler_59(void);
void int_handler_60(void);
void int_handler_61(void);
void int_handler_62(void);
void int_handler_63(void);
void int_handler_64(void);
void int_handler_65(void);
void int_handler_66(void);
void int_handler_67(void);
void int_handler_68(void);
void int_handler_69(void);
void int_handler_70(void);
void int_handler_71(void);
void int_handler_72(void);
void int_handler_73(void);
void int_handler_74(void);
void int_handler_75(void);
void int_handler_76(void);
void int_handler_77(void);
void int_handler_78(void);
void int_handler_79(void);
void int_handler_80(void);
void int_handler_81(void);
void int_handler_82(void);
void int_handler_83(void);
void int_handler_84(void);
void int_handler_85(void);
void int_handler_86(void);
void int_handler_87(void);
void int_handler_88(void);
void int_handler_89(void);
void int_handler_90(void);
void int_handler_91(void);
void int_handler_92(void);
void int_handler_93(void);
void int_handler_94(void);
void int_handler_95(void);
void int_handler_96(void);
void int_handler_97(void);
void int_handler_98(void);
void int_handler_99(void);
void int_handler_100(void);
void int_handler_101(void);
void int_handler_102(void);
void int_handler_103(void);
void int_handler_104(void);
void int_handler_105(void);
void int_handler_106(void);
void int_handler_107(void);
void int_handler_108(void);
void int_handler_109(void);
void int_handler_110(void);
void int_handler_111(void);
void int_handler_112(void);
void int_handler_113(void);
void int_handler_114(void);
void int_handler_115(void);
void int_handler_116(void);
void int_handler_117(void);
void int_handler_118(void);
void int_handler_119(void);
void int_handler_120(void);
void int_handler_121(void);
void int_handler_122(void);
void int_handler_123(void);
void int_handler_124(void);
void int_handler_125(void);
void int_handler_126(void);
void int_handler_127(void);
void int_handler_128(void);
void int_handler_129(void);
void int_handler_130(void);
void int_handler_131(void);
void int_handler_132(void);
void int_handler_133(void);
void int_handler_134(void);
void int_handler_135(void);
void int_handler_136(void);
void int_handler_137(void);
void int_handler_138(void);
void int_handler_139(void);
void int_handler_140(void);
void int_handler_141(void);
void int_handler_142(void);
void int_handler_143(void);
void int_handler_144(void);
void int_handler_145(void);
void int_handler_146(void);
void int_handler_147(void);
void int_handler_148(void);
void int_handler_149(void);
void int_handler_150(void);
void int_handler_151(void);
void int_handler_152(void);
void int_handler_153(void);
void int_handler_154(void);
void int_handler_155(void);
void int_handler_156(void);
void int_handler_157(void);
void int_handler_158(void);
void int_handler_159(void);
void int_handler_160(void);
void int_handler_161(void);
void int_handler_162(void);
void int_handler_163(void);
void int_handler_164(void);
void int_handler_165(void);
void int_handler_166(void);
void int_handler_167(void);
void int_handler_168(void);
void int_handler_169(void);
void int_handler_170(void);
void int_handler_171(void);
void int_handler_172(void);
void int_handler_173(void);
void int_handler_174(void);
void int_handler_175(void);
void int_handler_176(void);
void int_handler_177(void);
void int_handler_178(void);
void int_handler_179(void);
void int_handler_180(void);
void int_handler_181(void);
void int_handler_182(void);
void int_handler_183(void);
void int_handler_184(void);
void int_handler_185(void);
void int_handler_186(void);
void int_handler_187(void);
void int_handler_188(void);
void int_handler_189(void);
void int_handler_190(void);
void int_handler_191(void);
void int_handler_192(void);
void int_handler_193(void);
void int_handler_194(void);
void int_handler_195(void);
void int_handler_196(void);
void int_handler_197(void);
void int_handler_198(void);
void int_handler_199(void);
void int_handler_200(void);
void int_handler_201(void);
void int_handler_202(void);
void int_handler_203(void);
void int_handler_204(void);
void int_handler_205(void);
void int_handler_206(void);
void int_handler_207(void);
void int_handler_208(void);
void int_handler_209(void);
void int_handler_210(void);
void int_handler_211(void);
void int_handler_212(void);
void int_handler_213(void);
void int_handler_214(void);
void int_handler_215(void);
void int_handler_216(void);
void int_handler_217(void);
void int_handler_218(void);
void int_handler_219(void);
void int_handler_220(void);
void int_handler_221(void);
void int_handler_222(void);
void int_handler_223(void);
void int_handler_224(void);
void int_handler_225(void);
void int_handler_226(void);
void int_handler_227(void);
void int_handler_228(void);
void int_handler_229(void);
void int_handler_230(void);
void int_handler_231(void);
void int_handler_232(void);
void int_handler_233(void);
void int_handler_234(void);
void int_handler_235(void);
void int_handler_236(void);
void int_handler_237(void);
void int_handler_238(void);
void int_handler_239(void);
void int_handler_240(void);
void int_handler_241(void);
void int_handler_242(void);
void int_handler_243(void);
void int_handler_244(void);
void int_handler_245(void);
void int_handler_246(void);
void int_handler_247(void);
void int_handler_248(void);
void int_handler_249(void);
void int_handler_250(void);
void int_handler_251(void);
void int_handler_252(void);
void int_handler_253(void);
void int_handler_254(void);
void int_handler_255(void);

#endif /* _TINIX_ISR_H_ */