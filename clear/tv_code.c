/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: tv_code.c
 *
 * Code generated for Simulink model 'tv_code'.
 *
 * Model version                  : 1.31
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Mar 20 15:57:03 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "tv_code.h"
#include "rtwtypes.h"
#include "tv_code_private.h"
#include "tv_code_types.h"
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
    real_T Add_tmp;
    real_T Add_tmp_0;
    real_T *lastU;

    /* TransferFcn: '<S6>/Transfer Fcn' */
    tv_code_B.TransferFcn = tv_code_P.TransferFcn_C *
      tv_code_X.TransferFcn_CSTATE;
    if (rtmIsMajorTimeStep(tv_code_M)) {
      real_T Add_tmp_1;
      real_T Gain1_o_tmp;

      /* Gain: '<S16>/Gain2' incorporates:
       *  Constant: '<S10>/Constant'
       *  Constant: '<S2>/acc_pedal'
       *  Sum: '<S10>/Sum1'
       *  Sum: '<S13>/Add'
       */
      tv_code_B.Add = tv_code_P.acc_pedal_Value - tv_code_P.Constant_Value;

      /* Product: '<S10>/Product1' incorporates:
       *  Constant: '<S10>/Constant1'
       */
      tv_code_B.Product1 = 4.0 * tv_code_P.max_moment * tv_code_P.drive_ratio *
        tv_code_B.Add;

      /* Gain: '<S16>/Gain2' incorporates:
       *  Gain: '<S8>/Gain'
       *  Sum: '<S13>/Add'
       */
      tv_code_B.Add = tv_code_P.Gain_Gain_f * tv_code_B.Product1;

      /* Saturate: '<S8>/Saturation' */
      if (tv_code_B.Add > tv_code_P.Saturation_UpperSat) {
        /* Saturate: '<S8>/Saturation' */
        tv_code_B.Saturation[0] = tv_code_P.Saturation_UpperSat;
      } else if (tv_code_B.Add < tv_code_P.Saturation_LowerSat) {
        /* Saturate: '<S8>/Saturation' */
        tv_code_B.Saturation[0] = tv_code_P.Saturation_LowerSat;
      } else {
        /* Saturate: '<S8>/Saturation' */
        tv_code_B.Saturation[0] = tv_code_B.Add;
      }

      if (tv_code_B.Add > tv_code_P.Saturation_UpperSat) {
        /* Saturate: '<S8>/Saturation' */
        tv_code_B.Saturation[1] = tv_code_P.Saturation_UpperSat;
      } else if (tv_code_B.Add < tv_code_P.Saturation_LowerSat) {
        /* Saturate: '<S8>/Saturation' */
        tv_code_B.Saturation[1] = tv_code_P.Saturation_LowerSat;
      } else {
        /* Saturate: '<S8>/Saturation' */
        tv_code_B.Saturation[1] = tv_code_B.Add;
      }

      if (tv_code_B.Add > tv_code_P.Saturation_UpperSat) {
        /* Saturate: '<S8>/Saturation' */
        tv_code_B.Saturation[2] = tv_code_P.Saturation_UpperSat;
      } else if (tv_code_B.Add < tv_code_P.Saturation_LowerSat) {
        /* Saturate: '<S8>/Saturation' */
        tv_code_B.Saturation[2] = tv_code_P.Saturation_LowerSat;
      } else {
        /* Saturate: '<S8>/Saturation' */
        tv_code_B.Saturation[2] = tv_code_B.Add;
      }

      if (tv_code_B.Add > tv_code_P.Saturation_UpperSat) {
        /* Saturate: '<S8>/Saturation' */
        tv_code_B.Saturation[3] = tv_code_P.Saturation_UpperSat;
      } else if (tv_code_B.Add < tv_code_P.Saturation_LowerSat) {
        /* Saturate: '<S8>/Saturation' */
        tv_code_B.Saturation[3] = tv_code_P.Saturation_LowerSat;
      } else {
        /* Saturate: '<S8>/Saturation' */
        tv_code_B.Saturation[3] = tv_code_B.Add;
      }

      /* End of Saturate: '<S8>/Saturation' */

      /* Gain: '<S16>/Gain2' incorporates:
       *  Constant: '<S2>/whl_speed_fl'
       *  Constant: '<S2>/whl_speed_fr'
       *  Constant: '<S2>/whl_speed_rl'
       *  Constant: '<S2>/whl_speed_rr'
       *  Gain: '<S7>/Gain'
       *  Sum: '<S13>/Add'
       *  Sum: '<S7>/Plus'
       */
      tv_code_B.Add = ((tv_code_P.whl_speed_fl_Value +
                        tv_code_P.whl_speed_fr_Value) +
                       tv_code_P.whl_speed_rl_Value) +
        tv_code_P.whl_speed_rr_Value;
      tv_code_B.Add *= tv_code_P.Gain_Gain_m;

      /* Gain: '<S7>/Gain1' */
      tv_code_B.Gain1 = tv_code_P.rw * tv_code_B.Add;

      /* Constant: '<S2>/ax' */
      tv_code_ax_filter(tv_code_P.ax_Value, &tv_code_B.ax_filter,
                        &tv_code_DW.ax_filter);

      /* Gain: '<S14>/Gain1' incorporates:
       *  Gain: '<S15>/Gain1'
       *  Gain: '<S16>/Gain1'
       *  Gain: '<S17>/Gain1'
       */
      Add_tmp = tv_code_P.h * tv_code_B.ax_filter.ax_filter;

      /* Gain: '<S16>/Gain2' incorporates:
       *  Gain: '<S14>/Gain1'
       *  Sum: '<S13>/Add'
       */
      tv_code_B.Add = Add_tmp;

      /* Constant: '<S2>/ay' */
      tv_code_ax_filter(tv_code_P.ay_Value, &tv_code_B.ay_filter,
                        &tv_code_DW.ay_filter);

      /* Gain: '<S14>/Gain2' incorporates:
       *  Gain: '<S15>/Gain2'
       */
      tv_code_B.Max = tv_code_P.h * tv_code_P.lr / tv_code_P.ls *
        tv_code_B.ay_filter.ax_filter;

      /* Product: '<S13>/Divide' incorporates:
       *  Gain: '<S14>/Gain2'
       */
      tv_code_B.Divide_g = tv_code_B.Max;

      /* Sum: '<S14>/Sum' incorporates:
       *  Constant: '<S14>/Constant'
       *  Constant: '<S15>/Constant'
       *  Sum: '<S15>/Sum'
       */
      Add_tmp_0 = tv_code_P.g * tv_code_P.lr;

      /* Gain: '<S16>/Gain2' incorporates:
       *  Constant: '<S14>/Constant'
       *  Sum: '<S13>/Add'
       *  Sum: '<S14>/Sum'
       */
      tv_code_B.Add = (Add_tmp_0 - tv_code_B.Add) - tv_code_B.Divide_g;

      /* Gain: '<S14>/Gain' incorporates:
       *  Gain: '<S15>/Gain'
       */
      Add_tmp_1 = tv_code_P.m / (2.0 * tv_code_P.L);

      /* Gain: '<S16>/Gain2' incorporates:
       *  Gain: '<S14>/Gain'
       *  Sum: '<S13>/Add'
       */
      tv_code_B.Add *= Add_tmp_1;

      /* Gain: '<S18>/Gain1' incorporates:
       *  Gain: '<S19>/Gain1'
       */
      Gain1_o_tmp = 1.0 / (tv_code_P.m * tv_code_P.g);

      /* Gain: '<S18>/Gain1' */
      tv_code_B.Gain1_o = Gain1_o_tmp * tv_code_B.Add;

      /* Constant: '<S2>/yaw_rate' */
      tv_code_ax_filter(tv_code_P.yaw_rate_Value, &tv_code_B.yaw_rate_filter,
                        &tv_code_DW.yaw_rate_filter);

      /* Product: '<S13>/Divide' incorporates:
       *  Constant: '<S2>/delta'
       *  Product: '<S5>/Product'
       */
      tv_code_B.Divide_g = tv_code_P.delta_Value * tv_code_B.Gain1;

      /* Gain: '<S16>/Gain2' incorporates:
       *  Constant: '<S5>/Constant'
       *  Gain: '<S5>/Desired Understeer Gradient'
       *  Gain: '<S5>/axlebase'
       *  Math: '<S5>/Square'
       *  Sum: '<S13>/Add'
       *  Sum: '<S5>/Sum'
       */
      tv_code_B.Add = tv_code_B.Gain1 * tv_code_B.Gain1;
      tv_code_B.Add *= tv_code_P.Ku;
      tv_code_B.Add += tv_code_P.Constant_Value_o;
      tv_code_B.Add *= tv_code_P.L;

      /* Saturate: '<S5>/Saturation1' */
      if (tv_code_B.Add > tv_code_P.Saturation1_UpperSat) {
        /* Gain: '<S16>/Gain2' incorporates:
         *  Sum: '<S13>/Add'
         */
        tv_code_B.Add = tv_code_P.Saturation1_UpperSat;
      } else if (tv_code_B.Add < tv_code_P.Saturation1_LowerSat) {
        /* Gain: '<S16>/Gain2' incorporates:
         *  Sum: '<S13>/Add'
         */
        tv_code_B.Add = tv_code_P.Saturation1_LowerSat;
      }

      /* End of Saturate: '<S5>/Saturation1' */

      /* Product: '<S13>/Divide' incorporates:
       *  Product: '<S5>/Divide'
       */
      tv_code_B.Divide_g /= tv_code_B.Add;

      /* Saturate: '<S5>/Saturation' */
      if (tv_code_B.Divide_g > tv_code_P.Saturation_UpperSat_b) {
        /* Product: '<S13>/Divide' */
        tv_code_B.Divide_g = tv_code_P.Saturation_UpperSat_b;
      } else if (tv_code_B.Divide_g < tv_code_P.Saturation_LowerSat_i) {
        /* Product: '<S13>/Divide' */
        tv_code_B.Divide_g = tv_code_P.Saturation_LowerSat_i;
      }

      /* End of Saturate: '<S5>/Saturation' */

      /* Product: '<S13>/Divide' incorporates:
       *  Sum: '<S11>/Sum'
       */
      tv_code_B.Divide_g -= tv_code_B.yaw_rate_filter.ax_filter;

      /* DotProduct: '<S11>/Dot Product' incorporates:
       *  Constant: '<S2>/Mz Proportional Gain'
       */
      tv_code_B.DotProduct = tv_code_P.Mz_p * tv_code_B.Divide_g;

      /* Gain: '<S16>/Gain2' incorporates:
       *  Gain: '<S15>/Gain'
       *  Gain: '<S15>/Gain1'
       *  Sum: '<S13>/Add'
       *  Sum: '<S15>/Sum'
       */
      tv_code_B.Add = Add_tmp;
      tv_code_B.Add = (Add_tmp_0 - tv_code_B.Add) + tv_code_B.Max;
      tv_code_B.Add *= Add_tmp_1;

      /* Gain: '<S19>/Gain1' */
      tv_code_B.Gain1_m = Gain1_o_tmp * tv_code_B.Add;

      /* Gain: '<S14>/Gain2' incorporates:
       *  Gain: '<S16>/Gain1'
       *  MinMax: '<S6>/Max'
       */
      tv_code_B.Max = Add_tmp;

      /* Gain: '<S16>/Gain2' incorporates:
       *  Gain: '<S17>/Gain2'
       */
      tv_code_B.Add = tv_code_P.h * tv_code_P.lf / tv_code_P.ls *
        tv_code_B.ay_filter.ax_filter;

      /* Sum: '<S16>/Sum' incorporates:
       *  Constant: '<S16>/Constant'
       *  Constant: '<S17>/Constant'
       *  Sum: '<S17>/Sum'
       */
      Add_tmp_0 = tv_code_P.g * tv_code_P.lf;

      /* Gain: '<S14>/Gain2' incorporates:
       *  Constant: '<S16>/Constant'
       *  Gain: '<S16>/Gain'
       *  MinMax: '<S6>/Max'
       *  Sum: '<S16>/Sum'
       */
      tv_code_B.Max = (Add_tmp_0 + tv_code_B.Max) - tv_code_B.Add;
      tv_code_B.Max *= Add_tmp_1;

      /* Gain: '<S21>/Gain1' */
      tv_code_B.Gain1_j = Gain1_o_tmp * tv_code_B.Max;

      /* Gain: '<S14>/Gain2' incorporates:
       *  Gain: '<S17>/Gain'
       *  Gain: '<S17>/Gain1'
       *  MinMax: '<S6>/Max'
       *  Sum: '<S17>/Sum'
       */
      tv_code_B.Max = Add_tmp;
      tv_code_B.Max = (Add_tmp_0 + tv_code_B.Max) + tv_code_B.Add;
      tv_code_B.Max *= Add_tmp_1;

      /* Gain: '<S20>/Gain1' */
      tv_code_B.Gain1_p = Gain1_o_tmp * tv_code_B.Max;
    }

    /* Gain: '<S4>/current_change' incorporates:
     *  Integrator: '<S11>/Integrator'
     */
    tv_code_B.current_change = tv_code_X.Integrator_CSTATE;

    /* Sum: '<S11>/Sum1' */
    tv_code_B.Sum1 = tv_code_B.DotProduct + tv_code_B.current_change;

    /* Switch: '<S3>/speed_switch' */
    if (tv_code_B.Gain1 > tv_code_P.speed_switch_Threshold) {
      /* Switch: '<S6>/Switch1' */
      if (tv_code_B.Product1 > tv_code_P.Switch1_Threshold) {
        /* Gain: '<S18>/Gain' incorporates:
         *  Gain: '<S20>/Gain'
         */
        tv_code_B.Gain_i = tv_code_B.Sum1;
      } else {
        /* Gain: '<S6>/Gain' */
        tv_code_B.Gain = tv_code_P.Gain_Gain * tv_code_B.Sum1;

        /* Gain: '<S18>/Gain' incorporates:
         *  Gain: '<S20>/Gain'
         */
        tv_code_B.Gain_i = tv_code_B.Gain;
      }

      /* End of Switch: '<S6>/Switch1' */

      /* Gain: '<S18>/Gain' incorporates:
       *  Gain: '<S19>/Gain'
       *  Gain: '<S20>/Gain'
       *  Gain: '<S21>/Gain'
       */
      tv_code_B.Gain_i *= tv_code_P.rw / tv_code_P.ls;

      /* Saturate: '<S9>/Saturation2' incorporates:
       *  Gain: '<S18>/Gain'
       */
      tv_code_B.Saturation2 = tv_code_B.Gain_i;

      /* Switch: '<S6>/Switch' incorporates:
       *  ManualSwitch: '<S6>/regenerative_braking_switch'
       */
      if (tv_code_B.Product1 > tv_code_P.Switch_Threshold) {
        /* Saturate: '<S9>/Saturation3' */
        tv_code_B.Saturation3 = tv_code_B.Product1;
      } else {
        if (tv_code_P.regenerative_braking_switch_Cur == 1) {
          /* ManualSwitch: '<S6>/regenerative_braking_switch' incorporates:
           *  Constant: '<S6>/Constant'
           */
          tv_code_B.regenerative_braking_switch = tv_code_P.Constant_Value_g;
        } else {
          /* ManualSwitch: '<S6>/regenerative_braking_switch' */
          tv_code_B.regenerative_braking_switch = tv_code_B.TransferFcn;
        }

        /* Saturate: '<S9>/Saturation3' */
        tv_code_B.Saturation3 = tv_code_B.regenerative_braking_switch;
      }

      /* End of Switch: '<S6>/Switch' */

      /* Saturate: '<S9>/Saturation2' incorporates:
       *  Product: '<S18>/Product'
       *  Sum: '<S18>/Sum'
       */
      tv_code_B.Saturation2 = tv_code_B.Saturation3 - tv_code_B.Saturation2;
      tv_code_B.Saturation2 *= tv_code_B.Gain1_o;

      /* Saturate: '<S9>/Saturation' incorporates:
       *  Saturate: '<S9>/Saturation1'
       *  Saturate: '<S9>/Saturation2'
       *  Saturate: '<S9>/Saturation3'
       */
      Add_tmp_0 = -tv_code_P.max_moment * tv_code_P.drive_ratio;
      Add_tmp = tv_code_P.max_moment * tv_code_P.drive_ratio;
      if (tv_code_B.Saturation2 > Add_tmp) {
        /* Saturate: '<S9>/Saturation2' */
        tv_code_B.Saturation2 = Add_tmp;
      } else if (tv_code_B.Saturation2 < Add_tmp_0) {
        /* Saturate: '<S9>/Saturation2' */
        tv_code_B.Saturation2 = Add_tmp_0;
      }

      /* End of Saturate: '<S9>/Saturation' */

      /* Switch: '<S9>/tt_switch' */
      if (tv_code_B.Saturation3 != 0.0) {
        /* Switch: '<S9>/tt_switch' incorporates:
         *  Constant: '<S9>/Constant'
         */
        tv_code_B.tt_switch = tv_code_P.Constant_Value_j;
      } else {
        /* Switch: '<S9>/tt_switch' incorporates:
         *  Constant: '<S9>/Constant1'
         */
        tv_code_B.tt_switch = tv_code_P.Constant1_Value;
      }

      /* End of Switch: '<S9>/tt_switch' */

      /* DotProduct: '<S9>/Dot Product' */
      tv_code_B.DotProduct_i = tv_code_B.tt_switch * tv_code_B.Saturation2;

      /* Saturate: '<S9>/Saturation2' incorporates:
       *  Gain: '<S19>/Gain'
       *  Product: '<S19>/Product'
       *  Sum: '<S19>/Sum'
       */
      tv_code_B.Saturation2 = tv_code_B.Gain_i;
      tv_code_B.Saturation2 += tv_code_B.Saturation3;
      tv_code_B.Saturation2 *= tv_code_B.Gain1_m;

      /* Saturate: '<S9>/Saturation1' */
      if (tv_code_B.Saturation2 > Add_tmp) {
        /* Saturate: '<S9>/Saturation2' */
        tv_code_B.Saturation2 = Add_tmp;
      } else if (tv_code_B.Saturation2 < Add_tmp_0) {
        /* Saturate: '<S9>/Saturation2' */
        tv_code_B.Saturation2 = Add_tmp_0;
      }

      /* DotProduct: '<S9>/Dot Product1' */
      tv_code_B.DotProduct1_f = tv_code_B.tt_switch * tv_code_B.Saturation2;

      /* Saturate: '<S9>/Saturation2' incorporates:
       *  Gain: '<S21>/Gain'
       *  Product: '<S21>/Product'
       *  Sum: '<S21>/Sum'
       */
      tv_code_B.Saturation2 = tv_code_B.Gain_i;
      tv_code_B.Saturation2 = tv_code_B.Saturation3 - tv_code_B.Saturation2;
      tv_code_B.Saturation2 *= tv_code_B.Gain1_j;

      /* Saturate: '<S9>/Saturation2' */
      if (tv_code_B.Saturation2 > Add_tmp) {
        /* Saturate: '<S9>/Saturation2' */
        tv_code_B.Saturation2 = Add_tmp;
      } else if (tv_code_B.Saturation2 < Add_tmp_0) {
        /* Saturate: '<S9>/Saturation2' */
        tv_code_B.Saturation2 = Add_tmp_0;
      }

      /* DotProduct: '<S9>/Dot Product2' */
      tv_code_B.DotProduct2 = tv_code_B.tt_switch * tv_code_B.Saturation2;

      /* Saturate: '<S9>/Saturation3' incorporates:
       *  Product: '<S20>/Product'
       *  Sum: '<S20>/Sum'
       */
      tv_code_B.Saturation3 += tv_code_B.Gain_i;
      tv_code_B.Saturation3 *= tv_code_B.Gain1_p;

      /* Saturate: '<S9>/Saturation3' */
      if (tv_code_B.Saturation3 > Add_tmp) {
        /* Saturate: '<S9>/Saturation3' */
        tv_code_B.Saturation3 = Add_tmp;
      } else if (tv_code_B.Saturation3 < Add_tmp_0) {
        /* Saturate: '<S9>/Saturation3' */
        tv_code_B.Saturation3 = Add_tmp_0;
      }

      /* DotProduct: '<S9>/Dot Product3' */
      tv_code_B.DotProduct3 = tv_code_B.tt_switch * tv_code_B.Saturation3;

      /* Switch: '<S3>/speed_switch' */
      tv_code_B.speed_switch[0] = tv_code_B.DotProduct_i;
      tv_code_B.speed_switch[1] = tv_code_B.DotProduct1_f;
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
    Add_tmp_0 = tv_code_M->Timing.t[0];
    if ((tv_code_DW.TimeStampA >= Add_tmp_0) && (tv_code_DW.TimeStampB >=
         Add_tmp_0)) {
      /* Gain: '<S4>/current_change' */
      tv_code_B.current_change = 0.0;
    } else {
      Add_tmp = tv_code_DW.TimeStampA;
      lastU = &tv_code_DW.LastUAtTimeA;
      if (tv_code_DW.TimeStampA < tv_code_DW.TimeStampB) {
        if (tv_code_DW.TimeStampB < Add_tmp_0) {
          Add_tmp = tv_code_DW.TimeStampB;
          lastU = &tv_code_DW.LastUAtTimeB;
        }
      } else if (tv_code_DW.TimeStampA >= Add_tmp_0) {
        Add_tmp = tv_code_DW.TimeStampB;
        lastU = &tv_code_DW.LastUAtTimeB;
      }

      /* Gain: '<S4>/current_change' incorporates:
       *  Constant: '<S3>/batt_curr'
       */
      tv_code_B.current_change = (tv_code_P.batt_curr_Value - *lastU) /
        (Add_tmp_0 - Add_tmp);
    }

    /* End of Derivative: '<S4>/Derivative' */

    /* Gain: '<S4>/current_change' */
    tv_code_B.current_change *= tv_code_P.current_change_Gain;

    /* Sum: '<S4>/est_bat_current' incorporates:
     *  Constant: '<S3>/batt_curr'
     */
    tv_code_B.est_bat_current = tv_code_B.current_change +
      tv_code_P.batt_curr_Value;

    /* Switch: '<S4>/Switch' incorporates:
     *  Constant: '<S4>/Constant'
     *  Product: '<S4>/Divide'
     */
    Add_tmp_0 = tv_code_P.P_max / tv_code_P.batt_voltage;
    if (tv_code_B.est_bat_current > Add_tmp_0) {
      /* Product: '<S4>/Divide' */
      tv_code_B.Divide = Add_tmp_0 / tv_code_B.est_bat_current;

      /* Product: '<S4>/Product' */
      tv_code_B.Product[0] = tv_code_B.speed_switch[0] * tv_code_B.Divide;

      /* Switch: '<S3>/power_limiter_switch' */
      tv_code_B.power_limiter_switch[0] = tv_code_B.Product[0];

      /* Product: '<S4>/Product' */
      tv_code_B.Product[1] = tv_code_B.speed_switch[1] * tv_code_B.Divide;

      /* Switch: '<S3>/power_limiter_switch' */
      tv_code_B.power_limiter_switch[1] = tv_code_B.Product[1];

      /* Product: '<S4>/Product' */
      tv_code_B.Product[2] = tv_code_B.speed_switch[2] * tv_code_B.Divide;

      /* Switch: '<S3>/power_limiter_switch' */
      tv_code_B.power_limiter_switch[2] = tv_code_B.Product[2];

      /* Product: '<S4>/Product' */
      tv_code_B.Product[3] = tv_code_B.speed_switch[3] * tv_code_B.Divide;

      /* Switch: '<S3>/power_limiter_switch' */
      tv_code_B.power_limiter_switch[3] = tv_code_B.Product[3];
    } else {
      /* Switch: '<S3>/power_limiter_switch' */
      tv_code_B.power_limiter_switch[0] = tv_code_B.speed_switch[0];
      tv_code_B.power_limiter_switch[1] = tv_code_B.speed_switch[1];
      tv_code_B.power_limiter_switch[2] = tv_code_B.speed_switch[2];
      tv_code_B.power_limiter_switch[3] = tv_code_B.speed_switch[3];
    }

    /* End of Switch: '<S4>/Switch' */

    /* Switch: '<S3>/power_limiter_switch' */
    if (!(tv_code_B.speed_switch[0] > tv_code_P.power_limiter_switch_Threshold))
    {
      /* Switch: '<S3>/power_limiter_switch' */
      tv_code_B.power_limiter_switch[0] = tv_code_B.speed_switch[0];
    }

    if (!(tv_code_B.speed_switch[1] > tv_code_P.power_limiter_switch_Threshold))
    {
      /* Switch: '<S3>/power_limiter_switch' */
      tv_code_B.power_limiter_switch[1] = tv_code_B.speed_switch[1];
    }

    if (!(tv_code_B.speed_switch[2] > tv_code_P.power_limiter_switch_Threshold))
    {
      /* Switch: '<S3>/power_limiter_switch' */
      tv_code_B.power_limiter_switch[2] = tv_code_B.speed_switch[2];
    }

    if (!(tv_code_B.speed_switch[3] > tv_code_P.power_limiter_switch_Threshold))
    {
      /* Switch: '<S3>/power_limiter_switch' */
      tv_code_B.power_limiter_switch[3] = tv_code_B.speed_switch[3];
    }

    /* End of Switch: '<S3>/power_limiter_switch' */

    /* Gain: '<Root>/trq_fl' */
    tv_code_B.trq_fl = tv_code_P.trq_fl_Gain * tv_code_B.power_limiter_switch[0];

    /* Gain: '<Root>/trq_fr' */
    tv_code_B.trq_fr = tv_code_P.trq_fr_Gain * tv_code_B.power_limiter_switch[1];

    /* Gain: '<Root>/trq_rl' */
    tv_code_B.trq_rl = tv_code_P.trq_rl_Gain * tv_code_B.power_limiter_switch[2];

    /* Gain: '<Root>/trq_rr' */
    tv_code_B.trq_rr = tv_code_P.trq_rr_Gain * tv_code_B.power_limiter_switch[3];
    if (rtmIsMajorTimeStep(tv_code_M)) {
      /* DotProduct: '<S11>/Dot Product1' incorporates:
       *  Constant: '<S2>/Mz Integative Gain'
       */
      tv_code_B.DotProduct1 = tv_code_B.Divide_g * tv_code_P.Mz_I;

      /* Gain: '<S12>/X1' incorporates:
       *  Constant: '<S12>/Z1'
       *  Constant: '<S12>/Z2'
       *  Gain: '<S12>/X2'
       */
      Add_tmp_0 = tv_code_P.m * tv_code_P.g;

      /* Gain: '<S14>/Gain2' incorporates:
       *  Constant: '<S12>/Z1'
       *  Gain: '<S12>/Gain'
       *  Gain: '<S12>/Ta'
       *  Gain: '<S12>/X1'
       *  MinMax: '<S6>/Max'
       */
      tv_code_B.Max = Add_tmp_0 * tv_code_P.lf / tv_code_P.L * tv_code_P.X1_Gain;
      tv_code_B.Max *= tv_code_P.rw;
      tv_code_B.Max *= 1.0 / tv_code_P.drive_ratio;

      /* Product: '<S13>/Divide' incorporates:
       *  Constant: '<S12>/Z2'
       *  Gain: '<S12>/Gain1'
       *  Gain: '<S12>/Tr'
       *  Gain: '<S12>/X2'
       */
      tv_code_B.Divide_g = Add_tmp_0 * tv_code_P.lr / tv_code_P.L *
        tv_code_P.X2_Gain;
      tv_code_B.Divide_g *= tv_code_P.rw;
      tv_code_B.Divide_g *= 1.0 / tv_code_P.drive_ratio;

      /* Gain: '<S14>/Gain2' incorporates:
       *  MinMax: '<S6>/Max'
       *  Sum: '<S6>/Sum'
       */
      tv_code_B.Max += tv_code_B.Divide_g;

      /* DotProduct: '<S13>/Dot Product' incorporates:
       *  Constant: '<S13>/I_max'
       *  Constant: '<S13>/Vdc'
       */
      tv_code_B.DotProduct_n = tv_code_P.I_max_Value * tv_code_P.Vdc_Value;

      /* Product: '<S13>/Divide' incorporates:
       *  Gain: '<S13>/Gain'
       */
      tv_code_B.Divide_g = tv_code_P.Gain_Gain_mp * tv_code_B.DotProduct_n;

      /* Gain: '<S16>/Gain2' incorporates:
       *  Constant: '<S13>/car_trq_fl'
       *  Constant: '<S13>/car_trq_fr'
       *  Constant: '<S13>/car_trq_rl'
       *  Constant: '<S13>/car_trq_rr'
       *  Sum: '<S13>/Add'
       */
      tv_code_B.Add = ((tv_code_P.car_trq_fl_Value + tv_code_P.car_trq_fr_Value)
                       + tv_code_P.car_trq_rl_Value) +
        tv_code_P.car_trq_rr_Value;

      /* Product: '<S13>/Divide' */
      tv_code_B.Divide_g /= tv_code_B.Add;

      /* Gain: '<S14>/Gain2' incorporates:
       *  Constant: '<S6>/tt_max'
       *  MinMax: '<S6>/Max'
       *  MinMax: '<S6>/Max of Elements'
       */
      tv_code_B.Max = fmin(tv_code_B.Max, tv_code_B.Divide_g);
      tv_code_B.Max = fmax(tv_code_B.Max, tv_code_P.tt_max_Value);

      /* Gain: '<S6>/Gain1' */
      tv_code_B.Gain1_e = tv_code_P.Gain1_Gain * tv_code_B.Max;
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
  _rtXdot->TransferFcn_CSTATE += tv_code_B.Gain1_e;

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
}

/* Model terminate function */
void tv_code_terminate(void)
{
  tv_code_ax_filter_Term(&tv_code_DW.ax_filter);
  tv_code_ax_filter_Term(&tv_code_DW.ay_filter);
  tv_code_ax_filter_Term(&tv_code_DW.yaw_rate_filter);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
