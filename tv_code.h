/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: tv_code.h
 *
 * Code generated for Simulink model 'tv_code'.
 *
 * Model version                  : 1.30
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Feb 26 15:34:24 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_tv_code_h_
#define RTW_HEADER_tv_code_h_
#ifndef tv_code_COMMON_INCLUDES_
#define tv_code_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* tv_code_COMMON_INCLUDES_ */

#include "tv_code_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals for system '<S2>/ax_filter' */
typedef struct {
  real_T ax_filter;                    /* '<S2>/ax_filter' */
} B_ax_filter_tv_code_T;

/* Block states (default storage) for system '<S2>/ax_filter' */
typedef struct {
  dsp_simulink_LowpassFilter_tv_T obj; /* '<S2>/ax_filter' */
  boolean_T objisempty;                /* '<S2>/ax_filter' */
  boolean_T isInitialized;             /* '<S2>/ax_filter' */
} DW_ax_filter_tv_code_T;

/* Block signals (default storage) */
typedef struct {
  real_T Product1;                     /* '<S10>/Product1' */
  real_T Saturation[4];                /* '<S8>/Saturation' */
  real_T Gain1;                        /* '<S7>/Gain1' */
  real_T Switch;                       /* '<S6>/Switch' */
  real_T tt_switch;                    /* '<S9>/tt_switch' */
  real_T Gain1_o;                      /* '<S18>/Gain1' */
  real_T DotProduct;                   /* '<S11>/Dot Product' */
  real_T Sum1;                         /* '<S11>/Sum1' */
  real_T Gain1_m;                      /* '<S19>/Gain1' */
  real_T Gain1_j;                      /* '<S21>/Gain1' */
  real_T Gain1_p;                      /* '<S20>/Gain1' */
  real_T speed_switch[4];              /* '<S3>/speed_switch' */
  real_T est_batt_current;             /* '<S4>/Sum1' */
  real_T trq_fl;                       /* '<Root>/trq_fl' */
  real_T trq_fr;                       /* '<Root>/trq_fr' */
  real_T trq_rl;                       /* '<Root>/trq_rl' */
  real_T trq_rr;                       /* '<Root>/trq_rr' */
  real_T DotProduct1;                  /* '<S11>/Dot Product1' */
  real_T DotProduct_i;                 /* '<S9>/Dot Product' */
  real_T DotProduct1_f;                /* '<S9>/Dot Product1' */
  real_T DotProduct2;                  /* '<S9>/Dot Product2' */
  real_T DotProduct3;                  /* '<S9>/Dot Product3' */
  real_T Gain;                         /* '<S6>/Gain' */
  real_T regenerative_braking_switch;  /* '<S6>/regenerative_braking_switch' */
  real_T Gain1_e;                      /* '<S6>/Gain1' */
  real_T Product[4];                   /* '<S4>/Product' */
  real_T DotProduct_n;                 /* '<S13>/Dot Product' */
  real_T Divide;                       /* '<S4>/Divide' */
  real_T power_limiter_switch[4];      /* '<S3>/power_limiter_switch' */
  real_T Divide_g;                     /* '<S13>/Divide' */
  real_T Gain11;                       /* '<S4>/Gain11' */
  real_T Gain1_a;                      /* '<S12>/Gain1' */
  real_T Sum;                          /* '<S11>/Sum' */
  real_T Saturation3;                  /* '<S9>/Saturation3' */
  real_T MaxofElements;                /* '<S6>/Max of Elements' */
  real_T Gain_d;                       /* '<S17>/Gain' */
  real_T Saturation2;                  /* '<S9>/Saturation2' */
  real_T Gain2;                        /* '<S17>/Gain2' */
  B_ax_filter_tv_code_T yaw_rate_filter;/* '<S2>/ax_filter' */
  B_ax_filter_tv_code_T ay_filter;     /* '<S2>/ax_filter' */
  B_ax_filter_tv_code_T ax_filter;     /* '<S2>/ax_filter' */
} B_tv_code_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T TimeStampA;                   /* '<S4>/Derivative' */
  real_T LastUAtTimeA;                 /* '<S4>/Derivative' */
  real_T TimeStampB;                   /* '<S4>/Derivative' */
  real_T LastUAtTimeB;                 /* '<S4>/Derivative' */
  DW_ax_filter_tv_code_T yaw_rate_filter;/* '<S2>/ax_filter' */
  DW_ax_filter_tv_code_T ay_filter;    /* '<S2>/ax_filter' */
  DW_ax_filter_tv_code_T ax_filter;    /* '<S2>/ax_filter' */
} DW_tv_code_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S11>/Integrator' */
} X_tv_code_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S11>/Integrator' */
} XDot_tv_code_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S11>/Integrator' */
} XDis_tv_code_T;

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
} ODE4_IntgData;

#endif

