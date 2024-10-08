/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: tv_data.c
 *
 * Code generated for Simulink model 'tv'.
 *
 * Model version                  : 1.43
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sun Jul 21 12:27:19 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "tv.h"

/* Block parameters (default storage) */
P_tv_T tv_P = {
  /* Variable: L
   * Referenced by:
   *   '<S5>/axlebase'
   *   '<S10>/Gain'
   *   '<S11>/Gain'
   *   '<S12>/Gain'
   *   '<S13>/Gain'
   */
  2.6,

  /* Variable: P_max
   * Referenced by: '<S18>/Constant'
   */
  7900.0,

  /* Variable: drive_ratio
   * Referenced by:
   *   '<S7>/Torque_ub'
   *   '<S8>/Constant1'
   */
  14.25,

  /* Variable: g
   * Referenced by:
   *   '<S10>/Constant'
   *   '<S11>/Constant'
   *   '<S12>/Constant'
   *   '<S13>/Constant'
   *   '<S14>/Gain1'
   *   '<S15>/Gain1'
   *   '<S16>/Gain1'
   *   '<S17>/Gain1'
   */
  9.81,

  /* Variable: h
   * Referenced by:
   *   '<S10>/Gain1'
   *   '<S10>/Gain2'
   *   '<S11>/Gain1'
   *   '<S11>/Gain2'
   *   '<S12>/Gain1'
   *   '<S12>/Gain2'
   *   '<S13>/Gain1'
   *   '<S13>/Gain2'
   */
  0.25,

  /* Variable: lf
   * Referenced by:
   *   '<S12>/Constant'
   *   '<S12>/Gain2'
   *   '<S13>/Constant'
   *   '<S13>/Gain2'
   */
  2.1,

  /* Variable: lr
   * Referenced by:
   *   '<S10>/Constant'
   *   '<S10>/Gain2'
   *   '<S11>/Constant'
   *   '<S11>/Gain2'
   */
  0.5,

  /* Variable: ls
   * Referenced by:
   *   '<S10>/Gain2'
   *   '<S11>/Gain2'
   *   '<S12>/Gain2'
   *   '<S13>/Gain2'
   *   '<S14>/Gain'
   *   '<S15>/Gain'
   *   '<S16>/Gain'
   *   '<S17>/Gain'
   */
  1.242,

  /* Variable: m
   * Referenced by:
   *   '<S10>/Gain'
   *   '<S11>/Gain'
   *   '<S12>/Gain'
   *   '<S13>/Gain'
   *   '<S14>/Gain1'
   *   '<S15>/Gain1'
   *   '<S16>/Gain1'
   *   '<S17>/Gain1'
   */
  180.0,

  /* Variable: max_moment
   * Referenced by:
   *   '<S7>/Torque_ub'
   *   '<S8>/Constant1'
   */
  9.8,

  /* Variable: rw
   * Referenced by:
   *   '<S6>/Gain1'
   *   '<S14>/Gain'
   *   '<S15>/Gain'
   *   '<S16>/Gain'
   *   '<S17>/Gain'
   */
  0.217,

  /* Expression: 1
   * Referenced by: '<S2>/WheelSp_FL'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S2>/WheelSp_FR'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S2>/WheelSp_RL'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S2>/WheelSp_RR'
   */
  1.0,

  /* Expression: 1/4
   * Referenced by: '<S6>/Gain'
   */
  0.25,

  /* Expression: 1
   * Referenced by: '<S2>/delta'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S5>/Constant'
   */
  1.0,

  /* Expression: 1/2500
   * Referenced by: '<S5>/Gain1'
   */
  0.0004,

  /* Expression: 1
   * Referenced by: '<S2>/yaw_rate'
   */
  1.0,

  /* Expression: 0.5
   * Referenced by: '<S9>/Gain'
   */
  0.5,

  /* Expression: 0
   * Referenced by: '<S9>/Integrator'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S2>/acc_pedal'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S2>/brake_pedal'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S2>/ax'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S2>/ay'
   */
  1.0,

  /* Expression: 0.97
   * Referenced by: '<S18>/eta1'
   */
  0.97,

  /* Expression: 1
   * Referenced by: '<S4>/Trq_FL'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S4>/Trq_FR'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S4>/Trq_RL'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S4>/Trq_RR'
   */
  1.0,

  /* Expression: 0.05
   * Referenced by: '<S9>/Gain1'
   */
  0.05
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
