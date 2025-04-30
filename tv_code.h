/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: tv_code.h
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
  real_T Product1;                     /* '<S11>/Product1' */
  real_T Saturation[4];                /* '<S9>/Saturation' */
  real_T Gain1;                        /* '<S8>/Gain1' */
  real_T TransferFcn;                  /* '<S7>/Transfer Fcn' */
  real_T Switch;                       /* '<S7>/Switch' */
  real_T tt_switch;                    /* '<S10>/tt_switch' */
  real_T Gain1_o;                      /* '<S19>/Gain1' */
  real_T DotProduct;                   /* '<S12>/Dot Product' */
  real_T Sum1;                         /* '<S12>/Sum1' */
  real_T Switch1;                      /* '<S7>/Switch1' */
  real_T DotProduct_i;                 /* '<S10>/Dot Product' */
  real_T Gain1_m;                      /* '<S20>/Gain1' */
  real_T DotProduct1;                  /* '<S10>/Dot Product1' */
  real_T Gain1_j;                      /* '<S22>/Gain1' */
  real_T DotProduct2;                  /* '<S10>/Dot Product2' */
  real_T Gain1_p;                      /* '<S21>/Gain1' */
  real_T speed_switch[4];              /* '<S3>/speed_switch' */
  real_T est_bat_current;              /* '<S5>/est_bat_current' */
  real_T trq_fl;                       /* '<Root>/trq_fl' */
  real_T trq_fr;                       /* '<Root>/trq_fr' */
  real_T trq_rl;                       /* '<Root>/trq_rl' */
  real_T trq_rr;                       /* '<Root>/trq_rr' */
  real_T DotProduct1_h;                /* '<S12>/Dot Product1' */
  real_T Gain1_e;                      /* '<S7>/Gain1' */
  real_T DotProduct2_m;                /* '<S12>/Dot Product2' */
  real_T DotProduct3;                  /* '<S10>/Dot Product3' */
  real_T Switch_p[4];                  /* '<S4>/Switch' */
  real_T Gain;                         /* '<S4>/Gain' */
  real_T Gain1_a;                      /* '<S4>/Gain1' */
  real_T Gain2;                        /* '<S4>/Gain2' */
  real_T Gain3;                        /* '<S4>/Gain3' */
  real_T regenerative_braking_switch;  /* '<S7>/regenerative_braking_switch' */
  real_T Gain_b;                       /* '<S7>/Gain' */
  real_T Product[4];                   /* '<S5>/Product' */
  real_T DotProduct_n;                 /* '<S14>/Dot Product' */
  real_T Gain_o;                       /* '<S12>/Gain' */
  real_T Divide;                       /* '<S5>/Divide' */
  real_T power_limiter_switch[4];      /* '<S3>/power_limiter_switch' */
  real_T Saturation3;                  /* '<S10>/Saturation3' */
  real_T Divide_g;                     /* '<S14>/Divide' */
  real_T Add;                          /* '<S14>/Add' */
  real_T current_change;               /* '<S5>/current_change' */
  real_T Max;                          /* '<S7>/Max' */
  B_ax_filter_tv_code_T yaw_rate_filter;/* '<S2>/ax_filter' */
  B_ax_filter_tv_code_T ay_filter;     /* '<S2>/ax_filter' */
  B_ax_filter_tv_code_T ax_filter;     /* '<S2>/ax_filter' */
} B_tv_code_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T TimeStampA;                   /* '<S5>/Derivative' */
  real_T LastUAtTimeA;                 /* '<S5>/Derivative' */
  real_T TimeStampB;                   /* '<S5>/Derivative' */
  real_T LastUAtTimeB;                 /* '<S5>/Derivative' */
  DW_ax_filter_tv_code_T yaw_rate_filter;/* '<S2>/ax_filter' */
  DW_ax_filter_tv_code_T ay_filter;    /* '<S2>/ax_filter' */
  DW_ax_filter_tv_code_T ax_filter;    /* '<S2>/ax_filter' */
} DW_tv_code_T;

/* Continuous states (default storage) */
typedef struct {
  real_T TransferFcn_CSTATE;           /* '<S7>/Transfer Fcn' */
  real_T Integrator_CSTATE;            /* '<S12>/Integrator' */
} X_tv_code_T;

/* State derivatives (default storage) */
typedef struct {
  real_T TransferFcn_CSTATE;           /* '<S7>/Transfer Fcn' */
  real_T Integrator_CSTATE;            /* '<S12>/Integrator' */
} XDot_tv_code_T;

