/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: tv_code_types.h
 *
 * Code generated for Simulink model 'tv_code'.
 *
 * Model version                  : 1.40
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed May 28 17:21:41 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_tv_code_types_h_
#define RTW_HEADER_tv_code_types_h_
#include "rtwtypes.h"
#ifndef struct_tag_YGFa0cxEmLPN5OOzoMPX6F
#define struct_tag_YGFa0cxEmLPN5OOzoMPX6F

struct tag_YGFa0cxEmLPN5OOzoMPX6F
{
  int32_T S0_isInitialized;
  real_T W0_states[8];
  real_T P0_InitialStates;
  real_T P1_Coefficients[9];
};

#endif                                 /* struct_tag_YGFa0cxEmLPN5OOzoMPX6F */

#ifndef typedef_b_dsp_FIRFilter_0_tv_code_T
#define typedef_b_dsp_FIRFilter_0_tv_code_T

typedef struct tag_YGFa0cxEmLPN5OOzoMPX6F b_dsp_FIRFilter_0_tv_code_T;

#endif                                 /* typedef_b_dsp_FIRFilter_0_tv_code_T */

#ifndef struct_tag_85cEWOJhHsTP3Esf8Mi1pG
#define struct_tag_85cEWOJhHsTP3Esf8Mi1pG

struct tag_85cEWOJhHsTP3Esf8Mi1pG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_dsp_FIRFilter_0_tv_code_T cSFunObject;
};

#endif                                 /* struct_tag_85cEWOJhHsTP3Esf8Mi1pG */

#ifndef typedef_b_dspcodegen_FIRFilter_tv_cod_T
#define typedef_b_dspcodegen_FIRFilter_tv_cod_T

typedef struct tag_85cEWOJhHsTP3Esf8Mi1pG b_dspcodegen_FIRFilter_tv_cod_T;

#endif                             /* typedef_b_dspcodegen_FIRFilter_tv_cod_T */

#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap_tv_code_T
#define typedef_cell_wrap_tv_code_T

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE cell_wrap_tv_code_T;

#endif                                 /* typedef_cell_wrap_tv_code_T */

#ifndef struct_tag_5puAQeCvQeiHcCpKgTlMeD
#define struct_tag_5puAQeCvQeiHcCpKgTlMeD

struct tag_5puAQeCvQeiHcCpKgTlMeD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  cell_wrap_tv_code_T inputVarSize;
  int32_T NumChannels;
  b_dspcodegen_FIRFilter_tv_cod_T *FilterObj;
  b_dspcodegen_FIRFilter_tv_cod_T _pobj0;
};

#endif                                 /* struct_tag_5puAQeCvQeiHcCpKgTlMeD */

#ifndef typedef_dsp_simulink_LowpassFilter_tv_T
#define typedef_dsp_simulink_LowpassFilter_tv_T

typedef struct tag_5puAQeCvQeiHcCpKgTlMeD dsp_simulink_LowpassFilter_tv_T;

#endif                             /* typedef_dsp_simulink_LowpassFilter_tv_T */

#ifndef struct_tag_je9TdSm2yYb751inV09C2
#define struct_tag_je9TdSm2yYb751inV09C2

struct tag_je9TdSm2yYb751inV09C2
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T pWinLen;
  real_T pBuf[5];
  real_T pHeap[5];
  real_T pMidHeap;
  real_T pIdx;
  real_T pPos[5];
  real_T pMinHeapLength;
  real_T pMaxHeapLength;
};

#endif                                 /* struct_tag_je9TdSm2yYb751inV09C2 */

#ifndef typedef_c_dsp_internal_MedianFilterCG_T
#define typedef_c_dsp_internal_MedianFilterCG_T

typedef struct tag_je9TdSm2yYb751inV09C2 c_dsp_internal_MedianFilterCG_T;

#endif                             /* typedef_c_dsp_internal_MedianFilterCG_T */

#ifndef struct_tag_4kpgE3lCKM2mKMlNBIa8oB
#define struct_tag_4kpgE3lCKM2mKMlNBIa8oB

struct tag_4kpgE3lCKM2mKMlNBIa8oB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  cell_wrap_tv_code_T inputVarSize;
  int32_T NumChannels;
  c_dsp_internal_MedianFilterCG_T pMID;
};

#endif                                 /* struct_tag_4kpgE3lCKM2mKMlNBIa8oB */

#ifndef typedef_dsp_simulink_MedianFilter_tv__T
#define typedef_dsp_simulink_MedianFilter_tv__T

typedef struct tag_4kpgE3lCKM2mKMlNBIa8oB dsp_simulink_MedianFilter_tv__T;

#endif                             /* typedef_dsp_simulink_MedianFilter_tv__T */

/* Parameters (default storage) */
typedef struct P_tv_code_T_ P_tv_code_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_tv_code_T RT_MODEL_tv_code_T;

#endif                                 /* RTW_HEADER_tv_code_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
