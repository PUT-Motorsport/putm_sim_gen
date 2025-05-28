/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: tv_code_data.c
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

/* Block parameters (default storage) */
P_tv_code_T tv_code_P = {
  /* Variable: Ku
   * Referenced by: '<S5>/Desired Understeer Gradient'
   */
  -0.0005,

  /* Variable: L
   * Referenced by:
   *   '<S5>/axlebase'
   *   '<S12>/Z1'
   *   '<S12>/Z2'
   *   '<S14>/Gain'
   *   '<S15>/Gain'
   *   '<S16>/Gain'
   *   '<S17>/Gain'
   */
  1.53,

  /* Variable: Mz_I
   * Referenced by: '<S2>/Mz Integative Gain'
   */
  1.0,

  /* Variable: Mz_p
   * Referenced by: '<S2>/Mz Proportional Gain'
   */
  500.0,

  /* Variable: P_max
   * Referenced by:
   *   '<S4>/Constant'
   *   '<S4>/Switch'
   */
  80000.0,

  /* Variable: batt_voltage
   * Referenced by:
   *   '<S4>/Constant'
   *   '<S4>/Switch'
   */
  587.0,

  /* Variable: drive_ratio
   * Referenced by:
   *   '<S9>/Saturation'
   *   '<S9>/Saturation1'
   *   '<S9>/Saturation2'
   *   '<S9>/Saturation3'
   *   '<S10>/Constant1'
   *   '<S12>/Gain'
   *   '<S12>/Gain1'
   */
  14.25,

  /* Variable: g
   * Referenced by:
   *   '<S12>/Z1'
   *   '<S12>/Z2'
   *   '<S14>/Constant'
   *   '<S15>/Constant'
   *   '<S16>/Constant'
   *   '<S17>/Constant'
   *   '<S18>/Gain1'
   *   '<S19>/Gain1'
   *   '<S20>/Gain1'
   *   '<S21>/Gain1'
   */
  9.81,

  /* Variable: h
   * Referenced by:
   *   '<S14>/Gain1'
   *   '<S14>/Gain2'
   *   '<S15>/Gain1'
   *   '<S15>/Gain2'
   *   '<S16>/Gain1'
   *   '<S16>/Gain2'
   *   '<S17>/Gain1'
   *   '<S17>/Gain2'
   */
  0.3,

  /* Variable: lf
   * Referenced by:
   *   '<S12>/Z1'
   *   '<S16>/Constant'
   *   '<S16>/Gain2'
   *   '<S17>/Constant'
   *   '<S17>/Gain2'
   */
  0.765,

  /* Variable: lr
   * Referenced by:
   *   '<S12>/Z2'
   *   '<S14>/Constant'
   *   '<S14>/Gain2'
   *   '<S15>/Constant'
   *   '<S15>/Gain2'
   */
  0.765,

  /* Variable: ls
   * Referenced by:
   *   '<S14>/Gain2'
   *   '<S15>/Gain2'
   *   '<S16>/Gain2'
   *   '<S17>/Gain2'
   *   '<S18>/Gain'
   *   '<S19>/Gain'
   *   '<S20>/Gain'
   *   '<S21>/Gain'
   */
  1.242,

  /* Variable: m
   * Referenced by:
   *   '<S12>/Z1'
   *   '<S12>/Z2'
   *   '<S14>/Gain'
   *   '<S15>/Gain'
   *   '<S16>/Gain'
   *   '<S17>/Gain'
   *   '<S18>/Gain1'
   *   '<S19>/Gain1'
   *   '<S20>/Gain1'
   *   '<S21>/Gain1'
   */
  307.0,

  /* Variable: max_moment
   * Referenced by:
   *   '<S9>/Saturation'
   *   '<S9>/Saturation1'
   *   '<S9>/Saturation2'
   *   '<S9>/Saturation3'
   *   '<S10>/Constant1'
   */
  9.8,

  /* Variable: rw
   * Referenced by:
   *   '<S7>/Gain1'
   *   '<S12>/Ta'
   *   '<S12>/Tr'
   *   '<S18>/Gain'
   *   '<S19>/Gain'
   *   '<S20>/Gain'
   *   '<S21>/Gain'
   */
  0.217,

  /* Expression: -1
   * Referenced by: '<S6>/Gain'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S6>/Switch1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Switch'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S2>/acc_pedal'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S10>/Constant'
   */
  0.0,

  /* Expression: 1/4
   * Referenced by: '<S8>/Gain'
   */
  0.25,

  /* Expression: inf
   * Referenced by: '<S8>/Saturation'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/Saturation'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/whl_speed_fl'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/whl_speed_fr'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/whl_speed_rl'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/whl_speed_rr'
   */
  0.0,

  /* Expression: 1/4
   * Referenced by: '<S7>/Gain'
   */
  0.25,

  /* Expression: 1
   * Referenced by: '<S9>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S6>/Constant'
   */
  0.0,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<S6>/Transfer Fcn'
   */
  -1.0,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<S6>/Transfer Fcn'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S9>/Constant1'
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

  /* Expression: 0
   * Referenced by: '<S2>/delta'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S5>/Constant'
   */
  1.0,

  /* Expression: inf
   * Referenced by: '<S5>/Saturation1'
   */
  0.0,

  /* Expression: 0.3
   * Referenced by: '<S5>/Saturation1'
   */
  0.3,

  /* Expression: 6
   * Referenced by: '<S5>/Saturation'
   */
  6.0,

  /* Expression: -6
   * Referenced by: '<S5>/Saturation'
   */
  -6.0,

  /* Expression: 0
   * Referenced by: '<S11>/Integrator'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S3>/speed_switch'
   */
  2.0,

  /* Expression: 1
   * Referenced by: '<S3>/batt_curr'
   */
  1.0,

  /* Expression: 1/100
   * Referenced by: '<S4>/current_change'
   */
  0.01,

  /* Expression: 10
   * Referenced by: '<S3>/power_speed_limiter_switch'
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

  /* Expression: 15
   * Referenced by: '<S13>/I_max'
   */
  15.0,

  /* Expression: 550
   * Referenced by: '<S13>/Vdc'
   */
  550.0,

  /* Expression: 0.95
   * Referenced by: '<S13>/Gain'
   */
  0.95,

  /* Expression: 1.3
   * Referenced by: '<S12>/X1'
   */
  1.3,

  /* Expression: 1.3
   * Referenced by: '<S12>/X2'
   */
  1.3,

  /* Expression: 50
   * Referenced by: '<S6>/TT_max'
   */
  50.0,

  /* Expression: -1
   * Referenced by: '<S6>/Gain1'
   */
  -1.0,

  /* Computed Parameter: regen_switch_CurrentSetting
   * Referenced by: '<S6>/regen_switch'
   */
  0U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