/* Parameters (default storage) */
struct P_tv_code_T_ {
  real_T Ku;                           /* Variable: Ku
                                        * Referenced by: '<S5>/Desired Understeer Gradient'
                                        */
  real_T L;                            /* Variable: L
                                        * Referenced by:
                                        *   '<S5>/axlebase'
                                        *   '<S12>/Z1'
                                        *   '<S12>/Z2'
                                        *   '<S14>/Gain'
                                        *   '<S15>/Gain'
                                        *   '<S16>/Gain'
                                        *   '<S17>/Gain'
                                        */
  real_T Mz_I;                         /* Variable: Mz_I
                                        * Referenced by: '<S2>/Mz Integative Gain'
                                        */
  real_T Mz_p;                         /* Variable: Mz_p
                                        * Referenced by: '<S2>/Mz Proportional Gain'
                                        */
  real_T P_max;                        /* Variable: P_max
                                        * Referenced by:
                                        *   '<S4>/Constant'
                                        *   '<S4>/Switch'
                                        */
  real_T batt_voltage;                 /* Variable: batt_voltage
                                        * Referenced by:
                                        *   '<S4>/Constant'
                                        *   '<S4>/Switch'
                                        */
  real_T drive_ratio;                  /* Variable: drive_ratio
                                        * Referenced by:
                                        *   '<S9>/Saturation'
                                        *   '<S9>/Saturation1'
                                        *   '<S9>/Saturation2'
                                        *   '<S9>/Saturation3'
                                        *   '<S10>/Constant1'
                                        *   '<S12>/Gain'
                                        *   '<S12>/Gain1'
                                        */
  real_T g;                            /* Variable: g
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
  real_T h;                            /* Variable: h
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
  real_T lf;                           /* Variable: lf
                                        * Referenced by:
                                        *   '<S12>/Z1'
                                        *   '<S16>/Constant'
                                        *   '<S16>/Gain2'
                                        *   '<S17>/Constant'
                                        *   '<S17>/Gain2'
                                        */
  real_T lr;                           /* Variable: lr
                                        * Referenced by:
                                        *   '<S12>/Z2'
                                        *   '<S14>/Constant'
                                        *   '<S14>/Gain2'
                                        *   '<S15>/Constant'
                                        *   '<S15>/Gain2'
                                        */
  real_T ls;                           /* Variable: ls
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
  real_T m;                            /* Variable: m
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
  real_T max_moment;                   /* Variable: max_moment
                                        * Referenced by:
                                        *   '<S9>/Saturation'
                                        *   '<S9>/Saturation1'
                                        *   '<S9>/Saturation2'
                                        *   '<S9>/Saturation3'
                                        *   '<S10>/Constant1'
                                        */
  real_T rw;                           /* Variable: rw
                                        * Referenced by:
                                        *   '<S7>/Gain1'
                                        *   '<S12>/Ta'
                                        *   '<S12>/Tr'
                                        *   '<S18>/Gain'
                                        *   '<S19>/Gain'
                                        *   '<S20>/Gain'
                                        *   '<S21>/Gain'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T car_trq_rr_Value;             /* Expression: 1
                                        * Referenced by: '<S13>/car_trq_rr'
                                        */
  real_T car_trq_rl_Value;             /* Expression: 1
                                        * Referenced by: '<S13>/car_trq_rl'
                                        */
  real_T car_trq_fr_Value;             /* Expression: 1
                                        * Referenced by: '<S13>/car_trq_fr'
                                        */
  real_T car_trq_fl_Value;             /* Expression: 1
                                        * Referenced by: '<S13>/car_trq_fl'
                                        */
  real_T Vdc_Value;                    /* Expression: 550
                                        * Referenced by: '<S13>/Vdc'
                                        */
  real_T I_max_Value;                  /* Expression: 15
                                        * Referenced by: '<S13>/I_max'
                                        */
  real_T Gain_Gain;                    /* Expression: 0.95
                                        * Referenced by: '<S13>/Gain'
                                        */
  real_T X2_Gain;                      /* Expression: 1.3
                                        * Referenced by: '<S12>/X2'
                                        */
  real_T X1_Gain;                      /* Expression: 1.3
                                        * Referenced by: '<S12>/X1'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S6>/Gain1'
                                        */
  real_T Gain_Gain_l;                  /* Expression: -1
                                        * Referenced by: '<S6>/Gain'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S6>/Switch1'
                                        */
  real_T Constant_Value_j;             /* Expression: 1
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S9>/Constant1'
                                        */
  real_T acc_pedal_Value;              /* Expression: 1
                                        * Referenced by: '<S2>/acc_pedal'
                                        */
  real_T Constant_Value_c;             /* Expression: 0
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Gain_Gain_f;                  /* Expression: 1/4
                                        * Referenced by: '<S8>/Gain'
                                        */
  real_T Saturation_UpperSat;          /* Expression: inf
                                        * Referenced by: '<S8>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S8>/Saturation'
                                        */
  real_T whl_speed_fl_Value;           /* Expression: 200
                                        * Referenced by: '<S2>/whl_speed_fl'
                                        */
  real_T whl_speed_fr_Value;           /* Expression: 200
                                        * Referenced by: '<S2>/whl_speed_fr'
                                        */
  real_T whl_speed_rl_Value;           /* Expression: 200
                                        * Referenced by: '<S2>/whl_speed_rl'
                                        */
  real_T whl_speed_rr_Value;           /* Expression: 200
                                        * Referenced by: '<S2>/whl_speed_rr'
                                        */
  real_T Gain_Gain_m;                  /* Expression: 1/4
                                        * Referenced by: '<S7>/Gain'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S6>/Switch'
                                        */
  real_T ax_Value;                     /* Expression: 0
                                        * Referenced by: '<S2>/ax'
                                        */
  real_T ay_Value;                     /* Expression: 0
                                        * Referenced by: '<S2>/ay'
                                        */
  real_T yaw_rate_Value;               /* Expression: 0
                                        * Referenced by: '<S2>/yaw_rate'
                                        */
  real_T delta_Value;                  /* Expression: 2
                                        * Referenced by: '<S2>/delta'
                                        */
  real_T Constant_Value_o;             /* Expression: 1
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: inf
                                        * Referenced by: '<S5>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0.3
                                        * Referenced by: '<S5>/Saturation1'
                                        */
  real_T Saturation_UpperSat_b;        /* Expression: 6
                                        * Referenced by: '<S5>/Saturation'
                                        */
  real_T Saturation_LowerSat_i;        /* Expression: -6
                                        * Referenced by: '<S5>/Saturation'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S11>/Integrator'
                                        */
  real_T speed_switch_Threshold;       /* Expression: 3
                                        * Referenced by: '<S3>/speed_switch'
                                        */
  real_T batt_curr_Value;              /* Expression: 550
                                        * Referenced by: '<S3>/batt_curr'
                                        */
  real_T Gain11_Gain;                  /* Expression: 1/100
                                        * Referenced by: '<S4>/Gain11'
                                        */
  real_T power_limiter_switch_Threshold;/* Expression: 10
                                         * Referenced by: '<S3>/power_limiter_switch'
                                         */
  real_T trq_fl_Gain;                  /* Expression: 1
                                        * Referenced by: '<Root>/trq_fl'
                                        */
  real_T trq_fr_Gain;                  /* Expression: 1
                                        * Referenced by: '<Root>/trq_fr'
                                        */
  real_T trq_rl_Gain;                  /* Expression: 1
                                        * Referenced by: '<Root>/trq_rl'
                                        */
  real_T trq_rr_Gain;                  /* Expression: 1
                                        * Referenced by: '<Root>/trq_rr'
                                        */
  uint8_T regenerative_braking_switch_Cur;
                          /* Computed Parameter: regenerative_braking_switch_Cur
                           * Referenced by: '<S6>/regenerative_braking_switch'
                           */
};

