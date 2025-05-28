/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: tv_code.c
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

#include "tv_code.h"
#include "rtwtypes.h"
#include "tv_code_types.h"
#include "tv_code_private.h"
#include <math.h>
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_tv_code_T tv_code_B;

/* Continuous states */
X_tv_code_T tv_code_X;

/* Block states (default storage) */
DW_tv_code_T tv_code_DW;

/* Real-time model */
static RT_MODEL_tv_code_T tv_code_M_;
RT_MODEL_tv_code_T *const tv_code_M = &tv_code_M_;

/* Forward declaration for local functions */
static void tv_cod_MedianFilterCG_resetImpl(c_dsp_internal_MedianFilterCG_T *obj);
static void t_MedianFilterCG_trickleDownMax(c_dsp_internal_MedianFilterCG_T *obj,
  real_T i);
static void t_MedianFilterCG_trickleDownMin(c_dsp_internal_MedianFilterCG_T *obj,
  real_T i);

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  tv_code_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  tv_code_step();
  tv_code_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  tv_code_step();
  tv_code_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  tv_code_step();
  tv_code_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* System initialize for atomic system: */
void tv_code_ax_filter_Init(DW_ax_filter_tv_code_T *localDW)
{
  b_dspcodegen_FIRFilter_tv_cod_T *iobj_0;
  int32_T i;
  static const real_T tmp[9] = { -0.005412996192943418, -0.00037695464995368688,
    0.082835378892191724, 0.25136596710560233, 0.34706570862151792,
    0.25136596710560233, 0.082835378892191724, -0.00037695464995368688,
    -0.005412996192943418 };

  /* Start for MATLABSystem: '<S2>/ax_filter' */
  localDW->obj._pobj0.matlabCodegenIsDeleted = true;
  localDW->obj.NumChannels = -1;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  if (localDW->obj.NumChannels == -1) {
    localDW->obj.NumChannels = 1;
  }

  iobj_0 = &localDW->obj._pobj0;
  localDW->obj._pobj0.isInitialized = 0;
  localDW->obj._pobj0.isInitialized = 0;

  /* System object Constructor function: dsp.FIRFilter */
  localDW->obj._pobj0.cSFunObject.P0_InitialStates = 0.0;
  for (i = 0; i < 9; i++) {
    iobj_0->cSFunObject.P1_Coefficients[i] = tmp[i];
  }

  localDW->obj._pobj0.matlabCodegenIsDeleted = false;
  localDW->obj.FilterObj = &localDW->obj._pobj0;
  localDW->obj.isSetupComplete = true;

  /* End of Start for MATLABSystem: '<S2>/ax_filter' */

  /* InitializeConditions for MATLABSystem: '<S2>/ax_filter' */
  iobj_0 = localDW->obj.FilterObj;
  if (iobj_0->isInitialized == 1) {
    /* System object Initialization function: dsp.FIRFilter */
    for (i = 0; i < 8; i++) {
      iobj_0->cSFunObject.W0_states[i] = iobj_0->cSFunObject.P0_InitialStates;
    }
  }

  /* End of InitializeConditions for MATLABSystem: '<S2>/ax_filter' */
}

/* Output and update for atomic system: */
void tv_code_ax_filter(real_T rtu_0, B_ax_filter_tv_code_T *localB,
  DW_ax_filter_tv_code_T *localDW)
{
  b_dsp_FIRFilter_0_tv_code_T *obj_0;
  b_dspcodegen_FIRFilter_tv_cod_T *obj;
  real_T acc1;
  real_T zCurr;
  real_T zNext;
  int32_T n;

  /* MATLABSystem: '<S2>/ax_filter' */
  obj = localDW->obj.FilterObj;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->isSetupComplete = true;

    /* System object Initialization function: dsp.FIRFilter */
    for (n = 0; n < 8; n++) {
      obj->cSFunObject.W0_states[n] = obj->cSFunObject.P0_InitialStates;
    }
  }

  obj_0 = &obj->cSFunObject;

  /* System object Outputs function: dsp.FIRFilter */
  acc1 = 0.0;

  /* load input sample */
  zNext = rtu_0;
  for (n = 0; n < 8; n++) {
    /* shift state */
    zCurr = zNext;
    zNext = obj_0->W0_states[n];
    obj_0->W0_states[n] = zCurr;

    /* compute one tap */
    zCurr *= obj_0->P1_Coefficients[n];
    acc1 += zCurr;
  }

  /* compute last tap */
  zCurr = obj->cSFunObject.P1_Coefficients[n] * zNext;

  /* MATLABSystem: '<S2>/ax_filter' */
  /* store output sample */
  localB->ax_filter = acc1 + zCurr;
}

/* Termination for atomic system: */
void tv_code_ax_filter_Term(DW_ax_filter_tv_code_T *localDW)
{
  b_dspcodegen_FIRFilter_tv_cod_T *obj;

  /* Terminate for MATLABSystem: '<S2>/ax_filter' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      obj = localDW->obj.FilterObj;
      if (obj->isInitialized == 1) {
        obj->isInitialized = 2;
      }

      localDW->obj.NumChannels = -1;
    }
  }

  if (!localDW->obj._pobj0.matlabCodegenIsDeleted) {
    localDW->obj._pobj0.matlabCodegenIsDeleted = true;
    if (localDW->obj._pobj0.isInitialized == 1) {
      localDW->obj._pobj0.isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/ax_filter' */
}

static void tv_cod_MedianFilterCG_resetImpl(c_dsp_internal_MedianFilterCG_T *obj)
{
  real_T cnt1;
  real_T cnt2;
  int32_T i;
  for (i = 0; i < 5; i++) {
    obj->pBuf[i] = 0.0;
    obj->pPos[i] = 0.0;
    obj->pHeap[i] = 0.0;
  }

  obj->pWinLen = 5.0;
  obj->pIdx = obj->pWinLen;
  obj->pMidHeap = ceil((obj->pWinLen + 1.0) / 2.0);
  obj->pMinHeapLength = trunc((obj->pWinLen - 1.0) / 2.0);
  obj->pMaxHeapLength = trunc(obj->pWinLen / 2.0);
  cnt1 = 1.0;
  cnt2 = obj->pWinLen;
  for (i = 0; i < 5; i++) {
    if ((int32_T)fmod(5.0 - (real_T)i, 2.0) == 0) {
      obj->pPos[4 - i] = cnt1;
      cnt1++;
    } else {
      obj->pPos[4 - i] = cnt2;
      cnt2--;
    }

    obj->pHeap[(int32_T)obj->pPos[4 - i] - 1] = 5.0 - (real_T)i;
  }
}