/* State disabled  */
typedef struct {
  boolean_T TransferFcn_CSTATE;        /* '<S7>/Transfer Fcn' */
  boolean_T Integrator_CSTATE;         /* '<S12>/Integrator' */
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
                                        * Referenced by: '<S6>/Desired Understeer Gradient'
                                        */
  real_T L;                            /* Variable: L
                                        * Referenced by:
                                        *   '<S6>/axlebase'
                                        *   '<S13>/Z1'
                                        *   '<S13>/Z2'
                                        *   '<S15>/Gain'
                                        *   '<S16>/Gain'
                                        *   '<S17>/Gain'
                                        *   '<S18>/Gain'
                                        */
  real_T Mz_I;                         /* Variable: Mz_I
                                        * Referenced by: '<S2>/Mz Integative Gain'
                                        */
  real_T Mz_p;                         /* Variable: Mz_p
                                        * Referenced by: '<S2>/Mz Proportional Gain'
                                        */
  real_T P_max;                        /* Variable: P_max
                                        * Referenced by:
                                        *   '<S5>/Constant'
                                        *   '<S5>/Switch'
                                        */
  real_T batt_voltage;                 /* Variable: batt_voltage
                                        * Referenced by:
                                        *   '<S5>/Constant'
                                        *   '<S5>/Switch'
                                        */
  real_T bbal;                         /* Variable: bbal
                                        * Referenced by:
                                        *   '<S4>/Gain'
                                        *   '<S4>/Gain1'
                                        *   '<S4>/Gain2'
                                        *   '<S4>/Gain3'
                                        */
  real_T drive_ratio;                  /* Variable: drive_ratio
                                        * Referenced by:
                                        *   '<S10>/Saturation'
                                        *   '<S10>/Saturation1'
                                        *   '<S10>/Saturation2'
                                        *   '<S10>/Saturation3'
                                        *   '<S11>/Constant1'
                                        *   '<S13>/Gain'
                                        *   '<S13>/Gain1'
                                        */
  real_T g;                            /* Variable: g
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
  real_T gain_threshold;               /* Variable: gain_threshold
                                        * Referenced by: '<S12>/Gain'
                                        */
  real_T h;                            /* Variable: h
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
  real_T lf;                           /* Variable: lf
                                        * Referenced by:
                                        *   '<S13>/Z1'
                                        *   '<S17>/Constant'
                                        *   '<S17>/Gain2'
                                        *   '<S18>/Constant'
                                        *   '<S18>/Gain2'
                                        */
  real_T lr;                           /* Variable: lr
                                        * Referenced by:
                                        *   '<S13>/Z2'
                                        *   '<S15>/Constant'
                                        *   '<S15>/Gain2'
                                        *   '<S16>/Constant'
                                        *   '<S16>/Gain2'
                                        */
  real_T ls;                           /* Variable: ls
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
  real_T m;                            /* Variable: m
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
  real_T max_moment;                   /* Variable: max_moment
                                        * Referenced by:
                                        *   '<S10>/Saturation'
                                        *   '<S10>/Saturation1'
                                        *   '<S10>/Saturation2'
                                        *   '<S10>/Saturation3'
                                        *   '<S11>/Constant1'
                                        */
  real_T rw;                           /* Variable: rw
                                        * Referenced by:
                                        *   '<S8>/Gain1'
                                        *   '<S13>/Ta'
                                        *   '<S13>/Tr'
                                        *   '<S19>/Gain'
                                        *   '<S20>/Gain'
                                        *   '<S21>/Gain'
                                        *   '<S22>/Gain'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S7>/Gain'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S4>/Switch'
                                        */
  real_T acc_pedal_Value;              /* Expression: 1
                                        * Referenced by: '<S2>/acc_pedal'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T Gain_Gain_f;                  /* Expression: 1/4
                                        * Referenced by: '<S9>/Gain'
                                        */
  real_T Saturation_UpperSat;          /* Expression: inf
                                        * Referenced by: '<S9>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S9>/Saturation'
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
                                        * Referenced by: '<S8>/Gain'
                                        */
  real_T Constant_Value_j;             /* Expression: 1
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Constant_Value_g;             /* Expression: 0
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T TransferFcn_A;                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S7>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S7>/Transfer Fcn'
                                        */
  real_T Switch_Threshold_d;           /* Expression: 0
                                        * Referenced by: '<S7>/Switch'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S10>/Constant1'
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
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: inf
                                        * Referenced by: '<S6>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0.3
                                        * Referenced by: '<S6>/Saturation1'
                                        */
  real_T Saturation_UpperSat_b;        /* Expression: 6
                                        * Referenced by: '<S6>/Saturation'
                                        */
  real_T Saturation_LowerSat_i;        /* Expression: -6
                                        * Referenced by: '<S6>/Saturation'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S12>/Integrator'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S7>/Switch1'
                                        */
  real_T speed_switch_Threshold;       /* Expression: 3
                                        * Referenced by: '<S3>/speed_switch'
                                        */
  real_T batt_curr_Value;              /* Expression: 550
                                        * Referenced by: '<S3>/batt_curr'
                                        */
  real_T current_change_Gain;          /* Expression: 1/100
                                        * Referenced by: '<S5>/current_change'
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
  real_T X1_Gain;                      /* Expression: 1.3
                                        * Referenced by: '<S13>/X1'
                                        */
  real_T X2_Gain;                      /* Expression: 1.3
                                        * Referenced by: '<S13>/X2'
                                        */
  real_T I_max_Value;                  /* Expression: 15
                                        * Referenced by: '<S14>/I_max'
                                        */
  real_T Vdc_Value;                    /* Expression: 550
                                        * Referenced by: '<S14>/Vdc'
                                        */
  real_T Gain_Gain_mp;                 /* Expression: 0.95
                                        * Referenced by: '<S14>/Gain'
                                        */
  real_T car_trq_fl_Value;             /* Expression: 1
                                        * Referenced by: '<S14>/car_trq_fl'
                                        */
  real_T car_trq_fr_Value;             /* Expression: 1
                                        * Referenced by: '<S14>/car_trq_fr'
                                        */
  real_T car_trq_rl_Value;             /* Expression: 1
                                        * Referenced by: '<S14>/car_trq_rl'
                                        */
  real_T car_trq_rr_Value;             /* Expression: 1
                                        * Referenced by: '<S14>/car_trq_rr'
                                        */
  real_T tt_max_Value;                 /* Expression: 20
                                        * Referenced by: '<S7>/tt_max'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S7>/Gain1'
                                        */
  uint8_T regenerative_braking_switch_Cur;
                          /* Computed Parameter: regenerative_braking_switch_Cur
                           * Referenced by: '<S7>/regenerative_braking_switch'
                           */
  uint8_T active_balance_switch_CurrentSe;
                          /* Computed Parameter: active_balance_switch_CurrentSe
                           * Referenced by: '<S12>/active_balance_switch'
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
  real_T odeY[2];
  real_T odeF[4][2];
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
 * '<S4>'   : 'tv_code/The Best TorqueVectoring/TorqueVectoring1/Brake_balance'
 * '<S5>'   : 'tv_code/The Best TorqueVectoring/TorqueVectoring1/Power limiter for car'
 * '<S6>'   : 'tv_code/The Best TorqueVectoring/TorqueVectoring1/Reference generator'
 * '<S7>'   : 'tv_code/The Best TorqueVectoring/TorqueVectoring1/Regenerative braking'
 * '<S8>'   : 'tv_code/The Best TorqueVectoring/TorqueVectoring1/Speed estimaor'
 * '<S9>'   : 'tv_code/The Best TorqueVectoring/TorqueVectoring1/Toque distibution NO Tv'
 * '<S10>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring1/Torque distribution Tv'
 * '<S11>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring1/Total Torque Request'
 * '<S12>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring1/Upper Controller'
 * '<S13>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring1/Regenerative braking/Subsystem'
 * '<S14>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring1/Regenerative braking/Tmax'
 * '<S15>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring1/Torque distribution Tv/Fzfl'
 * '<S16>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring1/Torque distribution Tv/Fzfr'
 * '<S17>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring1/Torque distribution Tv/Fzrl'
 * '<S18>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring1/Torque distribution Tv/Fzrr'
 * '<S19>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring1/Torque distribution Tv/T_FL'
 * '<S20>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring1/Torque distribution Tv/T_FR'
 * '<S21>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring1/Torque distribution Tv/T_FR1'
 * '<S22>'  : 'tv_code/The Best TorqueVectoring/TorqueVectoring1/Torque distribution Tv/T_RL'
 */
#endif                                 /* RTW_HEADER_tv_code_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