/* Real-time Model Data Structure */
struct tag_RTM_tv_code_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_tv_code_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_tv_code_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[1];
  real_T odeF[4][1];
  ODE4_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_tv_code_T tv_code_P;

/* Block signals (default storage) */
extern B_tv_code_T tv_code_B;

/* Continuous states (default storage) */
extern X_tv_code_T tv_code_X;

/* Block states (default storage) */
extern DW_tv_code_T tv_code_DW;

/* Model entry point functions */
extern void tv_code_initialize(void);
extern void tv_code_step(void);
extern void tv_code_terminate(void);

/* Real-time Model object */
extern RT_MODEL_tv_code_T *const tv_code_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'tv_code'
 * '<S1>'   : 'tv_code/The Best TorqueVectoring'
 * '<S2>'   : 'tv_code/The Best TorqueVectoring/CarMaker_Inputs'
 * '<S3>'   : 'tv_code/The Best TorqueVectoring/TorqueVectoring1'
 * '<S4>'   : 'tv_code/The Best TorqueVectoring/TorqueVectoring1/Power limiter for car'
 * '<S5>'   : 'tv_code/The Best TorqueVectoring/TorqueVectoring1/Reference generator'
 * '<S6>'   : 'tv_code/The Best TorqueVectoring/TorqueVectoring1/Regenerative braking'
 * '<S7>'   : 'tv_code/The Best TorqueVectoring/TorqueVectoring1/Speed estimaor'
 * '<S8>'   : 'tv_code/The Best TorqueVectoring/TorqueVectoring1/Toque distibution NO Tv'
 * '<S9>'   : 'tv_code/The Best TorqueVectoring/TorqueVectoring1/Torque distribution Tv'
 * '<S10>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring1/Total Torque Request'
 * '<S11>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring1/Upper Controller'
 * '<S12>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring1/Regenerative braking/Subsystem'
 * '<S13>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring1/Regenerative braking/Tmax'
 * '<S14>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring1/Torque distribution Tv/Fzfl'
 * '<S15>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring1/Torque distribution Tv/Fzfr'
 * '<S16>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring1/Torque distribution Tv/Fzrl'
 * '<S17>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring1/Torque distribution Tv/Fzrr'
 * '<S18>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring1/Torque distribution Tv/T_FL'
 * '<S19>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring1/Torque distribution Tv/T_FR'
 * '<S20>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring1/Torque distribution Tv/T_FR1'
 * '<S21>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring1/Torque distribution Tv/T_RL'
 */
#endif                                 /* RTW_HEADER_tv_code_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