static void t_MedianFilterCG_trickleDownMax(c_dsp_internal_MedianFilterCG_T *obj,
  real_T i)
{
  boolean_T exitg1;
  exitg1 = false;
  while ((!exitg1) && (i >= -obj->pMaxHeapLength)) {
    real_T ind1;
    real_T ind2;
    real_T tmp;
    real_T tmp_0;
    if ((i < -1.0) && (i > -obj->pMaxHeapLength) && (obj->pBuf[(int32_T)
         obj->pHeap[(int32_T)(i + obj->pMidHeap) - 1] - 1] < obj->pBuf[(int32_T)
         obj->pHeap[(int32_T)((i - 1.0) + obj->pMidHeap) - 1] - 1])) {
      i--;
    }

    ind1 = trunc(i / 2.0) + obj->pMidHeap;
    ind2 = i + obj->pMidHeap;
    tmp = obj->pHeap[(int32_T)ind1 - 1];
    tmp_0 = obj->pHeap[(int32_T)ind2 - 1];
    if (!(obj->pBuf[(int32_T)tmp - 1] < obj->pBuf[(int32_T)tmp_0 - 1])) {
      exitg1 = true;
    } else {
      obj->pHeap[(int32_T)ind1 - 1] = tmp_0;
      obj->pHeap[(int32_T)ind2 - 1] = tmp;
      obj->pPos[(int32_T)obj->pHeap[(int32_T)ind1 - 1] - 1] = ind1;
      obj->pPos[(int32_T)obj->pHeap[(int32_T)ind2 - 1] - 1] = ind2;
      i *= 2.0;
    }
  }
}

static void t_MedianFilterCG_trickleDownMin(c_dsp_internal_MedianFilterCG_T *obj,
  real_T i)
{
  boolean_T exitg1;
  exitg1 = false;
  while ((!exitg1) && (i <= obj->pMinHeapLength)) {
    real_T ind1;
    real_T ind2;
    real_T tmp;
    real_T tmp_0;
    if ((i > 1.0) && (i < obj->pMinHeapLength) && (obj->pBuf[(int32_T)obj->
         pHeap[(int32_T)((i + 1.0) + obj->pMidHeap) - 1] - 1] < obj->pBuf
         [(int32_T)obj->pHeap[(int32_T)(i + obj->pMidHeap) - 1] - 1])) {
      i++;
    }

    ind1 = i + obj->pMidHeap;
    ind2 = trunc(i / 2.0) + obj->pMidHeap;
    tmp = obj->pHeap[(int32_T)ind1 - 1];
    tmp_0 = obj->pHeap[(int32_T)ind2 - 1];
    if (!(obj->pBuf[(int32_T)tmp - 1] < obj->pBuf[(int32_T)tmp_0 - 1])) {
      exitg1 = true;
    } else {
      obj->pHeap[(int32_T)ind1 - 1] = tmp_0;
      obj->pHeap[(int32_T)ind2 - 1] = tmp;
      obj->pPos[(int32_T)obj->pHeap[(int32_T)ind1 - 1] - 1] = ind1;
      obj->pPos[(int32_T)obj->pHeap[(int32_T)ind2 - 1] - 1] = ind2;
      i *= 2.0;
    }
  }
}

