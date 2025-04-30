/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: tv_code_data.c
 *
 * Code generated for Simulink model 'tv_code'.
 *
 * Model version                  : 1.32
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Apr 29 17:15:15 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "tv_code.h"

/* Block parameters (default storage) */
P_tv_code_T tv_code_P = {
  /* Variable: Ku
   * Referenced by: '<S6>/Desired Understeer Gradient'
   */
  -0.002,

  /* Variable: L
   * Referenced by:
   *   '<S6>/axlebase'
   *   '<S13>/Z1'
   *   '<S13>/Z2'
   *   '<S15>/Gain'
   *   '<S16>/Gain'
   *   '<S17>/Gain'
   *   '<S18>/Gain'
   */
  1.53,

  /* Variable: Mz_I
   * Referenced by: '<S2>/Mz Integative Gain'
   */
  70.0,

  /* Variable: Mz_p
   * Referenced by: '<S2>/Mz Proportional Gain'
   */
  500.0,

  /* Variable: P_max
   * Referenced by:
   *   '<S5>/Constant'
   *   '<S5>/Switch'
   */
  80000.0,

  /* Variable: batt_voltage
   * Referenced by:
   *   '<S5>/Constant'
   *   '<S5>/Switch'
   */
  587.0,

  /* Variable: bbal
   * Referenced by:
   *   '<S4>/Gain'
   *   '<S4>/Gain1'
   *   '<S4>/Gain2'
   *   '<S4>/Gain3'
   */
  1.0,

  /* Variable: drive_ratio
   * Referenced by:
   *   '<S10>/Saturation'
   *   '<S10>/Saturation1'
   *   '<S10>/Saturation2'
   *   '<S10>/Saturation3'
   *   '<S11>/Constant1'
   *   '<S13>/Gain'
   *   '<S13>/Gain1'
   */
  14.25,

  /* Variable: g
   * Referenced by:
   *   '<S13>/Z1'
   *   '<S13>/Z2'
   *   '<S15>/Constant'
   *   '<S16>/Constant'
   *   '<S17>/Constant'
   *   '<S18>/Constant'
   *   '<S19>/Gain1'
   *   '<S20>/Gain1'
   *   '<S21>/Gain1'
   *   '<S22>/Gain1'
   */
  9.81,

  /* Variable: gain_threshold
   * Referenced by: '<S12>/Gain'
   */
  20.0,

  /* Variable: h
   * Referenced by:
   *   '<S15>/Gain1'
   *   '<S15>/Gain2'
   *   '<S16>/Gain1'
   *   '<S16>/Gain2'
   *   '<S17>/Gain1'
   *   '<S17>/Gain2'
   *   '<S18>/Gain1'
   *   '<S18>/Gain2'
   */
  0.25,

  /* Variable: lf
   * Referenced by:
   *   '<S13>/Z1'
   *   '<S17>/Constant'
   *   '<S17>/Gain2'
   *   '<S18>/Constant'
   *   '<S18>/Gain2'
   */
  0.765,

  /* Variable: lr
   * Referenced by:
   *   '<S13>/Z2'
   *   '<S15>/Constant'
   *   '<S15>/Gain2'
   *   '<S16>/Constant'
   *   '<S16>/Gain2'
   */
  0.765,

  /* Variable: ls
   * Referenced by:
   *   '<S15>/Gain2'
   *   '<S16>/Gain2'
   *   '<S17>/Gain2'
   *   '<S18>/Gain2'
   *   '<S19>/Gain'
   *   '<S20>/Gain'
   *   '<S21>/Gain'
   *   '<S22>/Gain'
   */
  1.242,

  /* Variable: m
   * Referenced by:
   *   '<S13>/Z1'
   *   '<S13>/Z2'
   *   '<S15>/Gain'
   *   '<S16>/Gain'
   *   '<S17>/Gain'
   *   '<S18>/Gain'
   *   '<S19>/Gain1'
   *   '<S20>/Gain1'
   *   '<S21>/Gain1'
   *   '<S22>/Gain1'
   */
  226.0,

  /* Variable: max_moment
   * Referenced by:
   *   '<S10>/Saturation'
   *   '<S10>/Saturation1'
   *   '<S10>/Saturation2'
   *   '<S10>/Saturation3'
   *   '<S11>/Constant1'
   */
  9.8,

  /* Variable: rw
   * Referenced by:
   *   '<S8>/Gain1'
   *   '<S13>/Ta'
   *   '<S13>/Tr'
   *   '<S19>/Gain'
   *   '<S20>/Gain'
   *   '<S21>/Gain'
   *   '<S22>/Gain'
   */
  0.217,

  /* Expression: -1
   * Referenced by: '<S7>/Gain'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S4>/Switch'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S2>/acc_pedal'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S11>/Constant'
   */
  0.0,

  /* Expression: 1/4
   * Referenced by: '<S9>/Gain'
   */
  0.25,

  /* Expression: inf
   * Referenced by: '<S9>/Saturation'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S9>/Saturation'
   */
  0.0,

  /* Expression: 200
   * Referenced by: '<S2>/whl_speed_fl'
   */
  200.0,

  /* Expression: 200
   * Referenced by: '<S2>/whl_speed_fr'
   */
  200.0,

  /* Expression: 200
   * Referenced by: '<S2>/whl_speed_rl'
   */
  200.0,

  /* Expression: 200
   * Referenced by: '<S2>/whl_speed_rr'
   */
  200.0,

  /* Expression: 1/4
   * Referenced by: '<S8>/Gain'
   */
  0.25,

  /* Expression: 1
   * Referenced by: '<S10>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S7>/Constant'
   */
  0.0,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<S7>/Transfer Fcn'
   */
  -4.0,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<S7>/Transfer Fcn'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S7>/Switch'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S10>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/ax'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/ay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/yaw_rate'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S2>/delta'
   */
  2.0,

  /* Expression: 1
   * Referenced by: '<S6>/Constant'
   */
  1.0,

  /* Expression: inf
   * Referenced by: '<S6>/Saturation1'
   */
  0.0,

  /* Expression: 0.3
   * Referenced by: '<S6>/Saturation1'
   */
  0.3,

  /* Expression: 6
   * Referenced by: '<S6>/Saturation'
   */
  6.0,

  /* Expression: -6
   * Referenced by: '<S6>/Saturation'
   */
  -6.0,

  /* Expression: 0
   * Referenced by: '<S12>/Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S7>/Switch1'
   */
  0.0,

  /* Expression: 3
   * Referenced by: '<S3>/speed_switch'
   */
  3.0,

  /* Expression: 550
   * Referenced by: '<S3>/batt_curr'
   */
  550.0,

  /* Expression: 1/100
   * Referenced by: '<S5>/current_change'
   */
  0.01,

  /* Expression: 10
   * Referenced by: '<S3>/power_limiter_switch'
   */
  10.0,

  /* Expression: 1
   * Referenced by: '<Root>/trq_fl'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/trq_fr'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/trq_rl'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/trq_rr'
   */
  1.0,

  /* Expression: 1.3
   * Referenced by: '<S13>/X1'
   */
  1.3,

  /* Expression: 1.3
   * Referenced by: '<S13>/X2'
   */
  1.3,

  /* Expression: 15
   * Referenced by: '<S14>/I_max'
   */
  15.0,

  /* Expression: 550
   * Referenced by: '<S14>/Vdc'
   */
  550.0,

  /* Expression: 0.95
   * Referenced by: '<S14>/Gain'
   */
  0.95,

  /* Expression: 1
   * Referenced by: '<S14>/car_trq_fl'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S14>/car_trq_fr'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S14>/car_trq_rl'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S14>/car_trq_rr'
   */
  1.0,

  /* Expression: 20
   * Referenced by: '<S7>/tt_max'
   */
  20.0,

  /* Expression: -1
   * Referenced by: '<S7>/Gain1'
   */
  -1.0,

  /* Computed Parameter: regenerative_braking_switch_Cur
   * Referenced by: '<S7>/regenerative_braking_switch'
   */
  1U,

  /* Computed Parameter: active_balance_switch_CurrentSe
   * Referenced by: '<S12>/active_balance_switch'
   */
  1U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