/* Model step function */
void tv_code_step(void)
{
  if (rtmIsMajorTimeStep(tv_code_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&tv_code_M->solverInfo,((tv_code_M->Timing.clockTick0+
      1)*tv_code_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(tv_code_M)) {
    tv_code_M->Timing.t[0] = rtsiGetT(&tv_code_M->solverInfo);
  }

  {
    c_dsp_internal_MedianFilterCG_T *obj;
    real_T p;
    real_T vprev;
    real_T *lastU;

    /* TransferFcn: '<S6>/Transfer Fcn' */
    tv_code_B.TransferFcn = tv_code_P.TransferFcn_C *
      tv_code_X.TransferFcn_CSTATE;
    if (rtmIsMajorTimeStep(tv_code_M)) {
      real_T ind2;

      /* Gain: '<S16>/Gain2' incorporates:
       *  Constant: '<S10>/Constant'
       *  Constant: '<S2>/acc_pedal'
       *  Gain: '<S12>/Gain1'
       *  Sum: '<S10>/Sum1'
       */
      tv_code_B.Gain1_d = tv_code_P.acc_pedal_Value - tv_code_P.Constant_Value;

      /* Product: '<S10>/Product1' incorporates:
       *  Constant: '<S10>/Constant1'
       */
      tv_code_B.Product1 = 4.0 * tv_code_P.max_moment * tv_code_P.drive_ratio *
        tv_code_B.Gain1_d;

      /* Gain: '<S16>/Gain2' incorporates:
       *  Gain: '<S12>/Gain1'
       *  Gain: '<S8>/Gain'
       */
      tv_code_B.Gain1_d = tv_code_P.Gain_Gain_l * tv_code_B.Product1;

      /* Saturate: '<S8>/Saturation' */
      if (tv_code_B.Gain1_d > tv_code_P.Saturation_UpperSat) {
        /* Saturate: '<S8>/Saturation' */
        tv_code_B.Saturation[0] = tv_code_P.Saturation_UpperSat;
      } else if (tv_code_B.Gain1_d < tv_code_P.Saturation_LowerSat) {
        /* Saturate: '<S8>/Saturation' */
        tv_code_B.Saturation[0] = tv_code_P.Saturation_LowerSat;
      } else {
        /* Saturate: '<S8>/Saturation' */
        tv_code_B.Saturation[0] = tv_code_B.Gain1_d;
      }

      if (tv_code_B.Gain1_d > tv_code_P.Saturation_UpperSat) {
        /* Saturate: '<S8>/Saturation' */
        tv_code_B.Saturation[1] = tv_code_P.Saturation_UpperSat;
      } else if (tv_code_B.Gain1_d < tv_code_P.Saturation_LowerSat) {
        /* Saturate: '<S8>/Saturation' */
        tv_code_B.Saturation[1] = tv_code_P.Saturation_LowerSat;
      } else {
        /* Saturate: '<S8>/Saturation' */
        tv_code_B.Saturation[1] = tv_code_B.Gain1_d;
      }

      if (tv_code_B.Gain1_d > tv_code_P.Saturation_UpperSat) {
        /* Saturate: '<S8>/Saturation' */
        tv_code_B.Saturation[2] = tv_code_P.Saturation_UpperSat;
      } else if (tv_code_B.Gain1_d < tv_code_P.Saturation_LowerSat) {
        /* Saturate: '<S8>/Saturation' */
        tv_code_B.Saturation[2] = tv_code_P.Saturation_LowerSat;
      } else {
        /* Saturate: '<S8>/Saturation' */
        tv_code_B.Saturation[2] = tv_code_B.Gain1_d;
      }

      if (tv_code_B.Gain1_d > tv_code_P.Saturation_UpperSat) {
        /* Saturate: '<S8>/Saturation' */
        tv_code_B.Saturation[3] = tv_code_P.Saturation_UpperSat;
      } else if (tv_code_B.Gain1_d < tv_code_P.Saturation_LowerSat) {
        /* Saturate: '<S8>/Saturation' */
        tv_code_B.Saturation[3] = tv_code_P.Saturation_LowerSat;
      } else {
        /* Saturate: '<S8>/Saturation' */
        tv_code_B.Saturation[3] = tv_code_B.Gain1_d;
      }

      /* End of Saturate: '<S8>/Saturation' */

      /* Gain: '<S16>/Gain2' incorporates:
       *  Constant: '<S2>/whl_speed_fl'
       *  Constant: '<S2>/whl_speed_fr'
       *  Constant: '<S2>/whl_speed_rl'
       *  Constant: '<S2>/whl_speed_rr'
       *  Gain: '<S12>/Gain1'
       *  Gain: '<S7>/Gain'
       *  Sum: '<S7>/Plus'
       */
      tv_code_B.Gain1_d = ((tv_code_P.whl_speed_fl_Value +
                            tv_code_P.whl_speed_fr_Value) +
                           tv_code_P.whl_speed_rl_Value) +
        tv_code_P.whl_speed_rr_Value;
      tv_code_B.Gain1_d *= tv_code_P.Gain_Gain_o;

      /* Gain: '<S7>/Gain1' */
      tv_code_B.Gain1 = tv_code_P.rw * tv_code_B.Gain1_d;

      /* Constant: '<S2>/ax' */
      tv_code_ax_filter(tv_code_P.ax_Value, &tv_code_B.ax_filter,
                        &tv_code_DW.ax_filter);

      /* Gain: '<S16>/Gain2' incorporates:
       *  Gain: '<S12>/Gain1'
       *  Gain: '<S14>/Gain1'
       */
      tv_code_B.Gain1_d = tv_code_P.h * tv_code_B.ax_filter.ax_filter;

      /* Constant: '<S2>/ay' */
      tv_code_ax_filter(tv_code_P.ay_Value, &tv_code_B.ay_filter,
                        &tv_code_DW.ay_filter);

      /* Product: '<S13>/div2' incorporates:
       *  Gain: '<S14>/Gain2'
       */
      tv_code_B.div2 = tv_code_P.h * tv_code_P.lr / tv_code_P.ls *
        tv_code_B.ay_filter.ax_filter;

      /* Gain: '<S16>/Gain2' incorporates:
       *  Constant: '<S14>/Constant'
       *  Gain: '<S12>/Gain1'
       *  Gain: '<S14>/Gain'
       *  Sum: '<S14>/Sum'
       */
      tv_code_B.Gain1_d = (tv_code_P.g * tv_code_P.lr - tv_code_B.Gain1_d) -
        tv_code_B.div2;
      tv_code_B.Gain1_d *= tv_code_P.m / (2.0 * tv_code_P.L);

      /* Gain: '<S18>/Gain1' */
      tv_code_B.Gain1_j = 1.0 / (tv_code_P.m * tv_code_P.g) * tv_code_B.Gain1_d;

      /* Constant: '<S2>/yaw_rate' */
      tv_code_ax_filter(tv_code_P.yaw_rate_Value, &tv_code_B.yaw_rate_filter,
                        &tv_code_DW.yaw_rate_filter);

      /* MATLABSystem: '<S2>/Median Filter' incorporates:
       *  Constant: '<S2>/delta'
       */
      obj = &tv_code_DW.obj.pMID;
      if (tv_code_DW.obj.pMID.isInitialized != 1) {
        tv_code_DW.obj.pMID.isInitialized = 1;
        tv_code_DW.obj.pMID.isSetupComplete = true;
        tv_cod_MedianFilterCG_resetImpl(&tv_code_DW.obj.pMID);
      }

      vprev = tv_code_DW.obj.pMID.pBuf[(int32_T)tv_code_DW.obj.pMID.pIdx - 1];
      tv_code_DW.obj.pMID.pBuf[(int32_T)tv_code_DW.obj.pMID.pIdx - 1] =
        tv_code_P.delta_Value;
      p = tv_code_DW.obj.pMID.pPos[(int32_T)tv_code_DW.obj.pMID.pIdx - 1];
      tv_code_DW.obj.pMID.pIdx++;
      if (tv_code_DW.obj.pMID.pWinLen + 1.0 == tv_code_DW.obj.pMID.pIdx) {
        tv_code_DW.obj.pMID.pIdx = 1.0;
      }

      if (p > tv_code_DW.obj.pMID.pMidHeap) {
        if (vprev < tv_code_P.delta_Value) {
          t_MedianFilterCG_trickleDownMin(&tv_code_DW.obj.pMID, (p -
            tv_code_DW.obj.pMID.pMidHeap) * 2.0);
        } else {
          boolean_T exitg1;
          vprev = p - tv_code_DW.obj.pMID.pMidHeap;
          exitg1 = false;
          while ((!exitg1) && (vprev > 0.0)) {
            boolean_T flag;
            flag = (obj->pBuf[(int32_T)obj->pHeap[(int32_T)(vprev +
                     obj->pMidHeap) - 1] - 1] < obj->pBuf[(int32_T)obj->pHeap
                    [(int32_T)(trunc(vprev / 2.0) + obj->pMidHeap) - 1] - 1]);
            if (!flag) {
              exitg1 = true;
            } else {
              real_T temp;
              p = vprev + obj->pMidHeap;
              ind2 = trunc(vprev / 2.0) + obj->pMidHeap;
              temp = obj->pHeap[(int32_T)p - 1];
              obj->pHeap[(int32_T)p - 1] = obj->pHeap[(int32_T)ind2 - 1];
              obj->pHeap[(int32_T)ind2 - 1] = temp;
              obj->pPos[(int32_T)obj->pHeap[(int32_T)p - 1] - 1] = p;
              obj->pPos[(int32_T)obj->pHeap[(int32_T)ind2 - 1] - 1] = ind2;
              vprev = trunc(vprev / 2.0);
            }
          }

          if (vprev == 0.0) {
            t_MedianFilterCG_trickleDownMax(&tv_code_DW.obj.pMID, -1.0);
          }
        }
      } else if (p < tv_code_DW.obj.pMID.pMidHeap) {
        if (tv_code_P.delta_Value < vprev) {
          t_MedianFilterCG_trickleDownMax(&tv_code_DW.obj.pMID, (p -
            tv_code_DW.obj.pMID.pMidHeap) * 2.0);
        } else {
          boolean_T exitg1;
          vprev = p - tv_code_DW.obj.pMID.pMidHeap;
          exitg1 = false;
          while ((!exitg1) && (vprev < 0.0)) {
            boolean_T flag;
            flag = (obj->pBuf[(int32_T)obj->pHeap[(int32_T)(trunc(vprev / 2.0) +
                     obj->pMidHeap) - 1] - 1] < obj->pBuf[(int32_T)obj->pHeap
                    [(int32_T)(vprev + obj->pMidHeap) - 1] - 1]);
            if (!flag) {
              exitg1 = true;
            } else {
              real_T temp;
              p = trunc(vprev / 2.0) + obj->pMidHeap;
              ind2 = vprev + obj->pMidHeap;
              temp = obj->pHeap[(int32_T)p - 1];
              obj->pHeap[(int32_T)p - 1] = obj->pHeap[(int32_T)ind2 - 1];
              obj->pHeap[(int32_T)ind2 - 1] = temp;
              obj->pPos[(int32_T)obj->pHeap[(int32_T)p - 1] - 1] = p;
              obj->pPos[(int32_T)obj->pHeap[(int32_T)ind2 - 1] - 1] = ind2;
              vprev = trunc(vprev / 2.0);
            }
          }

          if (vprev == 0.0) {
            t_MedianFilterCG_trickleDownMin(&tv_code_DW.obj.pMID, 1.0);
          }
        }
      } else {
        if (tv_code_DW.obj.pMID.pMaxHeapLength != 0.0) {
          t_MedianFilterCG_trickleDownMax(&tv_code_DW.obj.pMID, -1.0);
        }

        if (tv_code_DW.obj.pMID.pMinHeapLength > 0.0) {
          t_MedianFilterCG_trickleDownMin(&tv_code_DW.obj.pMID, 1.0);
        }
      }

      /* MATLABSystem: '<S2>/Median Filter' */
      tv_code_B.MedianFilter = tv_code_DW.obj.pMID.pBuf[(int32_T)
        tv_code_DW.obj.pMID.pHeap[(int32_T)tv_code_DW.obj.pMID.pMidHeap - 1] - 1];

      /* Product: '<S13>/div2' incorporates:
       *  Product: '<S5>/Product'
       */
      tv_code_B.div2 = tv_code_B.MedianFilter * tv_code_B.Gain1;

      /* Gain: '<S16>/Gain2' incorporates:
       *  Constant: '<S5>/Constant'
       *  Gain: '<S12>/Gain1'
       *  Gain: '<S5>/Desired Understeer Gradient'
       *  Gain: '<S5>/axlebase'
       *  Math: '<S5>/Square'
       *  Sum: '<S5>/Sum'
       */
      tv_code_B.Gain1_d = tv_code_B.Gain1 * tv_code_B.Gain1;
      tv_code_B.Gain1_d *= tv_code_P.Ku;
      tv_code_B.Gain1_d += tv_code_P.Constant_Value_g;
      tv_code_B.Gain1_d *= tv_code_P.L;

      /* Saturate: '<S5>/Saturation1' */
      if (tv_code_B.Gain1_d > tv_code_P.Saturation1_UpperSat) {
        /* Gain: '<S16>/Gain2' incorporates:
         *  Gain: '<S12>/Gain1'
         */
        tv_code_B.Gain1_d = tv_code_P.Saturation1_UpperSat;
      } else if (tv_code_B.Gain1_d < tv_code_P.Saturation1_LowerSat) {
        /* Gain: '<S16>/Gain2' incorporates:
         *  Gain: '<S12>/Gain1'
         */
        tv_code_B.Gain1_d = tv_code_P.Saturation1_LowerSat;
      }

      /* End of Saturate: '<S5>/Saturation1' */

      /* Product: '<S13>/div2' incorporates:
       *  Product: '<S5>/div3'
       */
      tv_code_B.div2 /= tv_code_B.Gain1_d;

      /* Saturate: '<S5>/Saturation' */
      if (tv_code_B.div2 > tv_code_P.Saturation_UpperSat_l) {
        /* Product: '<S13>/div2' */
        tv_code_B.div2 = tv_code_P.Saturation_UpperSat_l;
      } else if (tv_code_B.div2 < tv_code_P.Saturation_LowerSat_p) {
        /* Product: '<S13>/div2' */
        tv_code_B.div2 = tv_code_P.Saturation_LowerSat_p;
      }

      /* End of Saturate: '<S5>/Saturation' */

      /* Product: '<S13>/div2' incorporates:
       *  Sum: '<S11>/Sum'
       */
      tv_code_B.div2 -= tv_code_B.yaw_rate_filter.ax_filter;

      /* DotProduct: '<S11>/Dot Product' incorporates:
       *  Constant: '<S2>/Mz Proportional Gain'
       */
      tv_code_B.DotProduct = tv_code_P.Mz_p * tv_code_B.div2;

      /* Gain: '<S16>/Gain2' incorporates:
       *  Gain: '<S12>/Gain1'
       *  Gain: '<S15>/Gain1'
       */
      tv_code_B.Gain1_d = tv_code_P.h * tv_code_B.ax_filter.ax_filter;

      /* MinMax: '<S6>/Max' incorporates:
       *  Gain: '<S15>/Gain2'
       */
      tv_code_B.Max = tv_code_P.h * tv_code_P.lr / tv_code_P.ls *
        tv_code_B.ay_filter.ax_filter;

      /* Gain: '<S16>/Gain2' incorporates:
       *  Constant: '<S15>/Constant'
       *  Gain: '<S12>/Gain1'
       *  Sum: '<S15>/Sum'
       */
      tv_code_B.Gain1_d = (tv_code_P.g * tv_code_P.lr - tv_code_B.Gain1_d) +
        tv_code_B.Max;

      /* Gain: '<S15>/Gain' */
      p = tv_code_P.m / (2.0 * tv_code_P.L);

      /* Gain: '<S16>/Gain2' incorporates:
       *  Gain: '<S12>/Gain1'
       *  Gain: '<S15>/Gain'
       */
      tv_code_B.Gain1_d *= p;

      /* Gain: '<S19>/Gain1' */
      ind2 = 1.0 / (tv_code_P.m * tv_code_P.g);

      /* Gain: '<S19>/Gain1' */
      tv_code_B.Gain1_i = ind2 * tv_code_B.Gain1_d;

      /* MinMax: '<S6>/Max' incorporates:
       *  Gain: '<S16>/Gain1'
       */
      tv_code_B.Max = tv_code_P.h * tv_code_B.ax_filter.ax_filter;

      /* Gain: '<S16>/Gain2' incorporates:
       *  Gain: '<S17>/Gain2'
       */
      tv_code_B.Gain1_d = tv_code_P.h * tv_code_P.lf / tv_code_P.ls *
        tv_code_B.ay_filter.ax_filter;

      /* Sum: '<S16>/Sum' incorporates:
       *  Constant: '<S16>/Constant'
       *  Constant: '<S17>/Constant'
       *  Sum: '<S17>/Sum'
       */
      vprev = tv_code_P.g * tv_code_P.lf;

      /* MinMax: '<S6>/Max' incorporates:
       *  Constant: '<S16>/Constant'
       *  Gain: '<S15>/Gain'
       *  Gain: '<S16>/Gain'
       *  Sum: '<S16>/Sum'
       */
      tv_code_B.Max = (vprev + tv_code_B.Max) - tv_code_B.Gain1_d;
      tv_code_B.Max *= p;

      /* Gain: '<S21>/Gain1' incorporates:
       *  Gain: '<S19>/Gain1'
       */
      tv_code_B.Gain1_g = ind2 * tv_code_B.Max;

      /* MinMax: '<S6>/Max' incorporates:
       *  Gain: '<S15>/Gain'
       *  Gain: '<S17>/Gain'
       *  Gain: '<S17>/Gain1'
       *  Sum: '<S17>/Sum'
       */
      tv_code_B.Max = tv_code_P.h * tv_code_B.ax_filter.ax_filter;
      tv_code_B.Max = (vprev + tv_code_B.Max) + tv_code_B.Gain1_d;
      tv_code_B.Max *= p;

      /* Gain: '<S20>/Gain1' incorporates:
       *  Gain: '<S19>/Gain1'
       */
      tv_code_B.Gain1_h = ind2 * tv_code_B.Max;
    }

    /* Sum: '<S4>/Sum1' incorporates:
     *  Integrator: '<S11>/Integrator'
     */
    tv_code_B.est_batt_current = tv_code_X.Integrator_CSTATE;

    /* Sum: '<S11>/Sum1' */
    tv_code_B.Sum1 = tv_code_B.DotProduct + tv_code_B.est_batt_current;

    /* Switch: '<S3>/speed_switch' */
    if (tv_code_B.Gain1 > tv_code_P.speed_switch_Threshold) {
      /* Switch: '<S6>/Switch1' */
      if (tv_code_B.Product1 > tv_code_P.Switch1_Threshold) {
        /* Gain: '<S18>/Gain' incorporates:
         *  Gain: '<S20>/Gain'
         */
        tv_code_B.Gain_p = tv_code_B.Sum1;
      } else {
        /* Gain: '<S6>/Gain' */
        tv_code_B.Gain = tv_code_P.Gain_Gain * tv_code_B.Sum1;

        /* Gain: '<S18>/Gain' incorporates:
         *  Gain: '<S20>/Gain'
         */
        tv_code_B.Gain_p = tv_code_B.Gain;
      }

      /* End of Switch: '<S6>/Switch1' */

      /* Gain: '<S18>/Gain' incorporates:
       *  Gain: '<S19>/Gain'
       *  Gain: '<S20>/Gain'
       *  Gain: '<S21>/Gain'
       */
      tv_code_B.Gain_p *= tv_code_P.rw / tv_code_P.ls;

      /* Saturate: '<S9>/Saturation2' incorporates:
       *  Gain: '<S18>/Gain'
       */
      tv_code_B.Saturation2 = tv_code_B.Gain_p;

      /* Switch: '<S6>/Switch' incorporates:
       *  ManualSwitch: '<S6>/regen_switch'
       */
      if (tv_code_B.Product1 > tv_code_P.Switch_Threshold) {
        /* Saturate: '<S9>/Saturation3' */
        tv_code_B.Saturation3 = tv_code_B.Product1;
      } else {
        if (tv_code_P.regen_switch_CurrentSetting == 1) {
          /* ManualSwitch: '<S6>/regen_switch' incorporates:
           *  Constant: '<S6>/Constant'
           */
          tv_code_B.regen_switch = tv_code_P.Constant_Value_n;
        } else {
          /* ManualSwitch: '<S6>/regen_switch' */
          tv_code_B.regen_switch = tv_code_B.TransferFcn;
        }

        /* Saturate: '<S9>/Saturation3' */
        tv_code_B.Saturation3 = tv_code_B.regen_switch;
      }

      /* End of Switch: '<S6>/Switch' */

      /* Saturate: '<S9>/Saturation2' incorporates:
       *  Product: '<S18>/Product'
       *  Sum: '<S18>/Sum'
       */
      tv_code_B.Saturation2 = tv_code_B.Saturation3 - tv_code_B.Saturation2;
      tv_code_B.Saturation2 *= tv_code_B.Gain1_j;

      /* Saturate: '<S9>/Saturation' incorporates:
       *  Saturate: '<S9>/Saturation1'
       *  Saturate: '<S9>/Saturation2'
       *  Saturate: '<S9>/Saturation3'
       */
      vprev = -tv_code_P.max_moment * tv_code_P.drive_ratio;
      p = tv_code_P.max_moment * tv_code_P.drive_ratio;
      if (tv_code_B.Saturation2 > p) {
        /* Saturate: '<S9>/Saturation2' */
        tv_code_B.Saturation2 = p;
      } else if (tv_code_B.Saturation2 < vprev) {
        /* Saturate: '<S9>/Saturation2' */
        tv_code_B.Saturation2 = vprev;
      }

      /* End of Saturate: '<S9>/Saturation' */

      /* Switch: '<S9>/Switch' */
      if (tv_code_B.Saturation3 != 0.0) {
        /* Switch: '<S9>/Switch' incorporates:
         *  Constant: '<S9>/Constant'
         */
        tv_code_B.Switch = tv_code_P.Constant_Value_k;
      } else {
        /* Switch: '<S9>/Switch' incorporates:
         *  Constant: '<S9>/Constant1'
         */
        tv_code_B.Switch = tv_code_P.Constant1_Value;
      }

      /* End of Switch: '<S9>/Switch' */

      /* DotProduct: '<S9>/Dot Product' */
      tv_code_B.DotProduct_p = tv_code_B.Switch * tv_code_B.Saturation2;

      /* Saturate: '<S9>/Saturation2' incorporates:
       *  Gain: '<S19>/Gain'
       *  Product: '<S19>/Product'
       *  Sum: '<S19>/Sum'
       */
      tv_code_B.Saturation2 = tv_code_B.Gain_p;
      tv_code_B.Saturation2 += tv_code_B.Saturation3;
      tv_code_B.Saturation2 *= tv_code_B.Gain1_i;

      /* Saturate: '<S9>/Saturation1' */
      if (tv_code_B.Saturation2 > p) {
        /* Saturate: '<S9>/Saturation2' */
        tv_code_B.Saturation2 = p;
      } else if (tv_code_B.Saturation2 < vprev) {
        /* Saturate: '<S9>/Saturation2' */
        tv_code_B.Saturation2 = vprev;
      }

      /* DotProduct: '<S9>/Dot Product1' */
      tv_code_B.DotProduct1_d = tv_code_B.Switch * tv_code_B.Saturation2;

      /* Saturate: '<S9>/Saturation2' incorporates:
       *  Gain: '<S21>/Gain'
       *  Product: '<S21>/Product'
       *  Sum: '<S21>/Sum'
       */
      tv_code_B.Saturation2 = tv_code_B.Gain_p;
      tv_code_B.Saturation2 = tv_code_B.Saturation3 - tv_code_B.Saturation2;
      tv_code_B.Saturation2 *= tv_code_B.Gain1_g;

      /* Saturate: '<S9>/Saturation2' */
      if (tv_code_B.Saturation2 > p) {
        /* Saturate: '<S9>/Saturation2' */
        tv_code_B.Saturation2 = p;
      } else if (tv_code_B.Saturation2 < vprev) {
        /* Saturate: '<S9>/Saturation2' */
        tv_code_B.Saturation2 = vprev;
      }

      /* DotProduct: '<S9>/Dot Product2' */
      tv_code_B.DotProduct2 = tv_code_B.Switch * tv_code_B.Saturation2;

      /* Saturate: '<S9>/Saturation3' incorporates:
       *  Product: '<S20>/Product'
       *  Sum: '<S20>/Sum'
       */
      tv_code_B.Saturation3 += tv_code_B.Gain_p;
      tv_code_B.Saturation3 *= tv_code_B.Gain1_h;

      /* Saturate: '<S9>/Saturation3' */
      if (tv_code_B.Saturation3 > p) {
        /* Saturate: '<S9>/Saturation3' */
        tv_code_B.Saturation3 = p;
      } else if (tv_code_B.Saturation3 < vprev) {
        /* Saturate: '<S9>/Saturation3' */
        tv_code_B.Saturation3 = vprev;
      }

      /* DotProduct: '<S9>/Dot Product3' */
      tv_code_B.DotProduct3 = tv_code_B.Switch * tv_code_B.Saturation3;

      /* Switch: '<S3>/speed_switch' */
      tv_code_B.speed_switch[0] = tv_code_B.DotProduct_p;
      tv_code_B.speed_switch[1] = tv_code_B.DotProduct1_d;
      tv_code_B.speed_switch[2] = tv_code_B.DotProduct2;
      tv_code_B.speed_switch[3] = tv_code_B.DotProduct3;
    } else {
      /* Switch: '<S3>/speed_switch' */
      tv_code_B.speed_switch[0] = tv_code_B.Saturation[0];
      tv_code_B.speed_switch[1] = tv_code_B.Saturation[1];
      tv_code_B.speed_switch[2] = tv_code_B.Saturation[2];
      tv_code_B.speed_switch[3] = tv_code_B.Saturation[3];
    }

    /* End of Switch: '<S3>/speed_switch' */

    /* Derivative: '<S4>/Derivative' */
    vprev = tv_code_M->Timing.t[0];
    if ((tv_code_DW.TimeStampA >= vprev) && (tv_code_DW.TimeStampB >= vprev)) {
      /* Sum: '<S4>/Sum1' */
      tv_code_B.est_batt_current = 0.0;
    } else {
      p = tv_code_DW.TimeStampA;
      lastU = &tv_code_DW.LastUAtTimeA;
      if (tv_code_DW.TimeStampA < tv_code_DW.TimeStampB) {
        if (tv_code_DW.TimeStampB < vprev) {
          p = tv_code_DW.TimeStampB;
          lastU = &tv_code_DW.LastUAtTimeB;
        }
      } else if (tv_code_DW.TimeStampA >= vprev) {
        p = tv_code_DW.TimeStampB;
        lastU = &tv_code_DW.LastUAtTimeB;
      }

      /* Sum: '<S4>/Sum1' incorporates:
       *  Constant: '<S3>/batt_curr'
       */
      tv_code_B.est_batt_current = (tv_code_P.batt_curr_Value - *lastU) / (vprev
        - p);
    }

    /* End of Derivative: '<S4>/Derivative' */

    /* Sum: '<S4>/Sum1' incorporates:
     *  Constant: '<S3>/batt_curr'
     *  Gain: '<S4>/current_change'
     */
    tv_code_B.est_batt_current *= tv_code_P.current_change_Gain;
    tv_code_B.est_batt_current += tv_code_P.batt_curr_Value;

    /* Product: '<S4>/Divide' incorporates:
     *  Constant: '<S4>/Constant'
     *  Switch: '<S4>/Switch'
     */
    vprev = tv_code_P.P_max / tv_code_P.batt_voltage;

    /* Product: '<S4>/Divide' incorporates:
     *  Constant: '<S4>/Constant'
     */
    tv_code_B.Divide = vprev / tv_code_B.est_batt_current;

    /* Product: '<S4>/Product' */
    tv_code_B.Product[0] = tv_code_B.speed_switch[0] * tv_code_B.Divide;
    tv_code_B.Product[1] = tv_code_B.speed_switch[1] * tv_code_B.Divide;
    tv_code_B.Product[2] = tv_code_B.speed_switch[2] * tv_code_B.Divide;
    tv_code_B.Product[3] = tv_code_B.speed_switch[3] * tv_code_B.Divide;
    if (rtmIsMajorTimeStep(tv_code_M)) {
    }

    /* Switch: '<S4>/Switch' */
    if (tv_code_B.est_batt_current > vprev) {
      /* Switch: '<S3>/power_speed_limiter_switch' */
      tv_code_B.power_speed_limiter_switch[0] = tv_code_B.Product[0];
      tv_code_B.power_speed_limiter_switch[1] = tv_code_B.Product[1];
      tv_code_B.power_speed_limiter_switch[2] = tv_code_B.Product[2];
      tv_code_B.power_speed_limiter_switch[3] = tv_code_B.Product[3];
    } else {
      /* Switch: '<S3>/power_speed_limiter_switch' */
      tv_code_B.power_speed_limiter_switch[0] = tv_code_B.speed_switch[0];
      tv_code_B.power_speed_limiter_switch[1] = tv_code_B.speed_switch[1];
      tv_code_B.power_speed_limiter_switch[2] = tv_code_B.speed_switch[2];
      tv_code_B.power_speed_limiter_switch[3] = tv_code_B.speed_switch[3];
    }

    /* Switch: '<S3>/power_speed_limiter_switch' */
    if (!(tv_code_B.speed_switch[0] > tv_code_P.power_speed_limiter_switch_Thre))
    {
      /* Switch: '<S3>/power_speed_limiter_switch' */
      tv_code_B.power_speed_limiter_switch[0] = tv_code_B.speed_switch[0];
    }

    if (!(tv_code_B.speed_switch[1] > tv_code_P.power_speed_limiter_switch_Thre))
    {
      /* Switch: '<S3>/power_speed_limiter_switch' */
      tv_code_B.power_speed_limiter_switch[1] = tv_code_B.speed_switch[1];
    }

    if (!(tv_code_B.speed_switch[2] > tv_code_P.power_speed_limiter_switch_Thre))
    {
      /* Switch: '<S3>/power_speed_limiter_switch' */
      tv_code_B.power_speed_limiter_switch[2] = tv_code_B.speed_switch[2];
    }

    if (!(tv_code_B.speed_switch[3] > tv_code_P.power_speed_limiter_switch_Thre))
    {
      /* Switch: '<S3>/power_speed_limiter_switch' */
      tv_code_B.power_speed_limiter_switch[3] = tv_code_B.speed_switch[3];
    }

    /* End of Switch: '<S3>/power_speed_limiter_switch' */

    /* Gain: '<Root>/trq_fl' */
    tv_code_B.trq_fl = tv_code_P.trq_fl_Gain *
      tv_code_B.power_speed_limiter_switch[0];

    /* Gain: '<Root>/trq_fr' */
    tv_code_B.trq_fr = tv_code_P.trq_fr_Gain *
      tv_code_B.power_speed_limiter_switch[1];

    /* Gain: '<Root>/trq_rl' */
    tv_code_B.trq_rl = tv_code_P.trq_rl_Gain *
      tv_code_B.power_speed_limiter_switch[2];

    /* Gain: '<Root>/trq_rr' */
    tv_code_B.trq_rr = tv_code_P.trq_rr_Gain *
      tv_code_B.power_speed_limiter_switch[3];
    if (rtmIsMajorTimeStep(tv_code_M)) {
      /* DotProduct: '<S11>/Dot Product1' incorporates:
       *  Constant: '<S2>/Mz Integative Gain'
       */
      tv_code_B.DotProduct1 = tv_code_B.div2 * tv_code_P.Mz_I;

      /* MinMax: '<S6>/Max' incorporates:
       *  Constant: '<S2>/whl_speed_fl'
       *  Constant: '<S2>/whl_speed_fr'
       *  Constant: '<S2>/whl_speed_rl'
       *  Constant: '<S2>/whl_speed_rr'
       *  Sum: '<S13>/Add'
       */
      tv_code_B.Max = ((tv_code_P.whl_speed_fl_Value +
                        tv_code_P.whl_speed_fr_Value) +
                       tv_code_P.whl_speed_rl_Value) +
        tv_code_P.whl_speed_rr_Value;

      /* DotProduct: '<S13>/Dot Product' incorporates:
       *  Constant: '<S13>/I_max'
       *  Constant: '<S13>/Vdc'
       */
      tv_code_B.DotProduct_k = tv_code_P.I_max_Value * tv_code_P.Vdc_Value;

      /* Product: '<S13>/div2' incorporates:
       *  Gain: '<S13>/Gain'
       */
      tv_code_B.div2 = tv_code_P.Gain_Gain_d * tv_code_B.DotProduct_k;
      tv_code_B.div2 /= tv_code_B.Max;

      /* Gain: '<S12>/X1' incorporates:
       *  Constant: '<S12>/Z1'
       *  Constant: '<S12>/Z2'
       *  Gain: '<S12>/X2'
       */
      vprev = tv_code_P.m * tv_code_P.g;

      /* MinMax: '<S6>/Max' incorporates:
       *  Constant: '<S12>/Z1'
       *  Gain: '<S12>/Gain'
       *  Gain: '<S12>/Ta'
       *  Gain: '<S12>/X1'
       */
      tv_code_B.Max = vprev * tv_code_P.lf / tv_code_P.L * tv_code_P.X1_Gain;
      tv_code_B.Max *= tv_code_P.rw;
      tv_code_B.Max *= 1.0 / tv_code_P.drive_ratio;

      /* Gain: '<S16>/Gain2' incorporates:
       *  Constant: '<S12>/Z2'
       *  Gain: '<S12>/Gain1'
       *  Gain: '<S12>/Tr'
       *  Gain: '<S12>/X2'
       */
      tv_code_B.Gain1_d = vprev * tv_code_P.lr / tv_code_P.L * tv_code_P.X2_Gain;
      tv_code_B.Gain1_d *= tv_code_P.rw;
      tv_code_B.Gain1_d *= 1.0 / tv_code_P.drive_ratio;

      /* MinMax: '<S6>/Max' incorporates:
       *  Constant: '<S6>/TT_max'
       *  MinMax: '<S6>/Max of Elements'
       *  Sum: '<S6>/Sum'
       */
      tv_code_B.Max += tv_code_B.Gain1_d;
      tv_code_B.Max = fmin(tv_code_B.Max, tv_code_B.div2);
      tv_code_B.Max = fmax(tv_code_B.Max, tv_code_P.TT_max_Value);

      /* Gain: '<S6>/Gain1' */
      tv_code_B.Gain1_l = tv_code_P.Gain1_Gain * tv_code_B.Max;
    }
  }

  if (rtmIsMajorTimeStep(tv_code_M)) {
    real_T *lastU;

    /* Update for Derivative: '<S4>/Derivative' incorporates:
     *  Constant: '<S3>/batt_curr'
     */
    if (tv_code_DW.TimeStampA == (rtInf)) {
      tv_code_DW.TimeStampA = tv_code_M->Timing.t[0];
      lastU = &tv_code_DW.LastUAtTimeA;
    } else if (tv_code_DW.TimeStampB == (rtInf)) {
      tv_code_DW.TimeStampB = tv_code_M->Timing.t[0];
      lastU = &tv_code_DW.LastUAtTimeB;
    } else if (tv_code_DW.TimeStampA < tv_code_DW.TimeStampB) {
      tv_code_DW.TimeStampA = tv_code_M->Timing.t[0];
      lastU = &tv_code_DW.LastUAtTimeA;
    } else {
      tv_code_DW.TimeStampB = tv_code_M->Timing.t[0];
      lastU = &tv_code_DW.LastUAtTimeB;
    }

    *lastU = tv_code_P.batt_curr_Value;

    /* End of Update for Derivative: '<S4>/Derivative' */
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(tv_code_M)) {
    rt_ertODEUpdateContinuousStates(&tv_code_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++tv_code_M->Timing.clockTick0;
    tv_code_M->Timing.t[0] = rtsiGetSolverStopTime(&tv_code_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.005s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.005, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      tv_code_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void tv_code_derivatives(void)
{
  XDot_tv_code_T *_rtXdot;
  _rtXdot = ((XDot_tv_code_T *) tv_code_M->derivs);

  /* Derivatives for TransferFcn: '<S6>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = tv_code_P.TransferFcn_A *
    tv_code_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += tv_code_B.Gain1_l;

  /* Derivatives for Integrator: '<S11>/Integrator' */
  _rtXdot->Integrator_CSTATE = tv_code_B.DotProduct1;
}

/* Model initialize function */
void tv_code_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  tv_code_P.Saturation_UpperSat = rtInf;
  tv_code_P.Saturation1_UpperSat = rtInf;

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&tv_code_M->solverInfo, &tv_code_M->Timing.simTimeStep);
    rtsiSetTPtr(&tv_code_M->solverInfo, &rtmGetTPtr(tv_code_M));
    rtsiSetStepSizePtr(&tv_code_M->solverInfo, &tv_code_M->Timing.stepSize0);
    rtsiSetdXPtr(&tv_code_M->solverInfo, &tv_code_M->derivs);
    rtsiSetContStatesPtr(&tv_code_M->solverInfo, (real_T **)
                         &tv_code_M->contStates);
    rtsiSetNumContStatesPtr(&tv_code_M->solverInfo,
      &tv_code_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&tv_code_M->solverInfo,
      &tv_code_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&tv_code_M->solverInfo,
      &tv_code_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&tv_code_M->solverInfo,
      &tv_code_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&tv_code_M->solverInfo, (&rtmGetErrorStatus(tv_code_M)));
    rtsiSetRTModelPtr(&tv_code_M->solverInfo, tv_code_M);
  }

  rtsiSetSimTimeStep(&tv_code_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&tv_code_M->solverInfo, false);
  tv_code_M->intgData.y = tv_code_M->odeY;
  tv_code_M->intgData.f[0] = tv_code_M->odeF[0];
  tv_code_M->intgData.f[1] = tv_code_M->odeF[1];
  tv_code_M->intgData.f[2] = tv_code_M->odeF[2];
  tv_code_M->intgData.f[3] = tv_code_M->odeF[3];
  tv_code_M->contStates = ((X_tv_code_T *) &tv_code_X);
  rtsiSetSolverData(&tv_code_M->solverInfo, (void *)&tv_code_M->intgData);
  rtsiSetSolverName(&tv_code_M->solverInfo,"ode4");
  rtmSetTPtr(tv_code_M, &tv_code_M->Timing.tArray[0]);
  tv_code_M->Timing.stepSize0 = 0.005;

  /* InitializeConditions for TransferFcn: '<S6>/Transfer Fcn' */
  tv_code_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S11>/Integrator' */
  tv_code_X.Integrator_CSTATE = tv_code_P.Integrator_IC;

  /* InitializeConditions for Derivative: '<S4>/Derivative' */
  tv_code_DW.TimeStampA = (rtInf);
  tv_code_DW.TimeStampB = (rtInf);

  /* Constant: '<S2>/ax' */
  tv_code_ax_filter_Init(&tv_code_DW.ax_filter);

  /* Constant: '<S2>/ay' */
  tv_code_ax_filter_Init(&tv_code_DW.ay_filter);

  /* Constant: '<S2>/yaw_rate' */
  tv_code_ax_filter_Init(&tv_code_DW.yaw_rate_filter);

  /* Start for MATLABSystem: '<S2>/Median Filter' */
  tv_code_DW.obj.matlabCodegenIsDeleted = false;
  tv_code_DW.objisempty = true;
  tv_code_DW.obj.isInitialized = 1;
  tv_code_DW.obj.NumChannels = 1;
  tv_code_DW.obj.pMID.isInitialized = 0;
  tv_code_DW.obj.isSetupComplete = true;

  /* InitializeConditions for MATLABSystem: '<S2>/Median Filter' */
  if (tv_code_DW.obj.pMID.isInitialized == 1) {
    tv_cod_MedianFilterCG_resetImpl(&tv_code_DW.obj.pMID);
  }

  /* End of InitializeConditions for MATLABSystem: '<S2>/Median Filter' */
}

/* Model terminate function */
void tv_code_terminate(void)
{
  tv_code_ax_filter_Term(&tv_code_DW.ax_filter);
  tv_code_ax_filter_Term(&tv_code_DW.ay_filter);
  tv_code_ax_filter_Term(&tv_code_DW.yaw_rate_filter);

  /* Terminate for MATLABSystem: '<S2>/Median Filter' */
  if (!tv_code_DW.obj.matlabCodegenIsDeleted) {
    tv_code_DW.obj.matlabCodegenIsDeleted = true;
    if ((tv_code_DW.obj.isInitialized == 1) && tv_code_DW.obj.isSetupComplete) {
      tv_code_DW.obj.NumChannels = -1;
      if (tv_code_DW.obj.pMID.isInitialized == 1) {
        tv_code_DW.obj.pMID.isInitialized = 2;
      }
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Median Filter' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
